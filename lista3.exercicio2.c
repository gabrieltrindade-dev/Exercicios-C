#include <stdio.h>

int main(){
    int i=3,j=5;
    int *p, *q;
    p = &i;
    q = &j;

    //p == &i;
    printf("o resultado de a eh: %d\n",p == &i);
    //*p - *q;
    printf("o resultado de b eh: %d\n",*p - *q);
    //**&p;
    printf("o resultado de c eh: %d\n",**&p);
    // 3* - *p/(*q)+7;
    printf("o resultado de d eh: %d\n",3* - *p/(*q)+7);

    return 0;
}