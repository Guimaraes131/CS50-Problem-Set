#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
void show_results(int score);

int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float l = (float) letters / words * 100;
    float s = (float) sentences / words * 100;

    int index = round(0.0588 * l - 0.296 * s - 15.8);

    show_results(index);
}

int count_letters(string text)
{
    int letters = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    return letters;
}

int count_words(string text)
{
    int words = 1;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }

    return words;
}

int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sentences++;
        }
    }

    return sentences;
}

void show_results(int score)
{
    if (score < 1)
    {
        printf("Before Grade 1\n");
        return;
    }

    if (score > 0 && score < 16)
    {
        printf("Grade %i\n", score);
        return;
    }

    printf("Grade 16+\n");
}
