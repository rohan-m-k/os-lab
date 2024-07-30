#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    FILE* fp;
    char ch;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1; 
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error in opening file: %s\n", argv[1]);
        return 1;  
    }

    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }

    fclose(fp);

    return 0; 
}
