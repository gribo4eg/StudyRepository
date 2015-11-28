#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>

void simpleBeauty();
void getSize(int *size, int *fValue, int *lValue);
void fillArray(double arr[], int size, int fValue, int lValue);
void revers(double arr[], int size);
void printArray(double arr[], int size);
void helpCom();
void start();
void errorM();
void null(double arr[], int size);
void shiftNull(double arr[], int size, int kolvo);
void shiftArray(double arr[], int size, int kolvo);
void power(double arr[], int size, int pw);
double firstMin(double arr[], int size, int * minIn);
void transposEl(double arr[], int size);
int negative(double arr[], int size);
double sumEl(double arr[], int size);
void chEl(double arr[], int size, int index, double value);

int main(void)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    srand(time(NULL));
    char command[20];
    int size, fValue, lValue, kolvo, index;
    double element;

    for(;;)
    {
        getSize(&size, &fValue, &lValue);
        getchar();
        if(size<=0 || fValue>lValue)
        {
            errorM();
        }
        else
        {
            break;
        }
        system("cls");
    }
    double arr[size];
    fillArray(arr, size, fValue, lValue);
    for(;;)
    {
        simpleBeauty();
        printArray(arr, size);

        start();
        gets(command);
        SetConsoleTextAttribute (hConsole, 15);
        if(command[0]=='h' && command[1]=='e' && command[2]=='l' && command[3]=='p' && strlen(command)==4)
        {
            helpCom();
        }
        else if(command[0]=='n' && command[1]=='u' && command[2]=='l' && command[3]=='l' && strlen(command)==4)
        {
            null(arr, size);
        }
        else if(command[0]=='r' && command[1]=='e' && command[2]=='v' && command[3]=='e' && command[4]=='r' && command[5]=='s' && command[6]=='e' && strlen(command)==7)
        {
            revers(arr, size);
        }
        else if(command[0]=='s' && command[1]=='h' && command[2]=='i' && command[3]=='f' && command[4]=='t' && command[5]=='N' && strlen(command)==6)
        {
            SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
            printf("How many steps I should to do?\n>>");
            SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
            scanf("%i", &kolvo);
            getchar();
            shiftNull(arr, size, kolvo);
        }
        else if(command[0]=='p' && command[1]=='o' && command[2]=='w' && command[3]=='e' && command[4]=='r' && strlen(command)==5)
        {
            SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
            printf("Choose your number:\n>>");
            SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
            scanf("%i", &kolvo);
            getchar();
            power(arr, size, kolvo);
        }
        else if(command[0]=='s' && command[1]=='h' && command[2]=='i' && command[3]=='f' && command[4]=='t' && strlen(command)==5)
        {
            SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
            printf("How many steps I should to do?\n>>");
            SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
            scanf("%i", &kolvo);
            getchar();
            shiftArray(arr, size, kolvo);
        }
        else if(command[0]=='m' && command[1]=='i' && command[2]=='n' && strlen(command)==3)
        {
            element=firstMin(arr, size, &index);
            SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
            printf("Minimal element is ");
            SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
            printf("%.3f", element);
            SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
            printf(" and has index: ");
            SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
            printf("%i", index);
            getchar();
        }
        else if(command[0]=='t' && command[1]=='r' && command[2]=='a' && command[3]=='n' && command[4]=='s' && command[5]=='p' && command[6]=='o' && command[7]=='s' && strlen(command)==8)
        {
            transposEl(arr, size);
        }
        else if(command[0]=='n' && command[1]=='e' && command[2]=='g' && strlen(command)==3)
        {
            kolvo = negative(arr, size);
            SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
            printf("Amount of negative elements: ");
            SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
            printf("%i", kolvo);
            getchar();
        }
        else if(command[0]=='s' && command[1]=='u' && command[2]=='m' && strlen(command)==3)
        {
            element=sumEl(arr, size);
            SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
            printf("Sum of all elements: ");
            SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
            printf("%.3f", element);
            getchar();
        }
        else if(command[0]=='f' && command[1]=='i' && command[2]=='l' && command[3]=='l' && strlen(command)==4)
        {
            SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
            printf("Choose size of array:");
            SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
            scanf("%i", &size);
            SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
            printf("Choose MIN value of diapason:");
            SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
            scanf("%i", &fValue);
            SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
            printf("Choose MAX value of diapason:");
            SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
            scanf("%i", &lValue);
            fillArray(arr, size, fValue, lValue);
            getchar();
        }
        else if(command[0]=='c' && command[1]=='h' && command[2]=='e' && command[3]=='l' && strlen(command)==4)
        {
            SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
            printf("Choose index, which you want to change:");
            SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
            scanf("%i", &index);
            SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
            printf("Enter value, which you prefer to enter:");
            SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
            scanf("%lf", &element);
            chEl(arr, size, index, element);
            getchar();
        }
        else if(command[0]=='e' && command[1]=='x' && command[2]=='i' && command[3]=='t' && strlen(command)==4)
        {
            break;
        }
        else
        {
            errorM();
        }
        SetConsoleTextAttribute (hConsole, 15);
        system("cls");
    }
    return EXIT_SUCCESS;
}

void getSize(int *size, int *fValue, int *lValue)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = 35;
    pos.Y = 10;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    printf("Choose size of array:");
    SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    scanf("%i", size);

    pos.X = 33;
    pos.Y = 11;
    SetConsoleCursorPosition(hConsole, pos);

    SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    printf("Choose MIN value of diapason:");
    SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    scanf("%i", fValue);

    pos.X = 33;
    pos.Y = 12;
    SetConsoleCursorPosition(hConsole, pos);

    SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    printf("Choose MAX value of diapason:");
    SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    scanf("%i", lValue);
    system("cls");
}

void helpCom()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    printf("\n\n");

    SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    printf("fill\t");
    SetConsoleTextAttribute (hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("/* fill numbers in array, if You choose diapason */\n\n");

    SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    printf("reverse\t");
    SetConsoleTextAttribute (hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("/* just reverse */\n\n");

    SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    printf("transpos");
    SetConsoleTextAttribute (hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("/* last min el. <-> last max el. //it's some kind of magic */\n\n");

    SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    printf("min\t");
    SetConsoleTextAttribute (hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("/* show you the first min element and his index in array */\n\n");

    SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    printf("null\t");
    SetConsoleTextAttribute (hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("/* all elements = 0 */\n\n");

    SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    printf("sum\t");
    SetConsoleTextAttribute (hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("/* show you sum of all elements //become a mathematician */\n\n");

    SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    printf("neg\t");
    SetConsoleTextAttribute (hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("/* show you amount of negative elements */\n\n");

    SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    printf("shiftN\t");
    SetConsoleTextAttribute (hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("/* move your array... but some elements become 0 T_T */\n\n");

    SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    printf("shift\t");
    SetConsoleTextAttribute (hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("/* move your array, without 0 */\n\n");

    SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    printf("power\t");
    SetConsoleTextAttribute (hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("/* brings the elements into a selected pow */\n\n");

    SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    printf("chel\t");
    SetConsoleTextAttribute (hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("/* change value of some element... if You wish ofc */\n\n");

    SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    printf("exit\t");
    SetConsoleTextAttribute (hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("/* just exit */\n\n");

    SetConsoleTextAttribute (hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("press ENTER to continue\n");
    getchar();
}

void simpleBeauty()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int i, j;
    for(i=0; i<=11; i++)
    {
        for(j=0; j<=99; j++)
        {
            COORD pos;
            pos.X = j;
            pos.Y = i;
            SetConsoleCursorPosition(hConsole, pos);
            if((j==0 && (i>=0 && i<=11)) || (j==99 && (i>=0 && i<=11)) || (i==0 && (j>=0 && j<=99)) || (i==11 && (j>=0 && j<=99)))
            {
                SetConsoleTextAttribute (hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                printf("*");
            }
            SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|BACKGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_INTENSITY);
            printf("*");
        }
    }
}

void start()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = 0;
    pos.Y = 12;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute (hConsole, 15);
    printf("What should I do?\n>>");
    SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
}

void errorM()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    COORD pos;
    pos.X = 45;
    pos.Y = 20;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute (hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("ERROR!");
    Sleep(2000);
    SetConsoleTextAttribute (hConsole, 15);
}

void fillArray(double arr[], int size, int fValue, int lValue) //заповнюЇ масив ел-ми в д≥апазон≥ [fValue; lValue]
{
    int i, x, k, first=fValue, last=lValue;
    double r;
    for (i=0; i<size; i++)
    {
        x = rand() % (last - first) + first;
        k = rand() % 100;
        r = (double)k/100;
        arr[i] = x + r;
    }
}

void revers(double arr[], int size)//виводить ел-ти масиву у зворотньому напр€мку
{
    int i, k;
    double tmp;
    for(i=0, k=size-1; i<k; i++, k--)
    {
        tmp=arr[i];
        arr[i]=arr[k];
        arr[k]=tmp;
    }
}

void printArray(double arr[], int size) //виводить масив на екран
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int i;
    COORD pos;
    pos.X = 7;
    pos.Y = 5;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute (hConsole, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_RED);
    for (i=0; i<size; i++)
    {
        printf("%.2f  ", arr[i]);
    }
    SetConsoleTextAttribute (hConsole, 15);
}

void null(double arr[], int size) //обнул€Ї вс≥ ел-ти масиву
{
    int i;
    for(i=0; i<size; i++)
    {
        arr[i]=0;
    }
}

void shiftNull(double arr[], int size, int kolvo)//здвиг прав≥ше на kolvo одиниць, "пуст≥" €чейки-0
{
    int i, j;
    for(j=1; j<=kolvo; j++)
    {
        for(i=size-2; i>=0; i--)
        {
            arr[i+1]=arr[i];

        }
        arr[0]=0;
    }
}

void shiftArray(double arr[], int size, int kolvo) // ÷» Ћ≤„Ќ»… здвиг ел-≥в масиву
{
    int i, j;
    double tmp;
    for(j=1; j<=kolvo; j++)
    {
        tmp=arr[size-1];
        for(i=size-2; i>=0; i--)
        {
            arr[i+1]=arr[i];
        }
        arr[0]=tmp;
    }
}

void power(double arr[], int size, int pw)//п≥дносить вс≥ ел-ти масиву до pw степен€
{
    int i;
    for(i=0; i<size; i++)
    {
        arr[i]=pow(arr[i], pw);
    }
}

double firstMin(double arr[], int size, int * minIn)//м≥н≥мальний ел-нт масиву та його ≥ндекс
{
    int i;
    double res=arr[0];
    *minIn=0;;
    for(i=0; i<size; i++)
    {
        if(res>arr[i])
        {
            res=arr[i];
            *minIn=i;
        }
    }
    return res;
}

void transposEl(double arr[], int size)//м≥н€Ї м≥сц€ми останн≥й найб≥льший ≥ найменший ел-ти
{
    int i, minIndex, maxIndex;
    double minEl=arr[0], maxEl=arr[0], tmp;
    for(i=0; i<size; i++)
    {
        if(minEl>=arr[i])
        {
            minEl=arr[i];
            minIndex=i;
        }
        if(maxEl<=arr[i])
        {
            maxEl=arr[i];
            maxIndex=i;
        }
    }
    tmp=maxEl;
    arr[maxIndex]=minEl;
    arr[minIndex]=tmp;
}

int negative(double arr[], int size)//к≥л-ть в≥д'Їмних ел-≥в масиву
{
    int i, res=0;
    for(i=0; i<size; i++)
    {
        if(arr[i]<0)
        {
            res++;
        }
    }
    return res;
}

double sumEl(double arr[], int size)//сума вс≥х ел-≥в масиву
{
    int i;
    float res=0.0;
    for(i=0; i<size; i++)
    {
        res=res+arr[i];
    }
    return res;
}

void chEl(double arr[], int size, int index, double value)//зам≥н€Ї ел-нт за вказаним значенн€м на вказане значенн€
{
    arr[index]=value;
}
