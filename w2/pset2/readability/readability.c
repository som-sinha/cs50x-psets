// readability.c
// A program which gives the reading level of text in US Grade level
// Somaditya Sinha
// 2nd January 2020

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int letter_count(string text);
int word_count(string text);
int sent_count(string text);

// MAIN
int main(void)
{
    string text = get_string("Text: ");
    int w = word_count(text);
    int s = sent_count(text);
    int le = letter_count(text);

    float L = (le * 100) / (float)w; // Letters per 100 words
    float S = (s * 100) / (float)w; // sentences per 100 words
    float raw_index = (0.0588 * L) - (0.296 * S) - 15.8;

    int index = round(raw_index);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

    return 0;
}

// Functions
// LETTER COUNT
int letter_count(string text)
{
    int i = 0, count = 0;
    while (strcmp(&text[i], "\0"))
    {
        // A - Z
        if ((int)text[i] >= 65 && (int)text[i] <= 90)
        {
            count++;
        }
        // a - z
        if ((int)text[i] >= 97 && (int)text[i] <= 122)
        {
            count++;
        }
        i++;
    }
    return count;
}
// WORD COUNT
int word_count(string text)
{
    int i = 0, count = 0;
    while (strcmp(&text[i], "\0"))
    {
        int before = i - 1;
        if ((int)text[i] == 32)
//                         Space
        {
            if ((int)text[before] != 32)
//                                  Space
            {
                count++;
            }
        }
        if (i == strlen(text) - 1)
        {
            count++;
        }
        i++;
    }
    return count;
}

//SENTENCES COUNT
int sent_count(string text)
{
    int i = 0, count = 0;
    while (strcmp(&text[i], "\0"))
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            if (text[i - 1] != '.' || text[i - 1] != '!' || text[i - 1] != '?')
            {
                count++;
            }
        }
        i++;
    }
    return count;
}