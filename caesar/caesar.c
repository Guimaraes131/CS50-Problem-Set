#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string digits);
char rotate(char a, int key);

int main(int argc, string argv[])
{
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext:  ");

    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        printf("%c", rotate(plaintext[i], key));
    }

    printf("\n");
}

char rotate(char a, int key)
{
    if (!isalpha(a))
    {
        return a;
    }

    if (key > 26)
    {
        key %= 26;
    }

    int position = a;

    for (int i = 0; i < key; i++)
    {
        position += 1;

        if (position == 91)
        {
            position = 65;
        }
        else
        {
            if (position == 123)
            {
                position = 97;
            }
        }
    }

    return (char) position;
}

bool only_digits(string digits)
{
    for (int i = 0, n = strlen(digits); i < n; i++)
    {
        if (!isdigit(digits[i]))
        {
            return false;
        }
    }

    return true;
}
