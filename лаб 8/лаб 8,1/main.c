#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define N 10

int main(){
    setlocale(LC_ALL,"ukr");
    printf("Лясковський Артем АІ-222");
int nr,nc,i,j;
int mt[N][N];
int a;

printf("\nВедіть розмір матриці:");
scanf("%d%d",&nr,&nc);

printf("Розмір мматриці[%d*%d]:\n",nr,nc);
for(i=0;i<nr;i++){
    for(j=0;j<nc;j++){
        scanf("%d",&mt[i][j]);
    }
}
for(i=0;i<nr;i++){
    for(j=0;j<nc;j++){
        printf("\t%d",mt[i][j]);
    }
    printf("\n");
}
 printf("Ведіть чичло а:\n");
 scanf("%d",&a);

 int temp;
 int p,u,k;
 float sum=0;

 for(i=0;i<nr;i++){
      u=i%a;
     if(u!=0){
            for(k=0;k<nc-1;k++){
          for(j=0;j<nc-1;j++){
              if(mt[i][j]<mt[i][j+1]){
                 temp=mt[i][j];
                mt[i][j]=mt[i][j+1];
                mt[i][j+1]=temp;
              }
          }
            }
     }else {
         for(j=0;j<nc;j++){
                sum+=mt[i][j];
                p++;
         }
     }
}
for(i=0;i<nr;i++){
    for(j=0;j<nc;j++){
        printf("\t%d",mt[i][j]);
    }
    printf("\n");
}

printf("%f",sum/p);

return 0;

}
