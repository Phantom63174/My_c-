#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define N 10

int main(){
    setlocale(LC_ALL,"ukr");
    printf("����������� ����� ��-222");
int nr,nc,i,j;
int mt[N][N];

printf("\n����� ����� �������:");
scanf("%d%d",&nr,&nc);

printf("����� ��������[%d*%d]:\n",nr,nc);
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
printf("������ � �������:\n");
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
