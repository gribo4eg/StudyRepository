#include <stdio.h>
#include <stdlib.h>

void fillRand(int mat[4][4])
{
    int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p;
    srand(time(NULL));
    mat[0][0]=a= -999 + rand() % 999;
    mat[0][1]=b= -999 + rand() % 999;
    mat[0][2]=c= -999 + rand() % 999;
    mat[0][3]=d= -999 + rand() % 999;
    mat[1][0]=e= -999 + rand() % 999;
    mat[1][1]=f= -999 + rand() % 999;
    mat[1][2]=g= -999 + rand() % 999;
    mat[1][3]=h= -999 + rand() % 999;
    mat[2][0]=i= -999 + rand() % 999;
    mat[2][1]=j= -999 + rand() % 999;
    mat[2][2]=k= -999 + rand() % 999;
    mat[2][3]=l= -999 + rand() % 999;
    mat[3][0]=m= -999 + rand() % 999;
    mat[3][1]=n= -999 + rand() % 999;
    mat[3][2]=o= -999 + rand() % 999;
    mat[3][3]=p= -999 + rand() % 999;
}

void rotateCCW90(int mat[4][4])
{
    int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p;
    mat[0][0]=a;
    mat[0][1]=b;
    mat[0][2]=c;
    mat[0][3]=d;
    mat[1][0]=e;
    mat[1][1]=f;
    mat[1][2]=g;
    mat[1][3]=h;
    mat[2][0]=i;
    mat[2][1]=j;
    mat[2][2]=k;
    mat[2][3]=l;
    mat[3][0]=m;
    mat[3][1]=n;
    mat[3][2]=o;
    mat[3][3]=p;


    mat[3][0]=a;
    mat[2][0]=b;
    mat[1][0]=c;
    mat[0][0]=d;
    mat[3][1]=e;
    mat[2][1]=f;
    mat[1][1]=g;
    mat[0][1]=h;
    mat[3][2]=i;
    mat[2][2]=j;
    mat[1][2]=k;
    mat[0][2]=l;
    mat[3][3]=m;
    mat[2][3]=n;
    mat[1][3]=o;
    mat[0][3]=p;
}

void flipH(int mat[4][4])
{
    int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p;
    mat[0][0]=a;
    mat[0][1]=b;
    mat[0][2]=c;
    mat[0][3]=d;
    mat[1][0]=e;
    mat[1][1]=f;
    mat[1][2]=g;
    mat[1][3]=h;
    mat[2][0]=i;
    mat[2][1]=j;
    mat[2][2]=k;
    mat[2][3]=l;
    mat[3][0]=m;
    mat[3][1]=n;
    mat[3][2]=o;
    mat[3][3]=p;

    mat[3][0]=p;
    mat[2][0]=l;
    mat[1][0]=h;
    mat[0][0]=d;
    mat[3][1]=o;
    mat[2][1]=k;
    mat[1][1]=g;
    mat[0][1]=c;
    mat[3][2]=n;
    mat[2][2]=j;
    mat[1][2]=f;
    mat[0][2]=b;
    mat[3][3]=m;
    mat[2][3]=i;
    mat[1][3]=e;
    mat[0][3]=a;
}

void transposSide(int mat[4][4])
{
    int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p;
    mat[0][0]=a;
    mat[0][1]=b;
    mat[0][2]=c;
    mat[0][3]=d;
    mat[1][0]=e;
    mat[1][1]=f;
    mat[1][2]=g;
    mat[1][3]=h;
    mat[2][0]=i;
    mat[2][1]=j;
    mat[2][2]=k;
    mat[2][3]=l;
    mat[3][0]=m;
    mat[3][1]=n;
    mat[3][2]=o;
    mat[3][3]=p;

    mat[3][0]=m;
    mat[2][0]=n;
    mat[1][0]=o;
    mat[0][0]=p;
    mat[3][1]=i;
    mat[2][1]=j;
    mat[1][1]=k;
    mat[0][1]=l;
    mat[3][2]=e;
    mat[2][2]=f;
    mat[1][2]=g;
    mat[0][2]=h;
    mat[3][3]=a;
    mat[2][3]=b;
    mat[1][3]=c;
    mat[0][3]=d;
}
