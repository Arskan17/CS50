#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>


int count_letters(string sl);
int count_words(string sw);
int count_sentences(string ss);


int main(void)
{
    string sentx = get_string("TEXT: ");

    float l = count_letters(sentx);

    float w = count_words(sentx);

    float s = count_sentences(sentx);

    //calculates the Coleman-Liau index
    float c = (0.0588 * ((l/w) * 100.00)) - (0.296 * ((s/w) * 100.00)) - 15.8;
    int ci = c;

    //rounds the index to the nearest integer
    if ((c - ci ) >= 0.5)
    {
        ci++;
    }
    else
    {
        c = c + 0;
    }

    //prints out the Grade reading level of the text
    if (c < 1.00)
    {
        printf("Before Grade 1\n");
    }
    else if(c >= 1.00 && c < 16.00)
    {
        printf("Grade %i\n", ci);
    }
    else
    {
        printf("Grade 16+\n");
    }

    // printf("%s\n", sentx);
    // printf("%f Letters\n", l);
    // printf("%f Words\n", w);
    // printf("%f Sentences\n", s);
}


//Calculates the number of letters in the text and then returns it back
int count_letters(string sl)
{
    string sentl = sl;
    int x = strlen(sentl);
    int n = 0;

    //loops every cheracter till a letter is found, then increments n
    for (int i = 0; i < x; i++)
    {
        int pos = sentl[i];
        if ((pos >= 65 && pos <= 90) || (pos >= 97 && pos <= 122))
        {
            n++;
        }
    }
    return n;
}

//calculates the number of words in the text and then returns it back
int count_words(string sw)
{
    string sentw = sw;
    int xi = strlen(sw);
    int m = 0;

    //loops every character till a space is found, then increment m
    for (int j = 0; j < xi; j++)
    {
        int posi = sentw[j];
        if (posi == 32)
        {
            m++;
        }
    }
    return m + 1;
}

//calculates the number of sentences in the text and then returns it back
int count_sentences(string ss)
{
    string sents = ss;
    int xii = strlen(ss);
    int o = 0;

    //loops each character till a (.), (!), or (?) is found, then increment o
    for (int k = 0; k < xii; k++)
    {
        int posii = sents[k];
        if ((posii == 33) || (posii == 63) || (posii == 46))
        {
            o++;
        }
    }
    return o;
}