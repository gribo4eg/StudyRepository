#include <stdlib.h>
#include <stdio.h>

void fillRand1(int arr[], int size)
{
    int i;
    for (i=0; i<size; i++)
    {
        arr[i]=rand()%99+1;
    }
}

int checkRand1(int arr[], int size)
{
    int i, check;
    for (i=0; i<size; i++)
    {
        if (arr[i]>=1 && arr[i]<=99)
        {
            check=1;
        }
        else
        {
            check=0;
            break;
        }
    }
    return check;
}

float meanValue(int arr[], int size)
{
    float ser;
    int i, sum=0;
    for (i=0; i<size; i++)
    {
        sum=sum+arr[i];
    }
    ser=(float)sum/(float)size;
    return ser;
}

int minIndex(int arr[], int size)
{
    int index, i, k;
    k=arr[0];
    index=0;
    for (i=0; i<size; i++)
    {
        if(k>arr[i])
        {
            k=arr[i];
            index=i;
        }
    }
    return index;
}

int maxOccurance(int arr[], int size)
{
    int max, i, j, n=0, m=0, value=0;
    for (j=0; j<size; j++)
    {
        for (i=0; i<size; i++)
        {
            if (arr[j]==arr[i] && j!=i)
            {
                n++;
                max=arr[j];
            }
            if (max>value && n>m)
            {
                m=n;
                value=max;
                goto label;
            }
            value=max;
            label: continue;
        }
    }
    return value;
}

int diff(int arr1[], int arr2[], int res[], int size)
{
    int i, check;
    for (i=0; i<size; i++)
    {
        res[i]=arr1[i]-arr2[i];
        if (res[i]==0)
        {
            check=1;
        }
        else
        {
            check=0;
            break;
        }
    }
    return check;
}

void dive(int arr1[], int arr2[], int res[], int size)
{
    int i;
    for (i=0; i<size; i++)
    {
        res[i]=arr1[i]/arr2[i];
    }
}

int lteq(int arr1[], int arr2[], int size)
{
    int i, res;
    for (i=0; i<size; i++)
    {
        if (arr1[i]<=arr2[i])
        {
            res=1;
        }
        else
        {
            res=0;
            break;
        }
    }
    return res;
}

void land(int arr1[], int arr2[], int res[], int size)
{
    int i;
    for (i=0; i<size; i++)
    {
        arr1[i]=rand()%2;
    }
    for (i=0; i<size; i++)
    {
        arr2[i]=rand()%2;
    }
    for (i=0; i<size; i++)
    {
        if (arr1[i]==1 && arr2[i]==1)
        {
            res[i]=1;
        }
        else
        {
            res[i]=0;
        }
    }
}


int main(void)
{
    srand(time(NULL));
    int size=10, check, index, max, check2, ltq;
    float ser;
    int i, arr[size], arr1[size], arr2[size], res[size];
    fillRand1(arr, size);
    printf("===ARRAY===\n");
    for (i=0; i<size; i++)
    {
        printf("%i ", arr[i]);
    }
    puts("");
    check=checkRand1(arr, size);
    printf("check=%i\n ", check);
    ser=meanValue(arr, size);
    printf("mean Value=%.2f\n ", ser);
    index=minIndex(arr, size);
    printf("min Index=%i\n ", index);
    max=maxOccurance(arr, size);
    printf("max Occurance=%i\n ", max);
    fillRand1(arr1, size);
    for (i=0; i<size; i++)
    {
        printf("%i ", arr1[i]);
    }
    puts("");
    fillRand1(arr2, size);
    for (i=0; i<size; i++)
    {
        printf("%i ", arr2[i]);
    }
    puts("");
    check2=diff(arr1, arr2, res, size);
    printf("diff check=%i\n ", check2);
    dive(arr1, arr2, res, size);
    for (i=0; i<size; i++)
    {
        printf("%i ", res[i]);
    }
    puts("");
    ltq=lteq(arr1, arr2, size);
    printf("lteq=%i\n ", ltq);
    land(arr1, arr2, res, size);
    for (i=0; i<size; i++)
    {
        printf("%i ", arr1[i]);
    }
    puts("");
    for (i=0; i<size; i++)
    {
        printf("%i ", arr2[i]);
    }
    puts("");
    for (i=0; i<size; i++)
    {
        printf("%i ", res[i]);
    }
    puts("");
    return EXIT_SUCCESS;
}

