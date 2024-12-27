#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int getrand(int min, int max)
{
    return (int)min+rand()%(max-min+1);
}

int* genRandArray(int size, int maxValue)
{
    int* arr = malloc(sizeof(int)*(size+1));
    arr[0] = size;
    for(int i=1;i<size+1;i++)
        arr[i]= getrand(0,maxValue);
    return arr;
}

void print(int* arr)
{
    printf("%d: ",arr[0]);
    for(int i=1;i<arr[0]+1;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int main()
{
    srand(time(NULL));
    int size = rand() % 10;
    int maxValue = 100;
    int* arr = genRandArray(size, maxValue);
    print(arr);
    free(arr);
}
