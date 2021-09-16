#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prototypes
    int calculate_years(int start, int end);

    // Declarations
    int start_size;
    int end_size;
    int years;

    // Prompt for start size
    do
    {
        start_size = get_int("Start size: ");
    }
    while (start_size < 9);

    // Prompt for end size
    do
    {
        end_size = get_int("End size: ");
    }
    while (end_size < start_size);

    // Calculate number of years until we reach threshold
    years = calculate_years(start_size, end_size);

    //Print number of years
    printf("Years: %i", years);

    return 0;
}

// Calcualte llamas growth population
int calculate_years(int start, int end)
{
    // Declarations
    int years = 0;
    int population = start;

    // Handles same starting and ending sizes
    if (start == end)
    {
        return 0;
    }

    // Year by year population calculation
    do
    {
        population += (int)((population / 3) - (population / 4));
        years++;
    }
    while (population < end);

    return years;
}