#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(LC_ALL, "rus");

  float x;
char grade;
  printf("�������� �������� ���������� ������ ��-222 \n");

  printf("������ � ����� ������ �� �������:\n");
  scanf("%f", &x);

while((1>x)||(x>11)){
 printf("������ �������� �� 1 �� 11\n");
  scanf("%f", &x);
 }


 if((x>=1)&&(4>=x)){
 grade ='A';
 } else if((x>=5)&&(9>=x)){
 grade = 'B';
  }else {
 grade = 'C';
 }

  switch(grade){
case 'A':
    printf("��������� �����\n");
    break;

    case 'B':
    printf("������� �����\n");
    break;

    case 'C':
    printf("������ �����\n");
    break;

  }
    return 0;
}
