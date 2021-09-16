#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


// Propotypes
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Declarations
    int nletters, nwords, nsentences, intindex;
    float avgl, avgs, index;
    string grade;

    // Prompt user
    string text = get_string("Text: ");

    // Compute letters, words and sentences
    nletters  = count_letters(text);
    nwords = count_words(text);
    nsentences = count_sentences(text);

    //printf("%i letter(s)\n", nletters);
    //printf("%i word(s)\n", nwords);
    //printf("%i sentence(s)\n", nsentences);


    /*
    index = 0.0588 * L - 0.296 * S - 15.8
    L is the average number of letters per 100 words in the text
    S is the average number of sentences per 100 words in the text.
    */

    avgl = (100 * (float)nletters) / (float)nwords;
    avgs = (100 * (float)nsentences) / (float)nwords;
    //printf("avgl: %f, avgs:%f\n", avgl, avgs);

    index = 0.0588 * avgl - 0.296 * avgs - 15.8;

    // https://manual.cs50.io/3/round
    intindex = (int)round(index);
    //printf("Index: %i\n", intindex);

    // Output grade
    if (intindex < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (intindex >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", intindex);
    }

    return 0;
}

int count_sentences(string text)
{
    // Declarations
    int nsentences = 0;
    int text_length = strlen(text);
    int c;

    for (int i = 0; i < (int) text_length; i++)
    {
        c = text[i];
        if (c == 33 || c == 46 || c == 63)
        {
            nsentences++;
        }
    }

    return nsentences;
}

int count_words(string text)
{
    // Declarations
    int nwords = 0;
    int text_length = strlen(text);
    int c;

    for (int i = 0; i < (int) text_length; i++)
    {
        c = text[i];
        if (c == 32) // Space
        {
            nwords++;
        }
    }

    // Prevent count word if "text" if only a space for example.
    if (text_length > 1)
    {
        nwords += 1; // Add one word, because after first space must count 1 word.
    }

    return nwords;
}

int count_letters(string text)
{
    // Declarations
    int nchars = 0;
    int text_length = strlen(text);
    int c;

    for (int i = 0; i < text_length; i++)
    {
        c = text[i];
        if (c >= 65 && c <= 90) // Letters upercase
        {
            nchars++;
        }
        else if (c >= 97 && c <= 122) // Letters lowercase
        {
            nchars++;
        }
    }

    return nchars;
}