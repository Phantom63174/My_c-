#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL,"Rus");
    printf("������ ������� ����������� ����� �I-222\n");
    float x,a,y;
    printf("������� �������� x=\n");
    scanf("%f",&x);

    printf("������� �������� a=\n");
    scanf("%f",&a);

    if((7-x)==fabs(a))
        printf("���� �������� y= %5.2f", y=x+a );
    else
        if((7-x)<fabs(a))
        printf("���� �������� y= %5.2f", y=x/a );
    else
         printf("���� �������� y= %5.2f", y=a-x );

    return 0;

}
