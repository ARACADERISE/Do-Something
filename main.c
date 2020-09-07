#include <stdio.h>
#include "src/errors.h"
#include "src/quick_use.h"

struct Color
{
    double r, g, b; /* red, green, blue values between 0 and 1 */
};

void writeBMP(struct Color **image, int height, int width, const char* filename)
{
    unsigned int header[14];
    int i, j;
    FILE* fp = fopen(filename, "wb");
    unsigned char pad[3] = {0, 0, 0};

    header[0] = 0x4d420000;
    header[1] = 54 + 3 * height * width;
    header[2] = 0;
    header[3] = 54;
    header[4] = 40;
    header[5] = width;
    header[6] = height;
    header[7] = 0x00180001;
    header[8] = 0;
    header[9] = 3 * width * height;
    header[10] = header[11] = header[12] = header[13] = 0;

    fwrite((char*)header + 2, 1, 54, fp);
    fflush(fp);

    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            unsigned char R = 255 * image[i][j].r;
            unsigned char G = 255 * image[i][j].g;
            unsigned char B = 255 * image[i][j].b;
            fwrite(&B, 1, 1, fp);
            fwrite(&G, 1, 1, fp);
            fwrite(&R, 1, 1, fp);
        }
        fwrite(pad, width % 4, 1, fp);
    }

    fclose(fp);
}

int main(int args, char* args_[]) {

    if(args < 2) {
        struct Color** col = calloc(4,sizeof(*col));
        col[0][0].r = 0;
        col[0][1].g = 1;
        col[0][2].b = 0;
        col[1][0].r = 0;
        col[1][1].g = 1;
        col[1][2].b = 0;
        col[2][0].r = 0;
        col[2][1].g = 1;
        col[2][2].b = 0;
        writeBMP(col, 820, 640, "file.bmp");
    }

    return 0;
}