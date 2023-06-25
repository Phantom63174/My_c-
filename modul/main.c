#include <stdio.h>
#include <stdlib.h>

int main(){
    int x, *vk;
    x=5;
    vk = &x;
    *vk = x*5;
    x+=*vk;
    printf("%d",x);
    return 0;
}
