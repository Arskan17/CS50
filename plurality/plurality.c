#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
        //printf("%b\n", vote(name));
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int j = 0; j < candidate_count; j++)
    {
        if (strcmp(candidates[j].name, name) == 0)
        {
            candidates[j].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int c = candidate_count;
    int comp[c];
    // candidate swap[c];

    // for (int e = 0; e < c; e++)
    // {
    //     swap[e] = candidates[e];
    // }

    for (int k = 0; k < c; k++)
    {
        for (int l = (k + 1); l < c; l++)
        {
            int a = candidates[k].votes;
            string aa = candidates[k].name;

            int b = candidates[l].votes;
            string bb = candidates[l].name;

            if (a > b)
            {
                candidates[k].votes = b;
                candidates[k].name = bb;
                candidates[l].votes = a;
                candidates[l].name = aa;
            }
        }
    }

    // for (int s = 0; s < c; s++)
    // {
    //     printf("%i\n", candidates[s].votes);
    // }

    int cv = candidates[c-1].votes;
    for (int u = 0; u < c; u++)
    {
        int ccv = candidates[u].votes;
        if (cv == ccv)
        {
            string v = candidates[u].name;
            printf("%s\n", v);
        }
    }

    return;
}