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
} candidate;

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
    // Loop through each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // Check if candidate's name is equal to inputted name
        if (strcmp(candidates[i].name, name) == 0)
        {
            // Increment the candidate's votes if true
            candidates[i].votes++;
            return true;
        }
    }
    // Return false otherwise
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Declare variable for maximum votes
    int maximum_votes = 0;

    // Loop through each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // Compare the candidate's votes to the maximum votes
        if (candidates[i].votes > maximum_votes)
        {
            // Adjust the value of the maximum votes accordingly
            maximum_votes = candidates[i].votes;
        }
    }

    // Loop through each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // Print out the winners with the most votes
        if (candidates[i].votes == maximum_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}
