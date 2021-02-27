#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void encode(char buff[]){//3 pointers
    char temp[100];//temporary array used to store "buff"
    strncpy(temp,buff,100);
    char * WordFinder = temp;//pointer that iterates through "buff"
    char * WordCopier = temp;
    char * WordPaster = buff;

    int n;
        while (*WordFinder != '\0') {
            n = 0;
            while (isalpha(*WordFinder) != 0 && *WordFinder != '\0') {
                WordFinder++;
                n++;

            }
            WordCopier = WordFinder;

            for (int a = 0; a < n; a++) {
                WordCopier--;
                *WordPaster = toupper(*WordCopier);
                WordPaster++;
            }
            *WordPaster = ' ';//
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
        printf("%d\n", sizeof(buff));
        for (int a = 0; a < sizeof(buff); a++) {printf("%c\n", buff[a]);}
        encode(buff);
        printf("%c\n", 'o');
        fputs(buff,fout);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
