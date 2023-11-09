#include <stdio.h>
#include <math.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int al, bl;

int square(int i)
{
    return i * i;
}

int max(int n, int m)
{
    int a = n;
    int b = m;
    if(a < b || a == b)
    {
        return b;
    }
    return a;
}

int exponent(int i)
{
    int acc = 1;
    for (int j = 0; j < i; j++)
    {
        acc *= 10;
    }
    return acc;
}

int karatsuba(int n, int m)
{
    int x = n;
    int y = m;
    int ax = 0;
    int ay = 0;
    int cx;
    int cy;

    // string aax = tostr(ax);
    // string aay = tostr(ay);
    // int an = strlen(aax);
    // int am = strlen(aay);


    cx = exponent(al - 2);
    ax += (x % cx);
    x = x / cx;

    cy = exponent(bl - 2);
    ay += (y % cy);
    y = y / cy;


    printf("%i\n", ax);
    printf("%i\n", ay);
    int ac = x * y;
    int bd = ax * ay;
    int abcd = (x + ax) * (y + ay);
    int ad = abcd - (ac + bd);
    int acz = square(max(cx, cy)) * ac;
    int aa = acz + (ad * max(cx, cy));
    return aa;
}

int main()
{
    string as = get_string("First number: ");
    string bs = get_string("Second number: ");
    al = strlen(as);
    bl = strlen(bs);
    int a = atoi(as);
    int b = atoi(bs);

    printf("%i\n", karatsuba(a, b));
}