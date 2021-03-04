#include <stdio.h>
void printHalf(){//print the string: One half is 50%
    printf("One half is 50 %%\n");
};
void printIntDiff(int a, int b){//print two integers and their difference.
    int c = a - b;
    printf("The difference between %d and %d is %d\n", a, b, c);
};
void printFloatDiv(float a, float b){//two floats and the result of dividing one with the other
    float c = a/b;
    printf("%f / %f is %f\n", a,b,c);
};
int main() {
    printHalf();
    printIntDiff(10,3);
    printFloatDiv(1,3);
    return 0;
}
