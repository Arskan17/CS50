#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    //prints out which player scored
    if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else if (score1 == score2)
    {
        printf("Tie!\n");
    }
    else
    {
        printf("Player 1 wins!\n");
    }
}

//calculates a words' points
int compute_score(string word)
{
    int x = strlen(word);
    int y = 0;
    string a = word;

    //converts the word to uppercase
    for (int i = 0; i < x; i++)
    {
        a[i] = toupper(word[i]);
    }

    //and then gets the ASCII equivalent of each characters and further substracts 65,
    //to get the points at that position in POINTS
    for (int j = 0; j < x; j++)
    {
        int t = ((int) a[j]) - 65;
        //printf("%i\n", t);
        y += POINTS[t];
    }
    //returns the score
    return y;
}
