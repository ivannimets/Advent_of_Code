#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    FILE* input;
    input = fopen("input.txt", "r");

    int res1 = 0;
    int res2 = 0;
    int number;
    int red_num, green_num, blue_num;
    int i,j;
    int game = 1;
    char line[200];
    char num[2];
    char ch = getc(input);
    while (game<=100) {
        red_num = 0;
        green_num = 0;
        blue_num = 0;
        for (i = 0; i < 200; i++) line[i] = '\0';
        while(ch != '\n') {
            strncat(line, &ch, 1);
            ch = getc(input);
        }
        printf("Game: %i  ", game);
        for (i = 6; i < 200; i++){
            if (line[i] == 'b') {
                for (j = 0; j < 2; j++) num[j] ='\0';
                strncat(num, &line[i-3], 1);
                strncat(num, &line[i-2], 1);
                number = atoi(num);
                printf("b%i ", number);
                if (number >= blue_num) blue_num = number;
            }
        }
        for (i = 6; i < 200; i++){
            if (line[i] == 'n') {
                for (j = 0; j < 2; j++) num[j] ='\0';
                strncat(num, &line[i-7], 1);
                strncat(num, &line[i-6], 1);
                number = atoi(num);
                printf("g%i ", number);
                if (number >= green_num) green_num = number;
            }
        }
        for (i = 6; i < 200; i++){
            if (line[i] == 'd') {
                for (j = 0; j < 2; j++) num[j] ='\0';
                strncat(num, &line[i-5], 1);
                strncat(num, &line[i-4], 1);
                number = atoi(num);
                printf("r%i ", number);
                if (number >= red_num) red_num = number;
            }
        }
        printf("\nb = %i   g = %i   r = %i", blue_num, green_num, red_num);
        res2 = blue_num * green_num * red_num;
        res1 = res1 + res2;
        printf("   res=%i ", res2);
        printf("\n");
        ch = getc(input);
        game++;
    }
    printf("\n\n\n       ------------ Result = %i -----------", res1);
    fclose(input);

    return 0;
}