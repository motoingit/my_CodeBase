
#include <stdio.h>

void printString(char str[], int idx){
    if(idx < 0)
        return;

    printf("%c",str[idx]);
    printString(str, idx-1);
}

int main() {
printf("\n");
    char str[] = "ABCD";
    int size = sizeof(str) / sizeof(str[0]);
    printString(str, size - 1);
printf("\n");
return 0;}
