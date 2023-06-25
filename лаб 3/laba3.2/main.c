#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL,"Rus");
    printf("Работу написал Лясковський Артем АI-222\n");
    float x,a,y;
    printf("Введите значение x=\n");
    scanf("%f",&x);

    printf("Введите значение a=\n");
    scanf("%f",&a);

    if((7-x)==fabs(a))
        printf("Ваше значение y= %5.2f", y=x+a );
    else
        if((7-x)<fabs(a))
        printf("Ваше значение y= %5.2f", y=x/a );
    else
         printf("Ваше значение y= %5.2f", y=a-x );

    return 0;

}
