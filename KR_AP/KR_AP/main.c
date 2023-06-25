#include <stdio.h> //не добавлены скобки в циклах и операторах для лучшей читабельности
#include <stdlib.h> //не добавлен заголовочній файл <stdlib.h> для функции rand()
#define MAX 10

float array[MAX];
int count;

float fn0(const float num_array[], int max0);
float fn1(float *ptr, int max1);
float fn2(float a, float b); //тип функции должен быть float вместо void // не корекное название переменых
float fn3(float *array, int max0); //завдання №6

int main( ){

    for (count = 0; count < 3; count++){

        printf("Enter a float value: ");  //не правильное описание ввода
        scanf("%f", &array[count]);

    }

    for (count = 3; count < MAX; count++) {

        array[count] = (float) (rand() % 100000) / (float) (rand() % 10000); //не подходящий тип rand (int)
    }

    printf("Show Array: \n"); //команда для вывода нужна (printf) вместо (puts)

    for (count = 0; count < MAX; count++) {

        printf("%d %f\n", count, array[count]);

    }

    printf("fn0 = %f\n", fn0(array, MAX)); //тип вызова переменой (%d) не соотвествует формату перемоной (float)
    printf("fn1 = %f\n", fn1(array, MAX)); //тип вызова переменой (%d) не соотвествует формату перемоной (float)
    printf("fn2 = %f\n", fn2(fn0(array, MAX),fn1(array, MAX))); //тип вызова переменой (%d) не соотвествует формату перемоной (float)
    printf("fn3 = %f\n", fn3(array, MAX)); //Завдання №6

    return 0;
}

/************************************/
float fn0(const float num_array[], int max0){ //поставлен (;) //P.S cosnt float num_array[] болле безопасние чем (float num_array[])

    int cnt;
float h;
h=num_array[0];

for (cnt = 0; cnt < max0; cnt++) {
    if (num_array[cnt] > h) {
        h = num_array[cnt];
    }
}
return h;
}

/******************************/
float fn1(float *ptr, int max1){

    int cnt;
    float d;
    d = *ptr++;

    for (cnt = 1; cnt<max1; cnt++){

        if (*ptr < d) {

            d = *ptr;

        }
        ptr++;
    }
    return d;
}

/*******************************/
float fn2(float a, float b){

    return (a-b);

}
/*******************************/ //Функція для завлання №6
float fn3(float *array, int max0){

    int cnt, count=0;
    float sum=0;

    for ( cnt = 0; cnt < max0; cnt++) {

        if (cnt%2 == 0) { // перевірка на парність елементу

            sum += array[cnt];
            count++;
        }
    }
    return sum/count;
}


