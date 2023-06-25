#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main()
{

    setlocale(LC_ALL , "rus");
    int x;

    printf("Работу написал Лясковський Артем АІ-222\n");
    printf("Ведите число от 1 до 25:\n");
    scanf("%d", &x);

    while((1>x)||(x>25)){

          printf("Ведите число от 1 до 25:\n");
          scanf("%d", &x);

    }

    switch(x){
    case 1:
    printf("first\n");
    break;

    case 2:
    printf("second\n");
    break;

    case 3:
    printf("third\n");
    break;

    case 4:
    printf("fourth\n");
    break;

    case 5:
    printf("fiveth\n");
    break;

    case 6:
    printf("sixth\n");
    break;

    case 7:
    printf("seventh\n");
    break;

    case 8:
    printf("eighth\n");
    break;

    case 9:
    printf("nineth\n");
    break;

    case 10:
    printf("tenth\n");
    break;

    case 11:
    printf("elenth\n");
    break;

    case 12:
    printf("twenteenth\n");
    break;

    case 13:
    printf("thirteenth\n");
    break;

    case 14:
    printf("fourteenth\n");
    break;

    case 15:
    printf("fiftenth\n");
    break;

    case 16:
    printf("sixtennth\n");
    break;

    case 17:
    printf("seventeenth\n");
    break;

    case 18:
    printf("eighteenth\n");
    break;

    case 19:
    printf("nineteenth\n");
    break;

    case 20:
    printf("twenty\n");
    break;

    case 21:
    printf("twenty first\n");
    break;

    case 22:
    printf("twenty second\n");
    break;

    case 23:
    printf("twenty third\n");
    break;

    case 24:
    printf("twenty fourth\n");
    break;

    case 25:
    printf("twenty fifth\n");
    break;
    }




    return 0;
}
