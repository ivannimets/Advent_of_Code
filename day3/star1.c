#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    FILE* input;
    input = fopen("input.txt", "r");

    char ch = getc(input);
    char cur_line[150];
    char top_line[150];
    char bot_line[150];
    char num[4];
    int number;
    int res = 0;
    int page = 1;
    for (int i = 0; i < 142; i++) {
        top_line[i] = '.';
        cur_line[i] = '.';
        bot_line[i] = '.';
    }
    while (ch != EOF) {
        int i = 0;
        while (ch != '\n') {
            top_line[i] = cur_line[i];
            cur_line[i] = bot_line[i];
            bot_line[i] = ch;
            i++;
            ch = getc(input);
        }
        //top_line[i] = '.';
        //cur_line[i] = '.';
        //bot_line[i] = '.';
        for (int i = 0; i<142; i++) {
            for (int j = 0; j < 4; j++) num[j] = '\0';
            if (cur_line[i] == '1' || cur_line[i] == '2' || cur_line[i] == '3' || cur_line[i] == '4' || cur_line[i] == '5' || cur_line[i] == '6' || cur_line[i] == '7' || cur_line[i] == '8' || cur_line[i] == '9' || cur_line[i] == '0'){
                if (cur_line[i+1] == '1' || cur_line[i+1] == '2' || cur_line[i+1] == '3' || cur_line[i+1] == '4' || cur_line[i+1] == '5' || cur_line[i+1] == '6' || cur_line[i+1] == '7' || cur_line[i+1] == '8' || cur_line[i+1] == '9' || cur_line[i+1] == '0'){
                    if (cur_line[i+2] == '1' || cur_line[i+2] == '2' || cur_line[i+2] == '3' || cur_line[i+2] == '4' || cur_line[i+2] == '5' || cur_line[i+2] == '6' || cur_line[i+2] == '7' || cur_line[i+2] == '8' || cur_line[i+2] == '9' || cur_line[i+2] == '0'){
                        if(i == 0){
                            if(cur_line[i + 3] != '.' || top_line[i] != '.' || top_line[i + 1] != '.' || top_line[i + 2] != '.' || top_line[i + 3] != '.' || bot_line[i] != '.'  || bot_line[i + 1] != '.'  || bot_line[i + 2] != '.'  || bot_line[i + 3] != '.') {
                                strncat(num, &cur_line[i], 1);
                                strncat(num, &cur_line[i + 1], 1);
                                strncat(num, &cur_line[i + 2], 1);
                                number = atoi(num);
                                printf(" %i ", number);
                                res = res + number;
                            }
                            i = i + 2;
                        } else {
                            if(cur_line[i - 1] != '.' || cur_line[i + 3] != '.' || top_line[i - 1] != '.' || top_line[i] != '.' || top_line[i + 1] != '.' || top_line[i + 2] != '.' || top_line[i + 3] != '.' || bot_line[i - 1] != '.' || bot_line[i] != '.'  || bot_line[i + 1] != '.'  || bot_line[i + 2] != '.'  || bot_line[i + 3] != '.') {
                                strncat(num, &cur_line[i], 1);
                                strncat(num, &cur_line[i + 1], 1);
                                strncat(num, &cur_line[i + 2], 1);
                                number = atoi(num);
                                printf(" %i ", number);
                                res = res + number;
                            }
                            i = i + 2;
                        }
                    } else {
                        if(i == 0){
                            if(cur_line[i + 2] != '.' || top_line[i] != '.' || top_line[i + 1] != '.' || top_line[i + 2] != '.' || bot_line[i] != '.'  || bot_line[i + 1] != '.'  || bot_line[i + 2] != '.') {
                                strncat(num, &cur_line[i], 1);
                                strncat(num, &cur_line[i + 1], 1);
                                number = atoi(num);
                                res = res + number;
                            }
                            i = i + 1;
                        } else {
                            if(cur_line[i - 1] != '.' || cur_line[i + 2] != '.' || top_line[i - 1] != '.' || top_line[i] != '.' || top_line[i + 1] != '.' || top_line[i + 2] != '.' || bot_line[i - 1] != '.' || bot_line[i] != '.'  || bot_line[i + 1] != '.'  || bot_line[i + 2] != '.') {
                                strncat(num, &cur_line[i], 1);
                                strncat(num, &cur_line[i + 1], 1);
                                number = atoi(num);
                                printf(" %i ", number);
                                res = res + number;
                            }
                            i = i + 1;
                        }
                    }
                } else {
                    if(i == 0){
                        if(cur_line[i + 1] != '.' || top_line[i] != '.' || top_line[i + 1] != '.' || bot_line[i] != '.' || bot_line[i + 1] != '.') {
                            strncat(num, &cur_line[i], 1);
                            strncat(num, &cur_line[i + 1], 1);
                            number = atoi(num);
                            printf(" %i ", number);
                            res = res + number;
                        }
                    } else {
                        if(cur_line[i - 1] != '.' || cur_line[i + 1] != '.' || top_line[i - 1] != '.' || top_line[i] != '.' || top_line[i + 1] != '.' || bot_line[i - 1] != '.' || bot_line[i] != '.' || bot_line[i + 1] != '.') {
                                num[0] = '0';
                            strncat(num, &cur_line[i], 1);
                            number = atoi(num);
                            printf(" %i", number);
                            res = res + number;
                        }
                    }
                }
            }
        }

        ch = getc(input);
        //puts(cur_line);
        printf(" %5i  %8i    \n", page, res);

        page++;
    }
    printf("   %i    ", res);
    if (feof(input))
        printf("\n End of file reached.");
    else
        printf("\n Something went wrong.");

    fclose(input);
    //printf("\nResult: %i", res);

    return 0;
}
