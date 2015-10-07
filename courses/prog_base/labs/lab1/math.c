#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#import <math.h>

double calc(double x, double y, double z) {
double a;
double a0, a1, a2;
if (z==0, x==y, x==0, y==0){
    return NAN;
}
a0 = ((pow(x, y+1)) / (pow((x - y), 1/z)));
a1 = y / (4 * fabs(x + y));
a2 = pow(x, (1/(fabs(sin(y)))));
a = a0 + a1 + a2;
return a;
}
