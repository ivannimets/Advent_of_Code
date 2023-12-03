#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    FILE* input;
    input = fopen("input.txt", "r");

    int page = 1;
    int i;
    char line[50];
    char ch = getc(input);
    while (ch != EOF) {
        for (i = 0; i < 50; i++) line[i] = '\0';
        while(ch != '\n') {
            strncat(line, &ch, 1);
            ch = getc(input);
        }
        printf ("p. %i ", page);
        puts(line);
        page++;
        ch = getc(input);
    }
    if (feof(input))
        printf("\n End of file reached.");
    else
        printf("\n Something went wrong.");
    fclose(input);

    return 0;
}

// one     two    three   four   five   six   seven    eight    nine
// nine           eight   one                 eight
