#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "rus");

    float n1,n2,n=1,a,e,sum;
    int i=1;

     printf("�������� �������� ����������� ������� ��-222\n");

     printf("������ �������� A � ��������� �� 1 �� 0.001 \n");
     scanf ("%f",&a );

     printf("������ �������� E � ��������� �� 0,01 �� 0.02 \n");
     scanf ("%f",&e );

    do {
printf("���� �������� n%d = %f\n",i,n);
sum+=n;
 i++;
     n=1/pow(i,2);
     } while(n>a);
    printf("����� ��� �� �������� �������� n%d = %f\n",i,n);
     printf("���� ����� �������� sum= %f\n", sum);

     i=1;
     do {
    printf("���� �������� n%d = %f\n",i,n);
            i++;
       n=1/pow(i,2);
       n1=1/pow(i-1,2);
n2=fabs(n1-n);
     }while(n2>e);
     printf("����� ��� �� �������� �������� n%d = %f\n",i,n);


    return 0;
}

