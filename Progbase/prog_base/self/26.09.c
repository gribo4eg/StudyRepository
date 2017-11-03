#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
int h, m, code;
float g;
printf("vvedit: hours, minutes ta kod mista \n");
scanf("%i %i %i", &h, &m, &code);
switch(code){
case 44: g=((h*60)+m)*0.44; break;
case 66: g=((h*60)+m)*0; break;
case 1 : g=((h*60)+m)*30; break;
default: {
g=((h*60)+m)*1;
printf("vartist: %f", g);
return 1;}
}
printf("vartist: %f", g);
return 0;
}
