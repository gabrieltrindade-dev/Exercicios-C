#include <stdio.h>

int main(){
    int i=5, *p;
    p = &i;
    printf("%x %d %d \n", p, *p+2, 3**p);
    //4094 7 15

 return 0;
}