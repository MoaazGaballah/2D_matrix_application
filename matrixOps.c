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

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            printf("%d\t", *(arr + i * column + j));
        printf("\n");
    }
    return arr;
}

int *rotateMatrix(int *matrix, int row, int column, int direction)
{
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

        // rotate up line
        for (int j = 0; j < column; j++)
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

        // rotate left column (column - 1 because the last element in the kolumn is rotated with the down row)
        char *leftColumnTempValues = malloc(sizeof(char) * row);
        for (int j = 0; j < column; j++)
            *(leftColumnTempValues + j) = *(matrix + column * j);
        // rotation for the first element in the column
        *(leftColumnTempValues) = firstElementColumn;
        for (int j = 0 ; j < column - 1; j++)
            *(matrix + column * j + column) = *(leftColumnTempValues + j);
            // printf("%d\t", *(leftColumnTempValues + j));
        // rotate right column
        char *rightColumnTempValues = malloc(sizeof(char) * row);
        for (int j = 0; j < column; j++)
            // *(rightColumnTempValues + j) = *(matrix + column * j);
            printf("%d \t", *(matrix + (column - 1)) * j + j));
    }
    printf("\n");
    printf("---------------------------------------------------------------------\n");
    // else
    // {
    //     for (int i = 0; i < row; i++)
    //         for (int j = 0; j < column; j++)
    //             *(matrix + i * column + j) = ;
    // }

    // end of rotation
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            printf("%d\t", *(matrix + i * column + j));
        printf("\n");
    }
}

// void rotatematrix(int m, int n, int mat[R][C])
// {
//     int row = 0, col = 0;
//     int prev, curr;

//     /*
//        row - Staring row index
//        m - ending row index
//        col - starting column index
//        n - ending column index
//        i - iterator
//     */
//     while (row < m && col < n)
//     {

//         if (row + 1 == m || col + 1 == n)
//             break;

//         // Store the first element of next row, this
//         // element will replace first element of current
//         // row
//         prev = mat[row + 1][col];

//         /* Move elements of first row from the remaining rows */
//         for (int i = col; i < n; i++)
//         {
//             curr = mat[row][i];
//             mat[row][i] = prev;
//             prev = curr;
//         }
//         row++;

//         /* Move elements of last column from the remaining columns */
//         for (int i = row; i < m; i++)
//         {
//             curr = mat[i][n - 1];
//             mat[i][n - 1] = prev;
//             prev = curr;
//         }
//         n--;

//         /* Move elements of last row from the remaining rows */
//         if (row < m)
//         {
//             for (int i = n - 1; i >= col; i--)
//             {
//                 curr = mat[m - 1][i];
//                 mat[m - 1][i] = prev;
//                 prev = curr;
//             }
//         }
//         m--;

//         /* Move elements of first column from the remaining rows */
//         if (col < n)
//         {
//             for (int i = m - 1; i >= row; i--)
//             {
//                 curr = mat[i][col];
//                 mat[i][col] = prev;
//                 prev = curr;
//             }
//         }
//         col++;
//     }

//     // Print rotated matrix
//     for (int i = 0; i < R; i++)
//     {
//         for (int j = 0; j < C; j++)
//             printf("%d\t", mat[i][j]);
//         printf("\n");
//     }
// }
