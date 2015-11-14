#include <stdio.h>
#include <stdlib.h>

int run(int moves[], int movesLen, int res[], int resLen)
{
    enum st{a0=0, a1, a2, a3};
    int operation[4][104], states[4][104];
    int i, k=0, op, move=0, input, n=0;

    /*
    pop=111
    continue=222
    repeat=333
    break=444
    */

    operation[a0][4]=5;
    operation[a0][8]=111;
    operation[a0][13]=444;
    operation[a0][103]=551;

    operation[a1][4]=444;
    operation[a1][8]=111;
    operation[a1][13]=552;
    operation[a1][103]=333;

    operation[a2][4]=222;
    operation[a2][8]=555;
    operation[a2][13]=444;
    operation[a2][103]=550;

    operation[a3][4]=444;
    operation[a3][8]=553;
    operation[a3][13]=444;
    operation[a3][103]=444;

    states[a0][4]=0;
    states[a0][8]=1;
    states[a0][103]=2;

    states[a1][8]=2;
    states[a1][13]=1;
    states[a1][103]=2;

    states[a2][4]=3;
    states[a2][8]=3;
    states[a2][103]=1;

    states[a3][8]=0;

    for (i=0; i<movesLen; i++)
    {
        input=moves[i];
        op=operation[move][input];
        if (input!=4 && input!=103 && input!=13 && input!=8)
        {
            goto label;
        }
        switch(op)
        {
        case 5:     res[k]=op; move=states[move][input]; break;
        case 551:   res[k]=op; move=states[move][input]; break;
        case 552:   res[k]=op; move=states[move][input]; break;
        case 555:   res[k]=op; move=states[move][input]; break;
        case 550:   res[k]=op; move=states[move][input]; break;
        case 553:   res[k]=op; move=states[move][input]; break;
        case 111:

                if(k==0 && res[k]==0)
                {
                    goto label;
                }
                else
                {
                    res[k-1]=0;
                    k--;
                    move=states[move][input];
                }
                break;

        case 222:   move=states[move][input]; break;
        case 333:   move=states[move][input]; i--; break;
        default:    goto label;
        }
        k++;
    }
    label:
            for(i=0; i<resLen; i++)
            {
                if (res[i]!=0)
                {
                    n++;
                    continue;
                }
                else
                {
                    res[i]=0;
                }
            }
            return n;
}

int main(void)
{
    int movesLen=4, resLen=4, i, n;
    int moves[4]={103, 8, 0, 4};
    int res[4]={0};
    n=run(moves, movesLen, res, resLen);
    for (i=0; i<resLen; i++)
    {
        printf("%4i", res[i]);
    }
    puts("");
    printf("n=%i", n);
    return EXIT_SUCCESS;
}
