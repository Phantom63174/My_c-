#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL,"Rus");
    printf("������ ������� ����������� ����� �I-222\n");
    float x,y;
    printf("������� �������� x=\n");
    scanf("%f",&x);

    printf("������� �������� y=\n");
    scanf("%f",&y);

    if (((pow(x,2)+pow(y,2))<=1)&& (x>=0)&&(y>=0))
        printf("����� �������� � ����\n");

    else
        if(((x>=-1)&&(y>=-1))&&((0>=x)&&(0>=y)))
    printf("����� �������� � ����\n");
        else
    printf("����� �� �������� � ����\n");



    return 0;
}
