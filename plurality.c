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
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
            //I might have problem with this
            //I actually had
            //First with strcmp()- I forgot that it returns an int
            //Second with the loop, I used MAX as a control statement
            //when I had to use candidate_count
            //Thanks for stackoverflow!
        }

    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    //Now I had an idea of this but I declared wrong data type and struggled with it
    int maximum_v = 0;
    //I have written this loop correctly
    //I just made some small improvements and again the control statement
    //in a loop caused a bit of trouble for me
    for (int i = 0; i < candidate_count; i++)
    {
        if (maximum_v < candidates[i].votes)
        {
            maximum_v = candidates[i].votes;
        }
    }
    //In general this program works correctly. But...man!
    //It is so hard to understand someone else's code! And modify it.
    for (int j = 0; j < candidate_count; j++)
    {
        if (maximum_v == candidates[j].votes)
        {
            printf("%s\n", candidates[j].name);

        }

    }
    return;
}

