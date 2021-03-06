/*
 * Programmer: Kailai Cui. This program reads the message, reverse each
“word” in the phrase where words are separated by one or more non-alphabetic characters; and
keep each non-alphabetic character in their original position. I use a temp array and three pointers to read "words" and modify the input string.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void encode(char buff[]){//should be able to handle "special cases" such as empty line, starting with special char, multiple special chars, etc.
    char temp[100];//temporary array used to store "buff"
    strncpy(temp,buff,100);
    char * WordFinder = temp;//pointer that iterates through "temp"
    char * WordCopier = temp;//pointer that iterates through "temp", goes back in reverse on each word
    char * WordPaster = buff;//pointer that copies value from WordCopier to "buff"
    int n;//store the length of each word
        while (*WordFinder != '\0') {
            n = 0;
            while (isalpha(*WordFinder) != 0 && *WordFinder != '\0') {//stops after each word
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
                *WordPaster = ' ';//replace underline with space
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
        encode(buff);//change buff to the desired output
        fputs(buff,fout);//puts buff into fout
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
