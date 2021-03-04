#include <stdio.h>
void intSum(){//asks for two integers and outputs them and their sum.
    int a,b,c;
    printf("Give two integers: ");
    scanf("%d%d",&a,&b);
    c = a + b;
    printf("You entered %d and %d, their sum is: %d\n",a,b,c);
}
void floatProd(){//asks for two floats and outputs their product.
    float a,b,c;
    printf("Give two floats: ");
    scanf("%f%f",&a,&b);
    c = a * b;
    printf("You entered %f and %f, their product is: %f\n",a,b,c);
}
void wordPrinter(){//asks for a word and prints it twice on the same row.
    char my_variable[100];
    printf("Give a word: ");
    scanf("%s", my_variable);
    printf("%s%c%s\n",my_variable,' ',my_variable);
}
int main() {
    intSum();
    floatProd();
    wordPrinter();
    return 0;
}
