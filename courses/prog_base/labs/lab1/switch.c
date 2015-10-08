#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int exec(int op, int a, int b){
int c, res, data_type;
if (op < 0){
    c = a;
    a = b;
    b = c;
    op = abs(op);
}
if (a == 0, b == 0){
    return 0;
}
switch (op){
case 0: res = -a; break;
case 1: res = a + b; break;
case 2: res = a - b; break;
case 3: res = a * b; break;
case 4: res = a / b; break;
case 5: res = abs(a); break;
case 6: res = pow(a, b); break;
case 7:
case 13:
case 77: res = a % b; break;
case 8: res = fmax(a, b); break;
case 9: res = fmin(a, b); break;
case 10:
    switch(abs(b)%8){
    case 0: data_type = sizeof(char); break;
    case 1: data_type = sizeof(signed char); break;
    case 2: data_type = sizeof(short); break;
    case 3: data_type = sizeof(unsigned int); break;
    case 4: data_type = sizeof(long); break;
    case 5: data_type = sizeof(unsigned long long); break;
    case 6: data_type = sizeof(float); break;
    case 7: data_type = sizeof(double); break;
    }
    res = abs(a) * data_type; break;
case 11: res = 4 * M_PI * cos((a * b) / a);
default:{
if (op < 100) {
    res = ((op % abs(a + 1)) + (op % abs(b + 1)));
    }else {
if (op >= 100){
    res = -1;
}
}
}
}
return res;
}
