#include <cs50.h>
#include <stdio.h>

void print_pyramid(int n);

int main(void)
{
    int n = 0;
    do
    {
        n = get_int("Height: ");

        print_pyramid(n);
    }
    while (n < 1);
}

void print_pyramid(int n)
{
    // Print lines
    for (int i = 0; i < n; i++)
    {
        // Print columns
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
        printf("\n");
    }
}
