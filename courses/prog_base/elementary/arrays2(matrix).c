#include <stdio.h>
#include <stdlib.h>

void fillMatrix(int n, int m, int mat[n][m])//1.1) matrix mat[n][m]
{
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            mat[i][j]=rand() % 100 - 50;
        }
    }
}

void printMatrix(int n, int m, int mat[n][m])//1.2) just print matrix mat[n][m]
{
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            printf("%i\t", mat[i][j]);
        }
        puts("");
    }
}

int sum(int n, int m, int mat[n][m])//2) sum of all elements
{
    int i, j, sum=0;
    puts(__func__);
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            sum+=mat[i][j];
        }
    }
    return sum;
}

void sumSandC(int n, int m, int mat[n][m])//3) sum of strings and columns elements
{
    int sum=0, i, j;
    puts(__func__);
    puts("");
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            sum+=mat[i][j];
        }
        printf("Sum of all elements from %i string: %i\n", (i+1), sum);//yeah, i know, talking function >_<
        sum=0;
    }
    puts("");//yeah, i know, talking function >_<
    for(j=0; j<m; j++)
    {
        for(i=0; i<n; i++)
        {
            sum+=mat[i][j];
        }
        printf("Sum of all elements from %i column: %i\n", (j+1), sum);
        sum=0;
    }
}

int mainDiag(int n, int mat[n][n])//4.1) sum= mat[0][0]+mat[1][1]+mat[2][2]+...+mat[n-1][n-1]
{
    int sum=0, i;
    puts(__func__);
    for (i=0; i<n; i++)
    {
        sum+=mat[i][i];
    }
    return sum;
}

int sideDiag(int n, int mat[n][n])//4.2) sum=mat[0][n-1]+mat[1][n-2]+...+mat[n-1][0]
{
    int sum=0, i, j;
    puts(__func__);
    for(i=0, j=n-1; i<n; i++, j--)
    {
        sum+=mat[i][j];
    }
    return sum;
}

int sumUnder(int n, int mat[n][n])//5) sum of elements under main diag.
{
    int sum=0, i, j;
    puts(__func__);
    for(i=1; i<n; i++)
    {
        for(j=0; j<i; j++)
        {
            sum+=mat[i][j];
        }
    }
    return sum;
}

int max(int n, int m, int mat[n][m])//6) max element in matrix
{
    int res=mat[0][0], i, j;
    puts(__func__);
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(mat[i][j]>res)
            {
                res=mat[i][j];
            }
        }
    }
    return res;
}

int min(int n, int m, int mat[n][m], int *indexI, int *indexJ)//7) show you min element of matrix and his indexes
{
    int res=mat[0][0], i, j;
    *indexI=0;
    *indexJ=0;
    puts(__func__);
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(res>mat[i][j])
            {
                res=mat[i][j];
                *indexI=i;
                *indexJ=j;
            }
        }
    }
    return res;
}

int main(void)
{
    srand(time(NULL));
    int n, m, indexI, indexJ, tmp;
    printf("Enter the number of strings(will be used for square matrix NxN):");
    scanf("%i", &n);
    puts("Enter the number of columns:");
    scanf("%i", &m);
    puts("");
    int mat[n][m];
    fillMatrix(n, m, mat);
    printMatrix(n, m, mat);
    puts("");
    tmp=sum(n, m, mat);
    printf("Sum of all elements: %i\n", tmp);
    tmp=max(n, m, mat);
    printf("Maximal element in matrix: %i\n", tmp);
    tmp=min(n, m, mat, &indexI, &indexJ);
    printf("Minimal element in matrix: mat[%i][%i]=%i\n\n", indexI, indexJ, tmp);
    sumSandC(n, m, mat);
    puts("Square matrix:\n");
    fillMatrix(n, n, mat);
    printMatrix(n, n, mat);
    puts("");
    tmp=mainDiag(n, mat);
    printf("Sum of the elements on the main diagonal: %i\n", tmp);
    tmp=sideDiag(n, mat);
    printf("Sum of the elements on the side diagonal: %i\n", tmp);
    tmp=sumUnder(n, mat);
    printf("Sum of the elements under the main diagonal: %i\n", tmp);
    return EXIT_SUCCESS;
}
