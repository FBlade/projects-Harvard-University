#include <cs50.h>
#include <stdio.h>

// Propotypes
void create_pyramid(int height);

int main(void)
{
    // Declarations
    int height;

    // Get a valid pyramid height
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    create_pyramid(height);
    return 0;
}

// Create The Pyramid
void create_pyramid(int height)
{
    // Loop through height lines
    for (int i = 1; i <= height; i++)
    {
        //Loop through height for characters
        for (int j = height; j > 0; j--)
        {
            if (j > i)
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
