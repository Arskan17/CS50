#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main()
{
    double n = get_double("Input integer: ");

    for (int i = 1; i <= n; i++)
    {
        int c = 0;
        for(int j = 1; j < i; j++)
        {
            if((i%j) == 0)
            {
                c++;
            }
        }

        if(c == 1)
        {
            printf("%i, ", i);
        }
    }
}