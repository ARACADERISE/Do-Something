// Brief overview of how Bite variabe declaration will be like
// with set, you need to have a value!

set variable_name: Int = 10; // standard variable declaration in Bite. This is the same as declaration a pointer in C, only in Bite that is standardly what you're going to work with(pointers).
// I want to make it to where we can have a 'strict' keyword though that will change that

// The 'strict' keyword means the variable cannot get any memory allocations to it
// another words, that variable is to have default memory-allocations/default memory releases happening to it
// example
strict set variable_name: Int = 10;

// or
set strict variable_name: Int = 20;

// By default, a variable declaration will always be applicable to memory management
// So, a strict variable declaration in Bite is the same as doing:
// int a = 10; in C!
// But, doing:
// set VariableName: Int = 10; is the same as writing:
// int* a = 20; in C!
// Now, by default, either way you do it there is going to be default memory allocations going on.
// But, in the near future, if you write a file such as the following:
/*
use {
  'b_io',
  'b_mem'
} as b;

set my_var: Int = b:malloc(b:sizeof(Int));

b:WriteLine(my_var);
*/

// FUTURE FUTURE LOOK AT Bite
// In this mini-project, we are going to create a string, copy it to something else, write a function that then prints it!
/*
// Simple useless application
use {
  'b_io',
  'b_mem',
  'b_str',
  'b_err'
} as b;

DEFINE MAX_STRING_LEN 20
// declare is a keyword just declaring a variable name for later reference
declare users_name: String = b:calloc(MAX_STRING_LEN,b:size(String)) // same concept as set, if it is strict it has auto memory-allocations
strict declare final_name: String;

// A 'strict' function means no allocations can go on within it
strict Func get_name(username: String): void {

  // checking if the length of username is above MAX_STRING_LEN
  if(b:len_of(username) > MAX_STRING_LEN) then { // yes, I want the langauge to support the 'then' keyword
    b:raise_error(b:io_err,"\nYour username is too long!\n\n"); // b:io_err gives a indication to b:raise_error that there is an error with the I/O
  }
  users_name = username;
  final_name := users_name; // if you are assigning another variable to another variables value, use :=
  // If you don't use :=, you will get an error saying you're attempting to assign a variable to a variable, meanwhile := indicates we want to derive the variables value

  // final_name := users_name is one way of doing it, but a better way to do it is as follows:
  // b:copy_string(users_name).to(final_name); // this makes sure the users_name variable value is derived and is strictly allocated, AND assigned to final_name

  // b:deallocate is just releasing all allocated memory. b:nullify is setting the variable to null to indicate it has no memory allocated to it
  b:deallocate(users_name,b:size(users_name));
  b:nullify(users_name);
} // 'strict Func' declares a function that will contain no memory allocations
// 'get_name' is the function name, '(username: String)' are the arguments going into the function. The argument name is first, followed by ':', then the argument type
// 'void' indicates we are returning nothing in the funciton

*/