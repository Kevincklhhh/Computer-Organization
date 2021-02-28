#include <stdio.h>
void printHalf(){
    printf("One half is 50 %%\n");
};
void printIntDiff(int a, int b){
    int c = a - b;
    printf("The difference between %d and %d is %d\n", a, b, c);
};
void printFloatDiv(float a, float b){
    float c = a/b;
    printf("%f / %f is %f\n", a,b,c);
};
int main() {
    printHalf();
    printIntDiff(10,20);
    printFloatDiv(3.3,9.9);
    return 0;
}
