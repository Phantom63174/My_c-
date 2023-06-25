#include <stdio.h>
#include <locale.h>
#include <string.h>
#define N 20
int main()
{
    int n,m;
    setlocale(LC_ALL, "ukr");
    struct student {
char Firtname[50];
char Lastname[50];
char Surname[50];
int Math;
int Physics;
int Ukr;
} std[N];
do{
   puts("How much students (from 1 to 20):");
scanf("%d",&n);
}while(n<0||n>20);
for(m=0; m<n; m++){
puts("Enter the name: ");
scanf("%s",std[m].Firtname);
puts("Enter the lastname: ");
scanf("%s",std[m].Lastname);
puts("Enter the surname: ");
scanf("%s",std[m].Surname);
do{
puts("Enter mark from the math: ");
scanf("%d",&std[m].Math);
}while(std[m].Math<0||std[m].Math>10);
do{
puts("Enter mark from the physics: ");
scanf("%d",&std[m].Physics);
}while(std[m].Physics<0||std[m].Physics>10);
do{
puts("Enter a pass=1 or fail=0 from the ukr: ");
scanf("%d",&std[m].Ukr);
}while(std[m].Ukr<-1||std[m].Ukr>2);
}
printf("List of students insured to universite:\n");
for(m=0; m<n; m++){
        if(std[m].Math>3&&std[m].Physics>3&&std[m].Ukr==1){
            printf("Student %d Name %s Lastname %s Surname %s passed.\n",m+1,std[m].Firtname,std[m].Lastname,std[m].Surname);
            printf("Your mark for the math %d and physics. %d",std[m].Math,std[m].Physics);
        }
}
    return 0;
}
