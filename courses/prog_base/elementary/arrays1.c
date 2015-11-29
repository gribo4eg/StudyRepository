#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fillAr(int arr[], int size, int fValue, int lValue);
void difNext(int arr[], int size);
void sumNext(int arr[], int size);
void posEl(int arr[], int size);
void chneg(int arr[], int size);
int sumneg(int arr[], int size);
void printAr(int arr[], int size);
void chel(int arr[], int size);
void kfunc(int arr[], int size, int kol);

int main(void)
{
    srand(time(NULL));
    int size, fValue, lValue, k;
    printf("vvedit:1) rozmir 2)diapazon chisel massivu 3) bukvu K z umovi:");
    scanf("%i %i %i %i", &size, &fValue, &lValue, &k);
    int arr[size];
    puts("");
    fillAr(arr, size, fValue, lValue);
    printAr(arr, size);
    puts("");
    kfunc(arr, size, k);
    printAr(arr, size);
    puts("");
    chel(arr, size);
    printAr(arr, size);
    puts("");
    printf("Sum of negative elements=%i", sumneg(arr, size));
    puts("");
    posEl(arr, size);
    puts("");
    difNext(arr, size);
    printAr(arr, size);
    puts("");
    sumNext(arr, size);
    printAr(arr, size);
    puts("");
    chneg(arr, size);
    printAr(arr, size);
    puts("");
    return EXIT_SUCCESS;
}

void kfunc(int arr[], int size, int kol)//9) change first k elements with last k
{
    int i, m, tmp;
    puts(__func__);
    for(i=0, m=size-1; i<kol; i++, m--)
    {
        tmp=arr[m];
        arr[m]=arr[i];
        arr[i]=tmp;
    }
}

void chel(int arr[], int size)//8) lastMin <-> lastMax
{
    int i, tmp, min, max, minindex, maxindex;
    min=arr[0]; max=min;
    puts(__func__);
    for(i=0; i<size; i++)
    {
        if(min>=arr[i])
        {
            min=arr[i];
            minindex=i;
        }
        if(max<=arr[i])
        {
            max=arr[i];
            maxindex=i;
        }
    }
    tmp=max;
    arr[maxindex]=min;
    arr[minindex]=tmp;
}

void difNext(int arr[], int size)//7) arr[i]=arr[i]-arr[i+1], arr[size-1]=0
{
    int i;
    puts(__func__);
    for(i=0; i<size; i++)
    {
        if(i==size-1)
        {
            arr[size-1]=0;
            break;
        }
        arr[i]=arr[i]-arr[i+1];// arr[i]-=arr[i+1] xD
    }
}

void sumNext(int arr[], int size)//6) arr[i]=arr[i+1]+arr[i+2]+...+arr[size-1] like matan x_x
{
    int i, k, sum;
    puts(__func__);
    for(i=0; i<size-1; i++)
    {
        sum=0;
        for(k=size-1; k>i; k--)
        {
            sum=sum+arr[k];
        }
        arr[i]=sum;
    }
}

void posEl(int arr[], int size)//5) show you all elements, which >0
{
    int i;
    puts(__func__);
    for(i=0; i<size; i++)
    {
        if(arr[i]>0)
        {
            printf("%i,\t", arr[i]);
        }
    }
}

void chneg(int arr[], int size)//4) all negative elements become 0
{
    puts(__func__);
    int i;
    for(i=0; i<size; i++)
    {
        if(arr[i]<0)
        {
            arr[i]=0;
        }
    }
}

int sumneg(int arr[], int size)//3) sum of negative elements
{
    puts(__func__);
    int i, res=0;
    for(i=0; i<size; i++)
    {
        if(arr[i]<0)
        {
            res+=arr[i];
        }
    }
    return res;
}

void fillAr(int arr[], int size, int fValue, int lValue) //1) put in arr elements [fValue; lValue]
{
    int i, first=fValue, last=lValue;
    for (i=0; i<size; i++)
    {
        arr[i]=rand() % (last-first) + first;
    }
}

void printAr(int arr[], int size) //2) print array
{
    int i;
    for (i=0; i<size; i++)
    {
        if(i==size-1)
        {
            printf("%i", arr[i]);
        }
        else
        {
            printf("%i,\t", arr[i]);
        }
    }
}
