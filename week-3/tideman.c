#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9
#define MAX_PAIRS MAX * (MAX - 1) / 2

#define false 0
#define true 1

typedef __uint8_t bool;
typedef char *string;

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX_PAIRS];

int pair_count;
int candidate_count;

// Function prototypes
int get_int(string text);
string get_string(string text);
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    printf("Cool! %d candidates!\n", candidate_count);
    for(int i = 0; i < candidate_count; i++)
    {
        printf("%s(ID: %d)\n", candidates[i], i);
    }
    printf("\n");

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            char name[20];
            printf("Rank %i: ", j + 1);
            scanf("%s", name);
            
            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            printf("%d|", preferences[i][j]);
        }
        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

int get_int(string text)
{
    int number;
    printf("%s", text);
    scanf("%i", &number);

    return number;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO

    printf("vote\n");

    for(int i = 0; i < candidate_count; i++)
    {
        if(strcmp(name, candidates[i]) == 0)
        {
            printf("%s(ID: %d)\n", candidates[i], i);
            ranks[rank] = i; // Get candidate 'ID'(in this case, array id)
            return true;
        }
    }

    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO

    for(int a = 0; a < candidate_count - 1; a++)
    {
        int prefer = ranks[a];
        for(int b = a + 1; b < candidate_count; b++)
        {
            int preferless = ranks[b];
            preferences[prefer][preferless]++;
        }
    }
    
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO

    int p = 0;
    for(int a = 0; a < candidate_count; a++)
    {
        for(int b = a; b < candidate_count; b++)
        {
            if(a == b) continue;

            pair current_pair;
            if(preferences[a][b] > preferences[b][a])
            {   
                current_pair.winner = a;       
                current_pair.loser = b;       
            } 
            else 
            {
                current_pair.winner = b;       
                current_pair.loser = a;
            }
            pairs[p++] = current_pair;
        }
    }
    for(int i = 0; i < MAX_PAIRS; i++)
    {
        printf("%d/%d\n", pairs[i].winner, pairs[i].loser);
    }

    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}