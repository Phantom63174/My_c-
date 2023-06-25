#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(LC_ALL, "rus");

  float x;
char grade;
  printf("Програма написана Лясковским Артёмом АІ-222 \n");

  printf("Ведите в каком классе вы учитесь:\n");
  scanf("%f", &x);

while((1>x)||(x>11)){
 printf("Ведите значение от 1 до 11\n");
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
    printf("початкова школа\n");
    break;

    case 'B':
    printf("середня школа\n");
    break;

    case 'C':
    printf("старша школа\n");
    break;

  }
    return 0;
}
