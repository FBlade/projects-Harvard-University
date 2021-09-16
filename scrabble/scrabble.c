#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

//https://www.asciitable.com/

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    //printf("Player 1: %i\n", score1);
    //printf("Player 2: %i\n", score2);
    if (score1 > score2)
    {
        printf("Player 1 wins!");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!");
    }
    return 0;

}

// Calculate points for given word
int compute_score(string word)
{

    // Declarations
    int cur_char;
    int points = 0;

    // Loop through each word char
    for (int i = 0; i <= strlen(word); i++)
    {
        // Convert to upper case
        cur_char = word[i] = toupper(word[i]);

        // Check if char is in allowed range, and sum point (if so).
        if (cur_char >= 65 && cur_char <= 90) // range from A to Z (ASCII table)
        {
            points += POINTS[cur_char - 65]; // remove ascii index position of char "A" to match POINTS index
        }
    }
    return points;
}