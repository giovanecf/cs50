#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct 
{
    char name[20];
    int votes;

} candidate;

int compute_vote(char name[], candidate* c_arr, int number_of_candidates);

void print_arr(int arr[], int size);

void spred_arr(candidate in_arr[], candidate* out_arr, int in_arr_start_index, int out_arr_start_index, int in_arr_end_index, int out_arr_end_index);

int slice_arr(candidate arr[], int left_side_size, int right_side_size, candidate* left_side_arr, candidate* right_side_arr);

void merge_sort_candidates(candidate* arr, int arr_size);


int main(int argc, char **argv)
{

    int number_of_candidates = argc - 1;

    if(number_of_candidates < 2)
    {
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
    
    } 
    while (votes_to_compute < 1);


    for(int i = 0; i < votes_to_compute; i++)
    {
        char candidate_name[20];
        do
        {
            printf("Vote %d: ", i + 1);
            scanf("%s", candidate_name);
            
        } 
        while (compute_vote(candidate_name, candidates, number_of_candidates) == 0);
        
    }

    // for(int i = 0; i < number_of_candidates; i++)
    // {
    //     printf("%s has %d votes\n", candidates[i].name, candidates[i].votes);
    // }

    // Sort candidades by num of votes
    merge_sort_candidates(candidates, number_of_candidates);
    for(int i = 0; i < number_of_candidates; i++)
    {
        printf("%s has %d votes\n", candidates[i].name, candidates[i].votes);
    }

    if(candidates[number_of_candidates - 1].votes == candidates[number_of_candidates - 2].votes)
    {
        printf("Draw!\n");
        return -1;
    }

    printf("%s Wins!\n", candidates[number_of_candidates - 1].name);

    return 0;
}


void print_arr(int arr[], int size)
{
    printf("\n");
    for(int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
    printf("\n\n");
}

void spred_arr(candidate in_arr[], candidate* out_arr, int in_arr_start_index, int out_arr_start_index, int in_arr_end_index, int out_arr_end_index)
{

    for(int i = in_arr_start_index, j = out_arr_start_index; i < in_arr_end_index; i++, j++)
    {
        if(j == out_arr_end_index)
        {
            printf("Out-array smaller then In-array.\n");
            return;
        }
        out_arr[j] = in_arr[i];
    }

}

int slice_arr(candidate arr[], int left_side_size, int right_side_size, candidate* left_side_arr, candidate* right_side_arr)
{

    for(int i = 0; i < left_side_size; i++)
    {
        left_side_arr[i] = arr[i];
    }

    for(int i = 0, j = left_side_size; j < left_side_size+right_side_size; i++, j++)
    {
        right_side_arr[i] = arr[j];
    }
}

void merge_sort_candidates(candidate* arr, int arr_size)
{

    if(arr_size == 1) return;

    int left_side_size = 0;
    int right_side_size = 0;
    
    if(arr_size % 2 == 0){
        left_side_size = right_side_size = arr_size / 2;
    } else {
        left_side_size = arr_size / 2;
        right_side_size = arr_size / 2 + 1;
    }

    candidate left_side_arr[left_side_size];
    candidate right_side_arr[right_side_size];

    slice_arr(arr, left_side_size, right_side_size, left_side_arr, right_side_arr);

    merge_sort_candidates(left_side_arr, left_side_size);

    merge_sort_candidates(right_side_arr, right_side_size);

    int right_side_index = 0;
    int left_side_index = 0;
    int arr_index = 0;
    while(1)
    {
        /**
         * This is the line that defines which property 
         * it uses to sort:
         * if(left_side_arr[left_side_index] < right_side_arr[right_side_index])
        **/

        if(left_side_arr[left_side_index].votes < right_side_arr[right_side_index].votes)
        {
            arr[arr_index++] = left_side_arr[left_side_index++];
        } 
        else
        {
            arr[arr_index++] = right_side_arr[right_side_index++];
        }

        if(right_side_index == right_side_size)
        {
            spred_arr(left_side_arr, arr, left_side_index, arr_index, left_side_size, arr_size);
            break;
        }

        if(left_side_index == left_side_size)
        {
            spred_arr(right_side_arr, arr, right_side_index, arr_index, right_side_size, arr_size);
            break;
        }

    }

}

int compute_vote(char name[], candidate* c_arr, int number_of_candidates)
{
    for(int i = 0; i < number_of_candidates; i++)
    {
        printf("%s - %s\n", name, c_arr[i].name);
        if(strcmp(name, c_arr[i].name) == 0)
        {
            printf("Vote computed!\n");
            c_arr[i].votes += 1;
            return 1;
        }
    }

    return 0;
}