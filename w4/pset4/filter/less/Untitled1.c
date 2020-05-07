#include <stdio.h>
#include "bmp.h"
#include <cs50.h>
#include <math.h>

int main(void)
{
    int height = 3;
    int width = 3;
    RGBTRIPLE image[height][width];

for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = get_int("Blue: ");
            image[i][j].rgbtGreen = get_int("Green: ");
            image[i][j].rgbtRed = get_int("Red: ");
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avR = image[i][j].rgbtRed;
            int avG = image[i][j].rgbtGreen;
            int avB = image[i][j].rgbtBlue;

            int count = 1;
            bool jm1 = false;
            bool jp1 = false;
            bool im1 = false;
            bool ip1 = false;

            if (j - 1 >= 0)
            {
                jm1 = true;
                avR += image[i][j - 1].rgbtRed;
                avG += image[i][j - 1].rgbtGreen;
                avB += image[i][j - 1].rgbtBlue;
                count++;
            }

            if (j + 1 < width)
            {
                jp1 = true;
                avR += image[i][j + 1].rgbtRed;
                avG += image[i][j + 1].rgbtGreen;
                avB += image[i][j + 1].rgbtBlue;
                count++;
            }
            if (i - 1 >= 0)
            {
                im1 = true;
                avR += image[i - 1][j].rgbtRed;
                avG += image[i - 1][j].rgbtGreen;
                avB += image[i - 1][j].rgbtBlue;
                count++;
            }
            if (i + 1 < height)
            {
                ip1 = true;
                avR += image[i + 1][j].rgbtRed;
                avG += image[i + 1][j].rgbtGreen;
                avB += image[i + 1][j].rgbtBlue;
                count++;
            }

            if (im1 && jm1)
            {
                avR += image[i - 1][j - 1].rgbtRed;
                avG += image[i - 1][j - 1].rgbtGreen;
                avB += image[i - 1][j - 1].rgbtBlue;
                count++;
            }

            if (im1 && jp1)
            {
                avR += image[i - 1][j + 1].rgbtRed;
                avG += image[i - 1][j + 1].rgbtGreen;
                avB += image[i - 1][j + 1].rgbtBlue;
                count++;
            }

            if (ip1 && jm1)
            {
                avR += image[i + 1][j - 1].rgbtRed;
                avG += image[i + 1][j - 1].rgbtGreen;
                avB += image[i + 1][j - 1].rgbtBlue;
                count++;
            }

            if (ip1 && jp1)
            {
                avR += image[i + 1][j + 1].rgbtRed;
                avG += image[i + 1][j + 1].rgbtGreen;
                avB += image[i + 1][j + 1].rgbtBlue;
                count++;
            }

            image[i][j].rgbtRed = round(avR / count);
            image[i][j].rgbtGreen = round(avG / count);
            image[i][j].rgbtBlue = round(avB / count);


        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("( %i, ", image[i][j].rgbtRed);
            printf("%i, ", image[i][j].rgbtGreen);
            printf("%i )", image[i][j].rgbtBlue);
        }
        printf("\n");
    }

}