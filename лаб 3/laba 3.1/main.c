#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL,"Rus");
    printf("Работу написал Лясковський Артем АI-222\n");
    float x,y;
    printf("Введите значение x=\n");
    scanf("%f",&x);

    printf("Введите значение y=\n");
    scanf("%f",&y);

    if (((pow(x,2)+pow(y,2))<=1)&& (x>=0)&&(y>=0))
        printf("Точка попадает в зону\n");

    else
        if(((x>=-1)&&(y>=-1))&&((0>=x)&&(0>=y)))
    printf("Точка попадает в зону\n");
        else
    printf("Точка не попадает в зону\n");



    return 0;
}
