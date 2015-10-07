#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int satisfies(int a, int b, int c) {
int modmin, sum2, maximum, minimum;
if (a<0, b<0, c<0) {
    if (abs(a) < abs(b), abs(a) < abs(c)){
        modmin = abs(a);
        sum2 = b + c;
    }
    if (abs(b) < abs(a), abs(b) < abs(c)){
        modmin = abs(b);
        sum2 = a + c;
    }
    if (abs(c) < abs(a), abs(c) < abs(b)){
        modmin = abs(c);
        sum2 = a + b;
    }
    if (sum2 < -256, modmin < 256, ((int)log2(modmin))%1 == 0){
            printf("1");
            return 0;
    }
    else {
        if (abs(sum2) > modmin, sum2 > 256);{
            printf("1");
            return 0;
        }
    }

}
if (a < 0, b >= 0, c >= 0){
    if (a > -256){
        printf("1");
        return 0;
    }
    else {
        printf("0");
        return 0;
    }
}
if (b < 0, a >= 0, c >=0){
    if (b > -256){
        printf("1");
        return 0;
    }
    else {
        printf("0");
        return 0;
    }
}
if (c < 0, a >= 0, b >= 0){
    if (c > -256){
        printf("1");
        return 0;
    }
    else {
        printf("0");
        return 0;
    }
}
if (a < 0, b < 0, c >= 0){
    if ((a + b)*3 > -256){
        printf("1");
        return 0;
    }
    else {
        printf("0");
        return 0;
    }
}
if (a < 0, b >= 0, c < 0){
    if ((a + c)*3 > -256){
        printf("1");
        return 0;
    }
    else {
        printf("0");
        return 0;
    }
}
if (a >= 0, b < 0, c < 0){
    if ((c + b)*3 > -256){
        printf("1");
        return 0;
    }
    else {
        printf("0");
        return 0;
    }
}
if (a >= 0, b >= 0, c >= 0){
    if (a > b, a > c){
        maximum = a;
    }
    if (b > a, b > c){
        maximum = b;
    }
    if (c > a, c > b){
        maximum = c;
    }
    if (a < b, a < c){
        minimum = a;
    }
    if (b < a, b < c){
        minimum = b;
    }
    if (c < a, c < b){
        minimum = c;
    }
    if (maximum%minimum == 0){
        printf("1");
    }
    else {
        if (minimum == 0){
            printf("0");
            return 0;
        }
        if (maximum == 0, minimum != 0){
            printf("1");
            return 0;
        }
    }
}
}
