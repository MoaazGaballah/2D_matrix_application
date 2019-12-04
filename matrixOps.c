#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
    srand(time(NULL));
    int *arr = (int *)malloc(row * column * sizeof(int));
    // setting elements randomly for every element of array
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            *(arr + i * column + j) = generateRandomNumber(0, range);

    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < column; j++)
    //         printf("%d\t", *(arr + i * column + j));
    //     printf("\n");
    // }
    return arr;
}

int *rotateMatrix(int *matrix, int row, int column, int direction)
{
    if (row == 1)
    {
        return matrix;
    }
    else if (column == 1)
    {
        return matrix;
    }

    int leftUpTemp = *(matrix);                        // correct (0)
    int leftDownTemp = *(matrix + (row - 1) * column); // correct (90)
    // printf("%d\n",(row - 1) * column  );
    int rightUptemp = *(matrix + column - 1); // coorect (9)
    // printf("%d\n", column - 1 );
    int rightDownTemp = *(matrix + (row - 1) * column + column - 1);
    // printf("%d\n",  (row - 1) * column + column -1); (99)

    // printf("this is leftUpTemp : %d\n", leftUpTemp);
    // printf("this is leftDownTemp : %d\n", leftDownTemp);
    // printf("this is rightUptemp : %d\n", rightUptemp);
    // printf("this is rightDownTemp : %d\n", rightDownTemp);
    
    if (direction == 1)
    {
        // get the first element in temp to rotate it in the left column
        int firstElementColumn = *matrix;

        // copy the right column from original matrix
        char *rightColumnTempValues = malloc(sizeof(char) * row);
        for (int j = 0; j < row; j++)
            *(rightColumnTempValues + j) = *(matrix + column * j + column - 1);
        // printf("%d \t", *(matrix + column * j + column - 1));

        // rotate up line
        for (int j = 0; j < column - 1; j++)
            *(matrix + j) = *(matrix + j + 1);

        /*
        // rotate last element in up line (last element in the next line)
        *(matrix + column - 1) = *(matrix + column * 2 - 1);
        */

        // rotate the down line
        char *downLineTempValues = malloc(sizeof(char) * column);
        for (int j = 0; j < column; j++)
            *(downLineTempValues + j) = *(matrix + (row - 1) * column + j);
        for (int j = 0; j < column; j++)
            //     // *(matrix + (row - 1) * j) = *(matrix + (row - 1) * j - 1);
            *(matrix + (row - 1) * column + j + 1) = *(downLineTempValues + j);
        // printf("%d \t", *(downLineTempValues + j));

        /*
        // rotate the first element in down line
        *(matrix + (row - 1) * column) = *(matrix + (row - 2) * column);
        */

        // rotate left column (row - 1 because the last element in the kolumn is rotated with the down row)
        char *leftColumnTempValues = malloc(sizeof(char) * row);
        for (int j = 0; j < row; j++)
            *(leftColumnTempValues + j) = *(matrix + column * j);
        // rotation for the first element in the column
        *(leftColumnTempValues) = firstElementColumn;
        for (int j = 0; j < row - 1; j++)
            *(matrix + column * j + column) = *(leftColumnTempValues + j);
        // printf("%d\t", *(leftColumnTempValues + j));

        // rotate right column
        for (int j = 0; j < row - 1; j++)
            *(matrix + column * j + column - 1) = *(rightColumnTempValues + j + 1);
    } 
    

    if (direction == -1)
    {
        // copy up line
        char *upLineTempValues = malloc(sizeof(char) * column);
        for (int j = 0; j < column; j++)
            *(upLineTempValues + j) = *(matrix + j);
            // printf("%d\t", *(matrix + j));
        
        // copy right column
        char *rightColumneTempValues = malloc(sizeof(char) * column);
        for (int j = 0; j < row; j++)
            *(rightColumneTempValues + j) = *(matrix + column * j + column - 1);
            // printf("%d\t", *(matrix + column * j + column - 1));

        // copy left column
        char *leftColumnTempValues = malloc(sizeof(char) * column);
        for (int j = 0; j < row; j++)
            *(leftColumnTempValues + j) = *(matrix + column * j);
            // printf("%d\t", *(matrix + column * j));

        // rotate up line
        for (int j = 0; j < column; j++)
            *(matrix + j) = *(upLineTempValues + j - 1);

        // rotate down line
        for (int j = 0; j < column; j++)
            *(matrix + (row - 1) * column + j) = *(matrix + (row - 1) * column + j + 1);
        
        // rotate right column
        for (int j = 1; j < row; j++)
            *(matrix + column * j + column - 1) = *(rightColumneTempValues + j - 1);
        
        // rotate left column
        for (int j = 0; j < row - 1; j++)
            *(matrix + column * j) = *(leftColumnTempValues + j + 1);
    }

    // printf("\n");
    // printf("-------------------------------------------------------------------------\n");
    // else
    // {
    //     for (int i = 0; i < row; i++)
    //         for (int j = 0; j < column; j++)
    //             *(matrix + i * column + j) = ;
    // }

    // end of rotation
    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < column; j++)
    //         printf("%d\t", *(matrix + i * column + j));
    //     printf("\n");
    // }
    return matrix;
}