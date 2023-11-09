#include <stdio.h>
#include <math.h>
#include <cs50.h>

int factorial(int c)
{
    int n = c;
    if(n == 1){ return 1;}
    else
    {
        return (n * factorial(n - 1));
    }
}

int main()
{
    int q = get_int("Factorial: ");
    int f = q;

    for (int i = 1; i < (q - 1); i++)
    {
        f = f * (f - i);
    }
    printf("%i\n", f);
    printf("%i\n", factorial(q));
}