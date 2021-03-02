#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void encode(char buff[]){//3 pointers
    char temp[100];//temporary array used to store "buff"
    strncpy(temp,buff,100);
    char * WordFinder = temp;//pointer that iterates through "temp"
    char * WordCopier = temp;//pointer that iterates through "temp", goes back in reverse on each word
    char * WordPaster = buff;//pointer that copies value from WordCopier to "buff"

    int n;
        while (*WordFinder != '\0') {
            n = 0;
            while (isalpha(*WordFinder) != 0 && *WordFinder != '\0') {//stops after the first word
                WordFinder++;
                n++;

            }
            WordCopier = WordFinder;

            for (int a = 0; a < n; a++) {//copies the word from "temp" into "buff", notice that the order is reversed
                WordCopier--;
                *WordPaster = toupper(*WordCopier);
                WordPaster++;
            }
            if (*WordPaster == '_'){
                *WordPaster = ' ';//replace special char with space
            }
            WordPaster++;
            WordFinder++;

        }


}
int main() {
    char buff[100];
    FILE *fin = fopen("lab1p3in","r");
    FILE *fout = fopen("lab1p3out","w");
    if (fin == NULL){
        perror("error opening file");
    }
    while(fgets(buff,100,fin)!=NULL){
        encode(buff);
        fputs(buff,fout);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
