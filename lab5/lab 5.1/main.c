#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "rus");

    int x,i=0;

    printf("������ ������� ���������� ���� ��-222\n");

 do{

       printf("������ ����� �� -10 �� 25 ������������: \n");
       scanf("%d",&x);
       if((-10<=x)||(x<=25)){
        i++;
       }
 }while (x!=0);
 {

 }

    printf("����� �� -10 �� 25: %d", i);

    return 0;
}
