#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string normalize_word(string word);
int calc_points(string word);
int verify_position(int position);
void show_winner(int p1, int p2);

int main(void)
{
    string p1 = normalize_word(get_string("Player 1: "));
    string p2 = normalize_word(get_string("Player 2: "));

    int scorep1 = calc_points(p1);
    int scorep2 = calc_points(p2);

    show_winner(scorep1, scorep2);
}

int calc_points(string word)
{
    string alphabet = "AEILNORSTUDGBCMPFHVWYKJXQZ";
    int points = 0;

    // Iterates over word
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // Iterates over alphabet
        for (int j = 0, n1 = strlen(alphabet); j < n1; j++)
        {
            if (word[i] == alphabet[j])
            {
                points += verify_position(j);
                break;
            }
        }
    }

    return points;
}

int verify_position(int position)
{
    if (position < 10)
    {
        return 1;
    }

    if (position == 10 || position == 11)
    {
        return 2;
    }

    if (position > 11 && position <= 15)
    {
        return 3;
    }

    if (position > 15 && position < 21)
    {
        return 4;
    }

    if (position == 21)
    {
        return 5;
    }

    if (position == 22 || position == 23)
    {
        return 8;
    }

    return 10;
}

void show_winner(int p1, int p2)
{
    if (p1 > p2)
    {
        printf("Player 1 wins!\n");
        return;
    }

    if (p2 > p1)
    {
        printf("Player 2 wins!\n");
        return;
    }

    printf("Tie!\n");
}

string normalize_word(string word)
{
    string new_word = word;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        new_word[i] = toupper(word[i]);
    }

    return new_word;
}
