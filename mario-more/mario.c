#include <cs50.h>
#include <stdio.h>

void print_pyramids(int n);

int main(void)
{
    int n = 0;
    do
    {
        n = get_int("Height: ");

        print_pyramids(n);
    }
    while (n < 1);
}

void print_pyramids(int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j < n - i)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }

        printf("  ");

        for (int j = 1; j <= n; j++)
        {
            if (j <= i + 1)
            {
                printf("#");
            }
        }

        printf("\n");
    }
}
