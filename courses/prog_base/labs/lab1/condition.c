#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int satisfies(int a, int b, int c){
int sum2, modmin, mx, mn;
if (a<0, b<0, c<0){
        if (a<b, a<b){
            modmin=abs(a);
            sum2=b+c;
        }
        if (b<a,b<c){
            modmin=abs(b);
            sum2=a+c;
        }
        if (c<a,c<b){
            modmin=abs(c);
            sum2=a+b;
        }
        if (sum2<-256, (int)log2(modmin)%1==0, modmin<256){
            return 1;
        }
} else {
if (abs(sum2)>modmin, sum2>-256){
    return 1;
}
}
if (a<0, b>=0, c>=0){
    if (a>-256){
        return 1;
    }
    else {
        return 0;
    }
}
if (b<0, a>=0, c>=0){
    if (b>-256){
        return 1;
    }
    else {
        return 0;
    }
}
if (c<0, b>=0, a>=0){
    if (c>-256){
        return 1;
    }
    else {
        return 0;
    }
}
if (a<0, b<0, c>=0){
    if (3*(a+b)>-256){
        return 1;
    }
    else {
        return 0;
    }
}
if (a<0, c<0, b>=0){
    if (3*(a+c)>-256){
        return 1;
    }
    else {
        return 0;
    }
}
if (c<0, b<0, a>=0){
    if (3*(c+b)>-256){
        return 1;
    }
    else {
        return 0;
    }
}
if (a>=0, b>=0, c>=0){
    mx = fmax(fmax(a,b), fmax(b,c));
    mn = fmin(fmin(a,b), fmin(b,c));
    if (mn==0){
        return 0;
    }
    if (mx==0, mn!=0){
        return 1;
    }
    if (mx%mn==0){
        return 1;
    }
}
}

