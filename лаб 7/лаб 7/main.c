#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL,"rus");
    int a,b,c,v,n,m;
    printf("������� ����� �� 1 �� 27:\n");
    scanf("%d",&a);
    switch(a){
        case 1 ... 27:
    for(b=100; b<=999; b++){
    c=b/100;
    v=b/10%10;
    n=b%10;
    m=c+v+n;
    if(a==m){
        printf("���� �����: %d \n",b);
    }
    }
        break;
        default:
            printf("���� ����� �� ������������ �����");
    }

    return 0;
}
