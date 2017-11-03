#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calc(int n, int m)
{
    int i, j, x=0, x1, x2=0, x3;
    for (j=1; j<=m; j++)
    {
        x1=cos((j*M_PI)/2);
        x2=x2+x1;
    }
    for (i=1; i<=n; i++)
    {
        x3=i*x2;
        x=x+x3;
    }
    return x;
}

int main(void)
{
    double x;
    int n=3, m=2;
    x=calc(n, m);
    printf("x=%f", x);
    return EXIT_SUCCESS;
}
