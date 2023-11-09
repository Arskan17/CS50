#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card = get_long("Number: ");
    long crd = card;
    int f;
    int s;
    int chk;
    long n = card;
    int l = 0;


    //calculates the length of the card's number
    for (int j = 1; j <= n; j++)
    {
        n = n / 10;
        l++;
    }

    // get digits for checksum
    for (int c = 1; c <= l; c++)
    {
        //last and forward digits
        f = f + (crd % 10);
        crd = crd /10;

        //second to last and forward digits
        s =  s + ((((crd % 10) * 2) / 10) + (((crd % 10) * 2) % 10));
        crd = crd / 10;
    }

    //calculates checksum
    chk = f + s;

    //checks if card is valid an then prints out which one it is
    if (chk % 10 == 0)
    {
        //condition for AMEX cards
        if ((340000000000000 <= card && card < 350000000000000) || (370000000000000 <= card && card < 380000000000000))
        {
            printf("AMEX\n");
        }
        //condition for Mastercards
        else if (card >= 5100000000000000 && card < 5600000000000000)
        {
            printf("MASTERCARD\n");
        }
        //condition for Visa Cards
        else if ((4000000000000 <= card && card < 5000000000000) || (4000000000000000 <= card && card < 5000000000000000))
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