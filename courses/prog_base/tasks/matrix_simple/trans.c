#include <stdio.h>
#include <stdlib.h>

void fillRand(int mat[4][4])
{
    int i, j;
    for (i=0; i<4; i++)
    {
        for (j=0; j<4; j++)
        {
            mat[i][j]=(-999)+rand()%1999;
            //printf("%i ", mat[i][j]);
        }
        //printf("\n");
    }
}

void rotateCCW90(int mat[4][4])
{
    int s, s1, r, r1;
    int mat1[4][4];
    for (r=0, r1=0; r<4; r++, r1++)
     {
         for (s=0, s1=0; s<4; s++, s1++)
         {
             mat1[r1][s1]=mat[r][s];
         }
     }
    for (r=0, s1=3; r<4; r++, s1--)
    {
        for (s=0, r1=0; s<4; s++, r1++)
        {
            mat[r][s]=mat1[r1][s1];
            //printf("%i    ", mat[r][s]);
        }
        //printf("\n");
    }

}

void flipH(int mat[4][4])
{
    int r, r1, s, s1;
    int mat1[4][4];
    for (r=0, r1=0; r<4; r++, r1++)
    {
         for (s=0, s1=0; s<4; s++, s1++)
         {
             mat1[r1][s1]=mat[r][s];
         }
    }
    for (r=0, r1=0; r<4; r++, r1++)
    {
        for (s=0, s1=3; s<4; s++, s1--)
        {
            mat[r][s]=mat1[r1][s1];
            //printf("%i  ", mat[r][s]);
        }
        //printf("\n");
    }
}

void transposSide(int mat[4][4])
{
    int s, s1, r, r1;
    int mat1[4][4];
    for (r=0, r1=0; r<4; r++, r1++)
     {
         for (s=0, s1=0; s<4; s++, s1++)
         {
             mat1[r1][s1]=mat[r][s];
         }
     }
    for (r=0, s1=3; r<4; r++, s1--)
    {
        for (s=0, r1=3; s<4; s++, r1--)
        {
            mat[r][s]=mat1[r1][s1];
            //printf("%i    ", mat[r][s]);
        }
        //printf("\n");
    }
}
