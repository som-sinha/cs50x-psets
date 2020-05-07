#include "helpers.h"
#include <cs50.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Some comment
    for (int i = 0; i < height; i++)
    {
        // Another comments
        for (int j = 0; j < width; j++)
        {
            int average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Guess what, another comment!
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue));
            int sepiaGreen = round((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue));
            int sepiaBlue = round((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue));

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }
    // Comment comment comment la la la comment comment comment


    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i  = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            int pixel2_loc = width - (j + 1);
            // Wait a minute..... COMMENT!
            RGBTRIPLE temp;
            temp = image[i][j];

            image[i][j] = image[i][pixel2_loc];

            image[i][pixel2_loc] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // What Com ment to say was Comment!
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avR = temp[i][j].rgbtRed;
            int avG = temp[i][j].rgbtGreen;
            int avB = temp[i][j].rgbtBlue;

            int count = 1;

            bool jm1 = false;
            bool jp1 = false;
            bool im1 = false;
            bool ip1 = false;

            if (j - 1 >= 0)
            {
                jm1 = true;
                avR += temp[i][j - 1].rgbtRed;
                avG += temp[i][j - 1].rgbtGreen;
                avB += temp[i][j - 1].rgbtBlue;
                count++;
            }
            // A comment a day keeps bugs away but this is like a one time thing
            // I'm kinda done with this
            if (j + 1 < width)
            {
                jp1 = true;
                avR += temp[i][j + 1].rgbtRed;
                avG += temp[i][j + 1].rgbtGreen;
                avB += temp[i][j + 1].rgbtBlue;
                count++;
            }
            if (i - 1 >= 0)
            {
                im1 = true;
                avR += temp[i - 1][j].rgbtRed;
                avG += temp[i - 1][j].rgbtGreen;
                avB += temp[i - 1][j].rgbtBlue;
                count++;
            }
            if (i + 1 < height)
            {
                ip1 = true;
                avR += temp[i + 1][j].rgbtRed;
                avG += temp[i + 1][j].rgbtGreen;
                avB += temp[i + 1][j].rgbtBlue;
                count++;
            }

            if (im1 && jm1)
            {
                avR += temp[i - 1][j - 1].rgbtRed;
                avG += temp[i - 1][j - 1].rgbtGreen;
                avB += temp[i - 1][j - 1].rgbtBlue;
                count++;
            }

            if (im1 && jp1)
            {
                avR += temp[i - 1][j + 1].rgbtRed;
                avG += temp[i - 1][j + 1].rgbtGreen;
                avB += temp[i - 1][j + 1].rgbtBlue;
                count++;

            }
            // COMMMMMMMEEEEEEEENT
            if (ip1 && jm1)
            {
                avR += temp[i + 1][j - 1].rgbtRed;
                avG += temp[i + 1][j - 1].rgbtGreen;
                avB += temp[i + 1][j - 1].rgbtBlue;
                count++;
            }
            // COMMMMMMMEEEEEEEENT
            // COMMMMMMMEEEEEEEENT

            if (ip1 && jp1)
            {
                avR += temp[i + 1][j + 1].rgbtRed;
                avG += temp[i + 1][j + 1].rgbtGreen;
                avB += temp[i + 1][j + 1].rgbtBlue;
                count++;
            }
            // COMMMMMMMEEEEEEEENT
            // COMMMMMMMEEEEEEEENT
            // COMMMMMMMEEEEEEEENT
            // COMMMMMMMEEEEEEEENT
            image[i][j].rgbtRed = round((float)avR / (float)count);
            image[i][j].rgbtGreen = round((float)avG / (float)count);
            image[i][j].rgbtBlue = round((float)avB / (float)count);


        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // GX Vals
            int Rgx = 0;
            int Ggx = 0;
            int Bgx = 0;

            // GY Vals
            int Rgy = 0;
            int Ggy = 0;
            int Bgy = 0;

            bool jm1 = false;
            bool jp1 = false;
            bool im1 = false;
            bool ip1 = false;

            if (j - 1 >= 0)
            {
                jm1 = true;
                Rgx += -2 * temp[i][j - 1].rgbtRed;
                Ggx += -2 * temp[i][j - 1].rgbtGreen;
                Bgx += -2 * temp[i][j - 1].rgbtBlue;
            }
            // A comment a day keeps bugs away but this is like a one time thing
            // I'm kinda done with this
            if (j + 1 < width)
            {
                jp1 = true;
                Rgx += 2 * temp[i][j + 1].rgbtRed;
                Ggx += 2 * temp[i][j + 1].rgbtGreen;
                Bgx += 2 * temp[i][j + 1].rgbtBlue;
            }
            if (i - 1 >= 0)
            {
                im1 = true;
                Rgy += -2 * temp[i - 1][j].rgbtRed;
                Ggy += -2 * temp[i - 1][j].rgbtGreen;
                Bgy += -2 * temp[i - 1][j].rgbtBlue;
            }
            if (i + 1 < height)
            {
                ip1 = true;
                Rgy += 2 * temp[i + 1][j].rgbtRed;
                Ggy += 2 * temp[i + 1][j].rgbtGreen;
                Bgy += 2 * temp[i + 1][j].rgbtBlue;
            }

            if (im1 && jm1)
            {
                Rgx += -1 * temp[i - 1][j - 1].rgbtRed;
                Ggx += -1 * temp[i - 1][j - 1].rgbtGreen;
                Bgx += -1 * temp[i - 1][j - 1].rgbtBlue;

                Rgy += -1 * temp[i - 1][j - 1].rgbtRed;
                Ggy += -1 * temp[i - 1][j - 1].rgbtGreen;
                Bgy += -1 * temp[i - 1][j - 1].rgbtBlue;
            }

            if (im1 && jp1)
            {
                Rgx += 1 * temp[i - 1][j + 1].rgbtRed;
                Ggx += 1 * temp[i - 1][j + 1].rgbtGreen;
                Bgx += 1 * temp[i - 1][j + 1].rgbtBlue;

                Rgy += -1 * temp[i - 1][j + 1].rgbtRed;
                Ggy += -1 * temp[i - 1][j + 1].rgbtGreen;
                Bgy += -1 * temp[i - 1][j + 1].rgbtBlue;
            }
            // COMMMMMMMEEEEEEEENT
            if (ip1 && jm1)
            {
                Rgx += -1 * temp[i + 1][j - 1].rgbtRed;
                Ggx += -1 * temp[i + 1][j - 1].rgbtGreen;
                Bgx += -1 * temp[i + 1][j - 1].rgbtBlue;

                Rgy += 1 * temp[i + 1][j - 1].rgbtRed;
                Ggy += 1 * temp[i + 1][j - 1].rgbtGreen;
                Bgy += 1 * temp[i + 1][j - 1].rgbtBlue;

            }
            // COMMMMMMMEEEEEEEENT
            // COMMMMMMMEEEEEEEENT

            if (ip1 && jp1)
            {
                Rgx += 1 * temp[i + 1][j + 1].rgbtRed;
                Ggx += 1 * temp[i + 1][j + 1].rgbtGreen;
                Bgx += 1 * temp[i + 1][j + 1].rgbtBlue;

                Rgy += 1 * temp[i + 1][j + 1].rgbtRed;
                Ggy += 1 * temp[i + 1][j + 1].rgbtGreen;
                Bgy += 1 * temp[i + 1][j + 1].rgbtBlue;
            }

            int finR = round(hypot((float)Rgx, (float)Rgy));
            int finG = round(hypot((float)Ggx, (float)Ggy));
            int finB = round(hypot((float)Bgx, (float)Bgy));

            if (finR > 255)
            {
                finR = 255;
            }
            if (finG > 255)
            {
                finG = 255;
            }
            if (finB > 255)
            {
                finB = 255;
            }

            image[i][j].rgbtRed = finR;
            image[i][j].rgbtGreen = finG;
            image[i][j].rgbtBlue = finB;
        }
    }
    return;
}
