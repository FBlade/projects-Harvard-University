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

        // Create left pyrammid
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

        // Add spaces between pyramids
        printf("  ");

        // Create left pyrammid
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}
