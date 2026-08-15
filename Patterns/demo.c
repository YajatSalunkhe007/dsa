#include <stdio.h>
int main (){
    int x;
    printf ("Hello World !!!\n");
    printf("Enter a Number from 1 to 99: - \n");
    scanf("%d", &x);
    if (x<100){
        printf("The Number you selected is = %d\n", x);
    }
    else{
        printf("The Number is Greater than 99 !!!");
    }
    return 0;
}