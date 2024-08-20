#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct 
{
    char name[20];
    int votes;

} candidate;

int compute_vote(char name[], candidate* c_arr, int number_of_candidates);

void print_arr(int arr[], int size)
{
    printf("\n");
    for(int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
    printf("\n\n");
}

int slice_arr(int arr[], int left_side_size, int right_side_size, int* left_side_arr, int* right_side_arr)
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

void merge_sort(int* arr, int arr_size)
{

    if(arr_size == 1) {
        printf("%d\n", arr[0]);
        return;
    }

    int left_side_size = 0;
    int right_side_size = 0;
    
    if(arr_size % 2 == 0){
        left_side_size = right_side_size = arr_size / 2;
    } else {
        left_side_size = arr_size / 2;
        right_side_size = arr_size / 2 + 1;
    }

    //printf("%d %d\n", left_side_size, right_side_size);

    int left_side_arr[left_side_size];
    int right_side_arr[right_side_size];

    slice_arr(arr, left_side_size, right_side_size, left_side_arr, right_side_arr);

    merge_sort(left_side_arr, left_side_size);

    merge_sort(right_side_arr, right_side_size);

    printf("L\n");
    print_arr(left_side_arr, left_side_size);

    printf("R\n");
    print_arr(right_side_arr, right_side_size);

    int j = 0;
    int last_right_item = 0;
    for(int i = 0; i < right_side_size; i++)
    {
        if(right_side_arr[i] > left_side_arr[j])
        {
            arr[i] =  left_side_arr[j];
            j++;
        }

        if(right_side_arr[i] < left_side_arr[j])
            arr[i] = right_side_arr[i];

        last_right_item = i;

        if(j == left_side_size) break;

    }

    for(int i = last_right_item; i < right_side_size; i++)
    {
        arr[i] = right_side_arr[i];
    }

    print_arr(arr, arr_size);

}

int main(int argc, char **argv){

    int n[] = {2,1,4,6,3,7,8,5,9};
 
    print_arr(n, 9);
    
    merge_sort(n, 9);

    print_arr(n, 9);

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