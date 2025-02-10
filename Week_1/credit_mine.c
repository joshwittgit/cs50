#include <cs50.h>
#include <math.h>
#include <stdio.h>

void thirt(long card, int lead, int dig);
void fift(long card, int lead, int dig);
void sixt(long card, int lead, int dig);
bool luhn(long card, int dig);

int main(void)
{
    long card = get_long("What is you\'re credit card number? ");
    bool digs13 = (9 < (card / ((long)pow(10, 11))) && (card / ((long)pow(10, 11))) < 100);
    bool digs15 = (9 < (card / ((long)pow(10, 13))) && (card / ((long)pow(10, 13))) < 100);
    bool digs16 = (9 < (card / ((long)pow(10, 14))) && (card / ((long)pow(10, 14))) < 100);
    // printf("%i ,%i, %i \n", dig13, dig15, dig16);

    if (digs13 == 1) // VISA (40)
    {
        int dig13 = 13;
        int lead13 = (int)(card / ((long)pow(10, 11)));
        thirt(card, lead13, dig13);
    }
    else if (digs15 == 1) // AMEX (34 or 37)
    {
        int dig15 = 15;
        int lead15 = (int)(card / ((long)pow(10, 13)));
        fift(card, lead15, dig15);
    }
    else if (digs16 == 1) // VISA (40) OR MASTERCARD (51, 52, 53, 54, or 55)
    {
        int dig16 = 16;
        int lead16 = (int)(card / ((long)pow(10, 14)));
        sixt(card, lead16, dig16);
    }
    else
    {
        printf("INVALID\n");
    }
}

void thirt(long card, int lead, int dig)
{
    bool start13 = (39 < lead && lead < 50);
    if (start13 == 1)
    {
        bool security = luhn(card, dig);
        if (security == 1)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

void fift(long card, int lead, int dig)
{
    bool start15 = (lead == 34 || lead == 37);
    if (start15 == 1)
    {
        bool security = luhn(card, dig);
        if (security == 1)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

void sixt(long card, int lead, int dig)
{
    bool start16visa = (39 < lead && lead < 50);
    bool start16MC = (50 < lead && lead < 56);
    if (start16visa == 1)
    {
        bool security = luhn(card, dig);
        if (security == 1)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (start16MC == 1)
    {
        bool security = luhn(card, dig);
        if (security == 1)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

bool luhn(long card, int dig)
{
    int sum;
    for (int i = 0; i < dig; i++)
    {
        if (i % 2 == 0)
        {
            long num = card % (long)pow(10, i + 1);
            long den = (long)pow(10, i);
            int digit = (int)(num / den);
            sum = sum + (int)(num / den);
        }
        else
        {
            long num = card % (long)pow(10, i + 1);
            long den = (long)pow(10, i);
            int digit = (int)(num / den);
            if (digit != 9)
            {
                sum = sum + ((digit * 2) % 9);
            }
            else
            {
                sum = sum + digit;
            }
        }
    }
    bool sectest = (sum % 10) == 0;
    return sectest;
    // printf("%i\n", sum);
}

// bool length = (9 < (card / ((long)pow(10,11))) && (card / ((long)pow(10,11))) < 100) || (9 <
// (card / ((long)pow(10,14))) && (card / ((long)pow(10,14))) < 100);
