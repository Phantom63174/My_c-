#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define N 10

int main(){
    setlocale(LC_ALL,"ukr");
    printf("Лясковський Артем АІ-222");
int nr,nc,i,j;
int mt[N][N];

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

 int temp;
printf("Массив с заменой:\n");
          for(j=0;j<nc;j++){
                if(mt[nr-1][j]>100){
                     for(i=0;i<nr;i++){
                 temp=mt[i][1];
                mt[i][1]=mt[i][j];
                mt[i][j]=temp;
                     }
              }
          }
for(i=0;i<nr;i++){
    for(j=0;j<nc;j++){
        printf("\t%d",mt[i][j]);
    }
    printf("\n");
}

return 0;

}
