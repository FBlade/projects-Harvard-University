#include <cs50.h>
#include <stdio.h>
#include <math.h>

// Propotypes
int calculate_n_coins(float change_owed);

int main(void)
{
    // Declarations
    float change_owed;

    // Get a valid Change owed value
    do
    {
        change_owed = get_float("Change owed: ");
    }
    while (change_owed <= 0);

    //Call function to calculate n coins
    int count_coins = calculate_n_coins(change_owed);
    printf("%i", count_coins);

    return 0;
}

// Calculate the numbers of coins used to make the change
int calculate_n_coins(float change_owed)
{
    // Declarations
    int existing_cents[4] = {25, 10, 5, 1};
    int coins[4];
    int count_coins = 0;

    // Convert meney to cents
    int change_owed_cents = round(change_owed * 100);

    // Calculate coins used and count
    for (int i = 0; i < 4; i++)
    {
        int rest = change_owed_cents % existing_cents[i];
        coins[i] = (change_owed_cents - rest) / existing_cents[i];
        change_owed_cents -= coins[i] * existing_cents[i];
        count_coins += coins[i];
        //printf("%ic coin: %i \n", existing_cents[i], coins[i]);
    }
    //printf("Num. coins: %i\n", count_coins);
    return count_coins;
}