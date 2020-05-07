#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <cs50.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    char *error_prompt = "Usage: ./recover *filename*";
    // Check if there are less or more than 2 arguments
    if (argc != 2)
    {
        printf("%s\n", error_prompt);
        return 1;
    }

    BYTE buff[512];
    // Opening the file input as a commandline argument
    FILE *file = fopen(argv[1], "r");
    FILE *jpeg = fopen("foo", "W");
    // Check whether the file can be opened or not
    if (ferror(file))
    {
        printf("%s\n", "cuz");
        return 1;
    }

    int i = -001;
    bool check = false;
    bool eof = false;

    while (!feof(file))
    {
        fread(buff, 1, 512, file);
        if (buff[0] == 0xff && buff[1] == 0xd8 && buff[2] == 0xff && (buff[3] & 0xf0) == 0xe0)
        {
            i++;
            check = true;
            char filename[8];
            sprintf(filename, "%03i.jpg", i);
            jpeg = fopen(filename, "w");
            fwrite(buff, 1, 512, jpeg);
        }
        else if (check && !feof(file))
        {
            fwrite(buff, 1, 512, jpeg);
        }
    }

    fclose(jpeg);
    fclose(file);
    return 0;
}

