#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "rus");

    float a,y1,y2,y3,y4,x1,x2,h;
   printf("Програма написана Лясковским Артёмом АІ-222 \n");

   printf("Ведите значение a:\n");
   scanf("%f", &a);

   x1=0.5;
   h=1.8;
   x2=43.8;

   do {
   y1= a +pow(x1,a/2);
   y2= pow(x1,1./3)+1.2;
   if(y2>0){
 y3=sqrt(y2);
 y4=y1/y3 +10;
printf(" |%.2f|  |%.2f|\n", x1,y4);
   }else {
    printf("Не можливо зробити обчислення x=%.2f = \n", x1);
   }

    x1=x1+h;
   }while(x1<x2);



    return 0;
}
