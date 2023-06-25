#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "rus");

    int x,i=0;

    printf("Работу написал Лясковский Артём АІ-222\n");

 do{

       printf("Ведите число от -10 до 25 включительно: \n");
       scanf("%d",&x);
       if((-10<=x)||(x<=25)){
        i++;
       }
 }while (x!=0);
 {

 }

    printf("Числа от -10 до 25: %d", i);

    return 0;
}
