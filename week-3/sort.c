#include <stdio.h>

void main(void)
{

    int LEN = 6;

    int arr[] = {2, 3, 5, 6, 4, 1};

    for(int i = 0; i < LEN; i++)
    {
        for (int j = 0; j < LEN - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
        
    }


    for(int i = 0; i < LEN; i++)
    {
        printf("%d ", arr[i]);
    }


    printf("\n");
    return;

}