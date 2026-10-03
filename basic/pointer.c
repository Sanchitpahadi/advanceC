#include<stdio.h>
#include<stdlib.h>

int main()
{
    const int * cptr;

    int * const * ipcptr;

    int arr[4] = {1,2,3,4};

    int * parr =(int *) malloc( 4 * sizeof(int)); // pointer with the size of 4 like 
    parr = arr;

    for(int i ; i < 4;i++)
    {
        printf("%d \n",parr[i]); // printed whats inside like string *
    }
    return 0;
}