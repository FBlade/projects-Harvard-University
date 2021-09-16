#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Propotypes
string get_credit_card_type(long ccnumber);
string validate_card(long c);

int main(void)
{
    // Declarations
    long credit_card;

    // Get a valid change owed value
    credit_card = get_long("Number: ");

    string res = get_credit_card_type(credit_card);
    printf("%s\n", res);
}

// Get type of credit card inserted
string get_credit_card_type(long ccnumber)
{
    // Get length of credit card number
    int cclen = 0;
    long t = ccnumber;
    while (t > 0)
    {
        t = t / 10;
        cclen++;
    }

    // Check if length is valid, otherwise returns INVALID
    if (cclen != 13 && cclen != 15 && cclen != 16)
    {
        return "INVALID";
    }

    return validate_card(ccnumber);
}

// Validate credit card and return its type
string validate_card(long c)
{
    // Declarations
    long ld = c, start_d = c;
    int m1, m2, d1, d2;
    int s1 = 0, s2 = 0;
    int t = 0;

    // Check credit card checksum
    do
    {
        // Remove last digit
        m1 = ld % 10;
        ld = ld / 10;
        s1 += m1;

        // Remove second last digit
        m2 = ld % 10;
        ld = ld / 10;
        // Double second last digit and add digits to s2
        m2 = m2 * 2;
        d1 = m2 % 10;
        d2 = m2 / 10;
        s2 += d1 + d2;
    }
    while (ld > 0);
    t = s1 + s2;

    // Get the first 2 digits of the credit card number
    while (start_d > 100)
    {
        start_d = start_d / 10;
    }

    // Check if last sum digit is zero, or return invalid
    if (t % 10 != 0)
    {
        return "INVALID" ;
    }

    // Check and return type of card
    if (start_d >= 51 && start_d <= 55) // Check if is Mastercard
    {
        return "MASTERCARD";
    }
    else if (start_d == 34 || start_d == 37) // Check if is Amex
    {
        return "AMEX";
    }
    else if (start_d / 10 == 4) // Check if is VISA
    {
        return "VISA";
    }
    else // otherwise is invalid
    {
        return "INVALID";
    }
}