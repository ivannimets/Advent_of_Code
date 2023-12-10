#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main() {
    FILE* input;
    input = fopen("input.txt", "r");

    long seeds[100];
    int w, k;
    char line[250];
    char num[50];
    char ch = getc(input);
    while (ch != EOF) {
        for (int i = 0; i < 250; i++) line[i] = '\0';
        while(ch != '\n' && ch != '\0') {
            // ch = getc(input);
            strncat(line, &ch, 1);
            ch = getc(input);
        }
        strncat(line, &ch, 1);
        if (line[0] == 's' && line[1] == 'e' && line[2] == 'e' && line[3] == 'd' && line[4] == 's' && line[5] == ':') {
            w = 7;
            k = 0;
            while (line[w] != '\n') {
                w++;
                for (int i = 0; i < 50; i++) {
                    num[i] = '\0';
                }
                while (line[w] != ' ' && line[w] != '\n') {
                    strncat(num, &line[w], 1);
                    w++;
                }
                seeds[k] = atoi(num);
                k++;
            }
        }
        //puts(line);
        ch = getc(input);
    }
    k = 0;
    while (seeds[k] != 0) {
        printf("%i, ", seeds[k]);
        k++;
    }
    //printf("\n\n\n       ------------ Result = %i -----------", res);
    fclose(input);

    return 0;
}