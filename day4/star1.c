#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main() {
    FILE* input;
    input = fopen("input.txt", "r");

    char num[3];
    int p, i, j;
    int win[25];
    int cur[35];
    int res = 0;
    char line[250];
    char ch = getc(input);
    while (ch != EOF) {
        for (i = 0; i < 250; i++) line[i] = '\0';
        for (i = 0; i < 25; i++) win[i] = 0;
        for (i = 0; i < 35; i++) cur[i] = 0;
        while(ch != '\n' && ch != '\0') {
            ch = getc(input);
            strncat(line, &ch, 1);
            //ch = gets(input);
        }
        i = 0;
        while (line[i] != ':') i++;
        i++;
        j = 0;
        while (line[i + 1] != '|') {
            for (int k = 0; k < 3; k++) num[k] = '\0';
            strncat(num, &line[i], 1);
            strncat(num, &line[i + 1], 1);
            strncat(num, &line[i + 2], 1);
            i = i + 3;
            win[j] = atoi(num);
            j++;
        }
        i = i + 2;
        j = 0;
        while (line[i] != '\n' && line[i] != '\0') {
            for (int k = 0; k < 3; k++) num[k] = '\0';
            strncat(num, &line[i], 1);
            strncat(num, &line[i + 1], 1);
            strncat(num, &line[i + 2], 1);
            i = i + 3;
            cur[j] = atoi(num);
            j++;
        }
        int local_res = 0;
        i = 0;
        while (win[i] != 0) {
            j = 0;
            while (cur[j] != 0){
                if (cur[j] == win[i]){
                    local_res++;
                }
                j++;
            }
            i++;
        }
        res = res + pow(2, local_res - 1);
        // p = 0;
        // printf("wins : ");
        // while (win[p] != 0) {
        //     printf("%i, ", win[p]);
        //     p++;
        // }
        // p = 0;
        // printf("my : ");
        // while (cur[p] != 0) {
        //     printf("%i, ", cur[p]);
        //     p++;
        // }
        // printf("\n");
        ch = getc(input);
    }
    printf("\n\n\n       ------------ Result = %i -----------", res);
    fclose(input);

    return 0;
}