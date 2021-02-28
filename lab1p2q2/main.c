#include <stdio.h>
void intSum(){
    int a,b,c;
    printf("Give two integers: ");
    scanf("%d%d",&a,&b);
    c = a + b;
    printf("You entered %d and %d, their sum is: %d\n",a,b,c);
}
void floatProd(){
    float a,b,c;
    printf("Give two floats: ");
    scanf("%f%f",&a,&b);
    c = a * b;
    printf("You entered %f and %f, their product is: %f\n",a,b,c);
}
void wordPrinter(){
    char my_variable[100];
    printf("Give a word:");
    scanf("%s", my_variable);
    printf("%s%s\n",my_variable,my_variable);
}
int main() {
    intSum();
    floatProd();
    wordPrinter();
    return 0;
}
