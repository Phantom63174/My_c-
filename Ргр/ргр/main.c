#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define N 7

int main()
{
    setlocale(LC_ALL, "rus");
float arr[N];
int max[N];
int a,i,z,l=1,m;
float sum=0;
for(a=1; a<=N; a++){

    printf("Введіть прибуток за %d день:\n",a);
    scanf("%f",&arr[a]);
}
for(a=1; a<=N; a++){

    printf("День %d=%6.2f грн \n",a,arr[a]);
}
int mxz=arr[1],mnx=arr[1];
for(a=1; a<=N; a++){

         if(arr[a]>mxz){
    mxz=arr[a];
         }
    if(arr[a]<mnx){
    mnx=arr[a];
    }
    if(a%2>0){
      sum+=arr[a];
      i++;
    }
}
for(a=1; a<=N; a++){
    if(mxz==arr[a]){
            z++;
    max[z]=a;
    }
}
for(a=1; a<=z; a++){
        m=max[a-1];
        if(max[a]==m+1){
        l++;
        }
    printf("День %d з максимальним прибутком:%d\n",max[a],mxz);
}
printf("Максимальна ціна була протягом:%d дн.\n",l);

   printf("Mінімальний прибуток:%d\n",mnx);

printf("Середне значеня прибутку за непарні дні %.2f\n", sum/i);

float c,b;
printf("Введите число a и b\n");
scanf("%f %f", &c,&b);
for(a=1; a<=N; a++){
if(arr[a] < c ){
    for(a=1; a<=N; a++){
        arr[a] = b;
    printf("День %d=%6.2f грн \n",a,arr[a]);
    }
}
}
    return 0;
}
