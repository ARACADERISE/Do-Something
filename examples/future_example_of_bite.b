use {
  'b_stdio',
  'b_str',
  'b_mem',
  'b_err'
} as b;

DEFINE MAX_STRING_LEN 20
declare users_username: String = b:calloc(MAX_STRING_LEN,b:size(String));

strict declare users_final_username: String;

strict Func gather_username(username: String) Void {
  if(b:len_of(username) > MAX_STRING_LEN) then {
    b:raise_error(b:io_err, "\nUsername too lang\n\n");
  }

  users_username = username;
  b:copy_string(users_username).to(users_final_username);

  // Freeing users_username since users_username was just memory storage for strictly assigning the value of 'username' to 'users_final_username'
  b:deallocate(users_username,b:size(users_username));
  b:nullify(users_username);
};

gather_username(b:get_input("Username:"));

b:WriteLine(users_final_username);

// Making sure the runtime releases default memory allocations from users_final_username
b:destroy(users_final_username);