#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int satisfies(int a, int b, int c){
int res, sum2, modmin, mx, mn;
if (a<0 && b<0 && c<0){
        if (a<b && a<c){
            modmin=abs(a);
            sum2=b+c;
        } else
        if (b<a && b<c){
            modmin=abs(b);
            sum2=a+c;
        } else{
        if (c<a && c<b){
            modmin=abs(c);
            sum2=a+b;
        }
        }
        if (sum2<-256 && (int)log2(modmin)%1==0 && modmin<256){
            res= 1;
        } else {
if (abs(sum2)>modmin && sum2>-256){
    res= 1;
}
}
}
if (a<0 && b>=0 && c>=0){
    if (a>-256){
        res= 1;
    }
    else {
        res= 0;
    }
}
if (b<0 && a>=0 && c>=0){
    if (b>-256){
        res= 1;
    }
    else {
    res= 0;
    }
}
if (c<0 && b>=0 && a>=0){
    if (c>-256){
        res= 1;
    }
    else {
        res= 0;
    }
}
if (a<0 && b<0 && c>=0){
    if (3*(a+b)>-256){
        res= 1;
    }
    else {
        res= 0;
    }
}
if (a<0 && c<0 && b>=0){
    if (3*(a+c)>-256){
        res= 1;
    }
    else {
        res= 0;
    }
}
if (c<0 && b<0 && a>=0){
    if (3*(c+b)>-256){
        res= 1;
    }
    else {
        res= 0;
    }
}
if (a>=0 && b>=0 && c>=0){
   if (a>b && a>c){
    mx=a;
   } else
   if (b>a && b>c){
    mx=b;
   } else {
   if (c>a && c>b){
    mx=c;
   }
   }
   if (a<b && a<c){
    mn=a;
   } else
   if (b<a && b<c){
    mn=b;
   } else {
   if (c<a && c<b){
    mn=c;
   }
   }
    if (mn==0){
        res= 0;
    } else
    if (mx==0 && mn!=0){
        res= 1;
    } else
    if (mx%mn==0){
        res= 1;
    } else {
        res= 0;
    }
}
return res;
}
