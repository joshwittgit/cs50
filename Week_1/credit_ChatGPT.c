#include <cs50.h>
#include <math.h>
#include <stdio.h>

bool luhn(long card);
int get_length(long num);
void check_card_type(long card);

int main(void)
{
    long card = get_long("What is your credit card number? ");
    check_card_type(card);
}

int get_length(long num)
{
    int length = 0;
    while (num > 0)
    {
        num /= 10;
        length++;
    }
    return length;
}

bool luhn(long card)
{
    int sum = 0;
    bool alternate = false;

    while (card > 0)
    {
        int digit = card % 10;
        card /= 10;

        if (alternate)
        {
            digit *= 2;
            if (digit > 9)
                digit -= 9;
        }

        sum += digit;
        alternate = !alternate;
    }

    return (sum % 10 == 0);
}

void check_card_type(long card)
{
    int length = get_length(card);
    int lead = (int)(card / pow(10, length - 2));

    if ((length == 13 || length == 16) && (lead >= 40 && lead < 50)) // VISA
    {
        if (luhn(card))
            printf("VISA\n");
        else
            printf("INVALID\n");
    }
    else if (length == 15 && (lead == 34 || lead == 37)) // AMEX
    {
        if (luhn(card))
            printf("AMEX\n");
        else
            printf("INVALID\n");
    }
    else if (length == 16 && (lead >= 51 && lead <= 55)) // MASTERCARD
    {
        if (luhn(card))
            printf("MASTERCARD\n");
        else
            printf("INVALID\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
