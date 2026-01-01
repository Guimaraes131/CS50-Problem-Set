#include <cs50.h>
#include <stdio.h>

int calc_coins(int cash);

int main(void)
{
    int cash = 0;
    do
    {
        cash = get_int("Change owed: ");
    }
    while (cash < 0);

    int coins = calc_coins(cash);

    printf("%i\n", coins);
}

int calc_coins(int cash)
{

    if (cash == 0) {
        return 0;
    }

    int coins = 0;
    while (cash >= 25)
    {
        cash -= 25;
        coins += 1;
    }

    while (cash >= 10)
    {
        cash -= 10;
        coins += 1;
    }

    while (cash >= 5)
    {
        cash -= 5;
        coins += 1;
    }

    while (cash >= 1)
    {
        cash -= 1;
        coins += 1;
    }

    return coins;
}
