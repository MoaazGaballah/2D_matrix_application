#include <stdio.h>
#include <stdlib.h>
#include "matrixOps.h"
int generateRandomNumber(int min, int max)
{
    return ((rand() % (int)(((max) + 1) - (min))) + (min));
}

int *createMatrixWithRange(int row, int column, int range)
{
    // // allocation for 2D matrix
    // int **arr = (int **)malloc(row * sizeof(int *));
    // for (int i = 0; i < row; i++)
    //     *(arr + i) = (int *)malloc(column * sizeof(int));

    // // setting elements randomly for every element of array
    // for (int i = 0; i < row; i++)
    //     for (int j = 0; j < column; j++)
    //         arr[i][j] = generateRandomNumber(0, range);
    // // print matrix
    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < column; j++)
    //         printf("%d\t", arr[i][j]);
    //     printf("\n");
    // }
    int *arr = (int *)malloc(row * column * sizeof(int));
    // setting elements randomly for every element of array
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            *(arr + i * column + j) = generateRandomNumber(0, range);

    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++)
            printf("%d\t", *(arr + i * column + j));
        printf("\n");
    }        
    return arr;
}