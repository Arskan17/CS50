#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main()
{
    float q = get_float("number: ");
    float n = 0;
    float m = 1;

    if (q > 0)
    {
        //float t;
        int c = 1;
        printf("x%i = %f\n", c, m);
        do
        {
            n = m;
            m = (1.0 / 2.0) * (m + (q / m));
            c++;
            printf("x%i = %.16f\n", c, m);
            //m = t;
        }
        while (m != n);
    }
}