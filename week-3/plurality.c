#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct 
{
    char name[20];
    int votes;

} candidate;

int compute_vote(char name[], candidate* c_arr, int number_of_candidates);

void merge_sort()
{

    int n[] = {2,1,4,6,3,7,8,5,9};

    slice

    merge

    order


    log2 (n / 2)



}

int main(int argc, char **argv){

    merge_sort();

    return 2;

    int number_of_candidates = argc - 1;

    if(number_of_candidates < 2){
        printf("Usage: ./plurality [candidate ...]\n");
        return 1;
    }

    candidate candidates[number_of_candidates];

    for(int i = 0; i < number_of_candidates; i++)
    {
        if (strlen(argv[i + 1]) >= sizeof(candidates[i].name)) {
            printf("candidate name too long: %s\n", argv[1]);
            continue;
        } else {
            strcpy(candidates[i].name, argv[i + 1]);
            candidates[i].votes = 0;
        }

        printf("%s has %d votes\n", candidates[i].name, candidates[i].votes);
    }

    int votes_to_compute; 

    do
    {
        votes_to_compute = 0;
        
    printf("Number of voters: ");
        scanf("%d", &votes_to_compute);
    
    } while (votes_to_compute < 1);


    for(int i = 0; i < votes_to_compute; i++)
    {
        char candidate_name[20];
        do
        {
            printf("Vote %d: ", i + 1);
            scanf("%s", candidate_name);
            
        } while (compute_vote(candidate_name, candidates, number_of_candidates) == 0);
        
    }

    for(int i = 0; i < number_of_candidates; i++)
    {
        printf("%s has %d votes\n", candidates[i].name, candidates[i].votes);
    }



    // Sort(Merge) candidades by Num of Votes and then select the first(or last)
    
    

    return 0;
}

int compute_vote(char name[], candidate* c_arr, int number_of_candidates)
{
    for(int i = 0; i < number_of_candidates; i++)
    {
        printf("%s - %s\n", name, c_arr[i].name);
        if(strcmp(name, c_arr[i].name) == 0)
        {
            printf("Match!\n");
            c_arr[i].votes += 1;
            return 1;
        }
    }

    return 0;
}