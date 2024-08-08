#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct 
{
    char name[20];
    int votes;

} candidate;

int compute_vote(char name[], candidate* c_arr);

int main(int argc, char **argv){

    if(argc < 2){
        printf("Usage: ./plurality [candidate ...]\n");
        return 1;
    }

    candidate candidates[argc - 1];

    for(int i = 0; i < argc - 1; i++)
    {
        if (strlen(argv[i + 1]) >= sizeof(candidates[i].name)) {
            printf("filename too long: %s\n", argv[1]);
            continue;
        } else {
            strcpy(candidates[i].name, argv[i + 1]);
            candidates[i].votes = 0;
        }

        printf("%s has %i votes\n", candidates[i].name, candidates[i].votes);
    }

    int votes_to_compute; 
    printf("Votes: ");
    scanf("%i", &votes_to_compute);

    for(int i = 0; i < votes_to_compute; i++)
    {
        char candidate_name[20];
        do
        {
            printf("Vote %d: ", i + 1);
            scanf("%s", candidate_name);
            
        } while (compute_vote(candidate_name, candidates) == 0);
        
    }

    for(int i = 0; i < argc - 1; i++)
    {
        printf("%s has %i votes\n", candidates[i].name, candidates[i].votes);
    }
    

    return 0;
}

int compute_vote(char name[], candidate* c_arr)
{
    for(int i = 0; i < sizeof(c_arr); i++)
    {
        if(strcmp(name, c_arr[i].name) == 0)
        {
            c_arr[i].votes += 1;
            return 1;
        }
    }

    return 0;
}