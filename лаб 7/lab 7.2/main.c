#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    int a,k,i,fact=1;
    float n,n1,n2,n3,sum=0;
    setlocale(LC_ALL,"rus");
    printf("Введіть значення а:\n");
    scanf("%d",&a);

    for(k=1; k<=a; k++){
    n1=pow(-1,k)*(pow(k,3)-27);
    n2=(k+2);
    for(i=1; i<=n2; i++){
            fact*=i;
    }
    n3=fact*3;
    n=n1/n3;
    sum+=n;
       fact=1;
    }
    printf("Ваше значення: %f",sum);

    return 0;
}
