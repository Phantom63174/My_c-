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

    printf("������ �������� �� %d ����:\n",a);
    scanf("%f",&arr[a]);
}
for(a=1; a<=N; a++){

    printf("���� %d=%6.2f ��� \n",a,arr[a]);
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
    printf("���� %d � ������������ ���������:%d\n",max[a],mxz);
}
printf("����������� ���� ���� ��������:%d ��.\n",l);

   printf("M��������� ��������:%d\n",mnx);

printf("������� ������� �������� �� ������ �� %.2f\n", sum/i);

float c,b;
printf("������� ����� a � b\n");
scanf("%f %f", &c,&b);
for(a=1; a<=N; a++){
if(arr[a] < c ){
    for(a=1; a<=N; a++){
        arr[a] = b;
    printf("���� %d=%6.2f ��� \n",a,arr[a]);
    }
}
}
    return 0;
}
