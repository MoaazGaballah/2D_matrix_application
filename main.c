#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "matrixOps.h"

void clear()
{
    const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
    write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 10);
}
char *inputMethod()
{
    char *user_input = malloc(sizeof(char) * 100);
    fgets(user_input, 100, stdin);
    return user_input;
}
char *getLineFromUser()
{
    //clear();
    printf("1. Run Application\n");
    printf("2. Create Matrix\n");
    printf("3. Direction\n");
    printf("4. Step number\n");
    printf("5. Exit\n");
    char *user_input = inputMethod();
    // int len = sizeOfString(user_input);
    // printf("Length : %d\n", strlen(user_input));
    return user_input;
}
int isNumber(char *str)
{
    // printf("this is strlen(str) : %d\n", strlen(str));
    for (int i = 0; i < strlen(str); i++)
    {
        // printf("This is str[i] : %c\n",
        //        str[i]);
        if (isdigit(str[i]) == 0)
            return 0;
    }

    return 1;
}

int main(int argc, char *argv[])
{
    
    int countinue = 1;
    char *runApplication = "1";
    char *createMatrix = "2";
    char *direction = "3";
    char *stepNumber = "4";
    char *exit = "5";

    // these are variables will be used to get recent values of previous operations
    int row = 0;
    int column = 0;
    int direct = 0;
    int range = 0;
    int step = 0;

    // this is the matrix remained from recent steps
    int *matrix = malloc(sizeof(int) * 500);

    while (countinue)
    {
        // get a main line from user
        char *exitTokenLine = getLineFromUser();

        // copy that line again because strtok() affect string
        char *runApplicationTokenLine = malloc(sizeof(char) * 10);
        memcpy(runApplicationTokenLine, exitTokenLine, strlen(exitTokenLine));

        // copy that line again because strtok() affect string
        char *createMatrixTokenLine = malloc(sizeof(char) * 10);
        memcpy(createMatrixTokenLine, exitTokenLine, strlen(exitTokenLine));

        // copy that line again because strtok() affect string
        char *directionTokenLine = malloc(sizeof(char) * 10);
        memcpy(directionTokenLine, exitTokenLine, strlen(exitTokenLine));

        // copy that line again because strtok() affect string
        char *stepNumberTokenLine = malloc(sizeof(char) * 10);
        memcpy(stepNumberTokenLine, exitTokenLine, strlen(exitTokenLine));

        char s[1] = " ";
        char *exitToken, *runApplicationToken, *createMatrixToken, *directionToken, *stepNumberToken;

        // get the first token 
        exitToken = strtok(exitTokenLine, s);
        runApplicationToken = exitToken;
        createMatrixToken = exitToken;
        directionToken = exitToken;
        stepNumberToken = exitToken;

        if (strcasecmp(exitToken, exit) == 0 || strcasecmp(exitToken, exit) == 10)
        {
            // printf("geldi : %s\n", token);
            countinue = 0;

            // free all memory malloc
            free(matrix);
            free(exitTokenLine);
            free(runApplicationTokenLine);
            free(createMatrixTokenLine);
            free(directionTokenLine);
            free(stepNumberTokenLine);
            break;
        }
        else if (strcasecmp(runApplicationToken, runApplication) == 0 || strcasecmp(runApplicationToken, runApplication) == 10)
        {
            // free matrix allocation memory to create a new one
            char *inputForRunApplication;
        err:
            inputForRunApplication = inputMethod();

            // split user's input line according to this space
            char space[2] = " ";

            // get the first number from input line (row)
            char *rowAsString = strtok(inputForRunApplication, space);
            // printf("this is isNumber(row) : %d\n", isNumber(rowAsString));
            if (isNumber(rowAsString) == 0)
            {
                clear();
                printf("Please enter a vaild row number !\n");
                printf("Try again \n");
                // free(matrix);
                // free(inputForRunApplication);
                free(exitTokenLine);
                free(runApplicationToken);
                free(createMatrixTokenLine);
                free(directionTokenLine);
                free(stepNumberTokenLine);
                free(inputForRunApplication);
                // goto err;
                continue;
            }

            row = atoi(rowAsString);
            // printf("This is row : %d\n", row);

            // get the second number from input line (column)
            char *columnAsString = strtok(NULL, space);
            // printf("this is isNumber(columnAsString) : %d\n", isNumber(columnAsString));
            if (isNumber(columnAsString) == 0)
            {
                clear();
                printf("Please enter a vaild column number !\n");
                free(exitTokenLine);
                free(runApplicationToken);
                free(createMatrixTokenLine);
                free(directionTokenLine);
                free(stepNumberTokenLine);
                continue;
            }
            column = atoi(columnAsString);
            // printf("This is column : %d\n", column);

            // get the third number from input line (direction)
            char *directionAsString = strtok(NULL, space);
            // printf("this is isNumber(directionAsString) : %d\n", isNumber(directionAsString));
            // printf("This is direction : %d\n", atoi(directionAsString));
            // printf("This is strcasecmp(directionAsString, '1') : %d\n", strcasecmp(directionAsString, "1"));
            // printf("This is strcasecmp(directionAsString, '-1') : %d\n", strcasecmp(directionAsString, "-1"));
            if (strcasecmp(directionAsString, "1") != 0 && strcasecmp(directionAsString, "-1") != 0)
            {
                clear();
                printf("Please enter a vaild direction (clockwise : -1 and counter-clockwise : 1)\n");
                free(exitTokenLine);
                free(runApplicationToken);
                free(createMatrixTokenLine);
                free(directionTokenLine);
                free(stepNumberTokenLine);
                continue;
            }

            direct = atoi(directionAsString);
            // printf("This is direct : %d\n", direct);

            // get the third number from input line (range)
            char *rangeAsString = strtok(NULL, space);
            // printf("this is isNumber(rangeAsString) : %d\n", isNumber(rangeAsString));

            if (isNumber(rangeAsString) == 0)
            {
                clear();
                printf("Please enter a vaild range number !\n");
                free(exitTokenLine);
                free(runApplicationToken);
                free(createMatrixTokenLine);
                free(directionTokenLine);
                free(stepNumberTokenLine);
                continue;
            }
            range = atoi(rangeAsString);
            // printf("This is range : %d\n", range);

            // get the third number from input line (range)
            char *stepNumberAsString = strtok(NULL, space);
            // printf("this is isNumber(rangeAsString) : %d\n", isNumber(rangeAsString));

            // this instruction set the last element in rangeAsString to NULL (0)
            stepNumberAsString[strlen(stepNumberAsString) - 1] = 0;
            if (isNumber(stepNumberAsString) == 0)
            {
                clear();
                printf("Please enter a vaild step number !\n");
                free(exitTokenLine);
                free(runApplicationToken);
                free(createMatrixTokenLine);
                free(directionTokenLine);
                free(stepNumberTokenLine);
                continue;
            }
            step = atoi(stepNumberAsString);
            // printf("This is step : %d\n", step);

            matrix = createMatrixWithRange(row, column, range);
            printf("-------------------------------------------------------------------------\n");
            // for (int i = 0; i < row; i++)
            // {
            //     for (int j = 0; j < column; j++)
            //         printf("%d\t", *(matrix + i * column + j));
            //     printf("\n");
            // }
            rotateMatrix(matrix, row, column, direct);

            // free all memory malloc
            // free(exitTokenLine);
            // free(runApplicationToken);
            // free(createMatrixTokenLine);
            // free(directionTokenLine);
            // free(stepNumberTokenLine);
            free(inputForRunApplication);
            continue;
        }
        else if (strcasecmp(createMatrixToken, createMatrix) == 0 || strcasecmp(createMatrixToken, createMatrix) == 10)
        {
            char *inputForCreateMatrix = inputMethod();
            // printf("this is inputForCreateMatrix : %s\n", inputForCreateMatrix);

            // split user's input line according to this space
            char space[2] = " ";

            // get the first number from input line (row)
            char *rowAsString = strtok(inputForCreateMatrix, space);
            // printf("this is isNumber(row) : %d\n", isNumber(rowAsString));
            if (isNumber(rowAsString) == 0)
            {
                clear();
                printf("Please enter a vaild row number !\n");
                free(exitTokenLine);
                free(runApplicationToken);
                free(createMatrixTokenLine);
                free(directionTokenLine);
                free(stepNumberTokenLine);
                continue;
            }

            row = atoi(rowAsString);
            // printf("This is row : %d\n", row);

            // get the second number from input line (column)
            char *columnAsString = strtok(NULL, space);
            // printf("this is isNumber(columnAsString) : %d\n", isNumber(columnAsString));
            if (isNumber(columnAsString) == 0)
            {
                clear();
                printf("Please enter a vaild column number !\n");
                free(exitTokenLine);
                free(runApplicationToken);
                free(createMatrixTokenLine);
                free(directionTokenLine);
                free(stepNumberTokenLine);
                continue;
            }
            column = atoi(columnAsString);
            // printf("This is column : %d\n", column);

            // get the third number from input line (range)
            char *rangeAsString = strtok(NULL, space);
            // printf("this is isNumber(rangeAsString) : %d\n", isNumber(rangeAsString));

            // this instruction set the last element in rangeAsString to NULL (0)
            rangeAsString[strlen(rangeAsString) - 1] = 0;
            if (isNumber(rangeAsString) == 0)
            {
                clear();
                printf("Please enter a vaild range number !\n");
                free(exitTokenLine);
                free(runApplicationToken);
                free(createMatrixTokenLine);
                free(directionTokenLine);
                free(stepNumberTokenLine);
                continue;
            }
            range = atoi(rangeAsString);
            // printf("This is range : %d\n", range);

            matrix = createMatrixWithRange(row, column, range);
            printf("-------------------------------------------------------------------------\n");
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                    printf("%d\t", *(matrix + i * column + j));
                printf("\n");
            }

            // free all memory malloc
            free(exitTokenLine);
            free(runApplicationToken);
            free(createMatrixTokenLine);
            free(directionTokenLine);
            free(stepNumberTokenLine);
            continue;
        }
        else if (strcasecmp(directionToken, direction) == 0 || strcasecmp(directionToken, direction) == 10)
        {
            printf("I am here in direction\n");

            // free all memory malloc
            free(exitTokenLine);
            free(runApplicationToken);
            free(createMatrixTokenLine);
            free(directionTokenLine);
            free(stepNumberTokenLine);
            continue;
        }
        else if (strcasecmp(stepNumberToken, stepNumber) == 0 || strcasecmp(stepNumberToken, stepNumber) == 10)
        {
            printf("I am here in stepNumber\n");

            // free all memory malloc
            free(exitTokenLine);
            free(runApplicationToken);
            free(createMatrixTokenLine);
            free(directionTokenLine);
            free(stepNumberTokenLine);
            continue;
        }
        else
        {
            clear();
            printf("Please choose a choice from menu !\n");
            free(exitTokenLine);
            free(runApplicationToken);
            free(createMatrixTokenLine);
            free(directionTokenLine);
            free(stepNumberTokenLine);
            continue;
        }
    }
    // free matrix allocation
    free(matrix);
    
//    printf("This is generateRandomNumber : %d\n", generateRandomNumber(0, 9));
}