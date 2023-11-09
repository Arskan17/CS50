#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

string sub_sub(string txt, string k);

int main(int argc, string argv[])
{
    string key = argv[1];  //gets the second argcument entered in the CLI.
    int len = strlen(argv[1]);  //calculates its length. Must be 26 btw.
    int a = argc;

    //checks validity of key.
    if ((a == 2) && (len != 26))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else if (a != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if ((a == 2) && (len == 26))
    {
        for (int p = 0; p < len; p++) //checks whether the key contains a non-alphabetical character.
        {
            if (isalpha(key[p]) == 0)
            {
                printf("Key must contain only aplphabetical characters.\n");
                return 1;
            }
        }

        for (int q = 0; q < len; q++) //checks whether the key contains a duplicate character.
        {
            for (int qi = (q + 1); qi < (26 - q); qi++)
            {
                if (key[q] == key[qi])
                {
                    printf("Key must not contain duplicate characters.\n");
                    return 1;
                }
            }
        }
    }

    string pln = get_string("Plaintext: ");  //gets the text to be encoded.

    string cypher = sub_sub(pln, key);

    printf("ciphertext: %s\n", cypher);

    return 0;
}



string sub_sub(string txt, string k)
{
    string t = txt;
    string ky = k;
    int l = strlen(txt);

    //checks if upper/lower case
    //then substitutes respectively with help of the key
    for (int i = 0; i < l; i++)
    {
        if (isalpha(txt[i]) != 0)
        {
            if (isupper(txt[i]) != 0)
            {
                char c = ky[((int)txt[i]) - 65];
                if (isupper(c) != 0)
                {
                     t[i] = c; //when an uppercase, substracts 65 from its ASCII representation.
                              //that'll give us the exact position of the character in the key it needs to be substituted with.
                             //then it's just a matter of converting it to uppercase(if lowercase)/or just giving it back.
                }
                else
                {
                    t[i] = toupper(c);
                }
            }
            else  //if (islower(txt[i]) != 0)
            {
                char b = ky[((int)txt[i]) - 97];
                if (islower(ky[i]) != 0)
                {
                    t[i] = b;
                }
                else
                {
                    t[i] = tolower(b);  //when a lowercase, substracts 97 from its ASCII representation.
                                       //that'll give us the exact position of the character in the key it needs to be substituted with.
                                      //then it's just a matter of converting it to lowercase(if uppercase)/or just giving it back.
                }
            }
        }
        else
        {
            t[i] = txt[i];
        }
    }
    return t;
}