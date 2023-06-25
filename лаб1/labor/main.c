#include <stdio.h>
#include <math.h>

int main() //Начало програмы
{

printf("Kod napusav Laskovskiy Artem AI-222\n");

    float v,a,h;//Вводим новые переменые

    printf("Ctorona kvadrata a=");

    scanf("%f", &a);//Значение стороны квадрата

    printf("Vusota piramidu h=");

    scanf("%f", &h);//Значение высоты пирамиды

    v = (a*a*h) / 3;//Находим обьъем пирамиды

    printf("Ob`em piramidu V= %1.2f", v); //Выводим объем пирамиды


    return 0;
}

