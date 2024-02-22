#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string phrase = get_string("Text: ");
    int letters = count_letters(phrase);
    int words = count_words(phrase);
    int sentences = count_sentences(phrase);

    double L = 1.0 * letters / words * 100;
    double S = 1.0 * sentences / words * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);
    // printf("letters %i\n", letters);
    // printf("words %i\n", words);
    // printf("sentences %i\n", sentences);
    // printf("index %i\n", index);
    // printf("L %f", L);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_sentences(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}

int count_letters(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    int words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }
    return words;
}
