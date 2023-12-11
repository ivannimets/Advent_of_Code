#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main() {
    FILE* input;
    input = fopen("input.txt", "r");

    // char temp[2500];
    char table[250][250];
    char ch = getc(input);
    int line = 1;
    int column = 1;
    int sx, sy;
    while (ch != EOF) {
        if ((ch != '\n') && (ch != '\0')) {
            table[column][line] = ch;
            if (ch == 'S') {
                sx = column;
                sy = line;
            }
            column += 1;
        }
        else {
            column = 1;
            line += 1;
        }
        ch = getc(input);
    }
    fclose(input);
    int circle = 0;
    int cas;
    int results[4];
    for (int i = 0; i < 4; i++) {
        cas = i + 1;
        circle = 1;
        column = sx;
        line = sy;
        if (cas == 1) line -= 1;
        if (cas == 3) line += 1;
        if (cas == 2) column += 1;
        if (cas == 4) column -= 1;
        while (sx != column || sy != line) {
            switch(cas) {
                case 1:
                    if (table[column][line] == '7'){
                        circle++;
                        column = column - 1;
                        cas = 4;
                        break;
                    }
                    if (table[column][line] == 'F'){
                        circle++;
                        column = column + 1;
                        cas = 2;
                        break;
                    }
                    if (table[column][line] == '|'){
                        circle++;
                        line = line - 1;
                        cas = 1;
                        break;
                    }
                    cas = 5;
                    break;
                case 2:
                    if (table[column][line] == '-'){
                        circle++;
                        column = column + 1;
                        cas = 2;
                        break;
                    }
                    if (table[column][line] == '7'){
                        circle++;
                        line = line + 1;
                        cas = 3;
                        break;
                    }
                    if (table[column][line] == 'J'){
                        circle++;
                        line = line - 1;
                        cas = 1;
                        break;
                    }
                    cas = 5;
                    break;
                case 3:
                    if (table[column][line] == 'J'){
                        circle++;
                        column = column - 1;
                        cas = 4;
                        break;
                    }
                    if (table[column][line] == 'L'){
                        circle++;
                        column = column + 1;
                        cas = 2;
                        break;
                    }
                    if (table[column][line] == '|'){
                        circle++;
                        line = line + 1;
                        cas = 3;
                        break;
                    }
                    cas = 5;
                    break;
                case 4:
                    if (table[column][line] == '-'){
                        circle++;
                        column = column - 1;
                        cas = 4;
                        break;
                    }
                    if (table[column][line] == 'F'){
                        circle++;
                        line = line + 1;
                        cas = 3;
                        break;
                    }
                    if (table[column][line] == 'L'){
                        circle++;
                        line = line - 1;
                        cas = 1;
                        break;
                    }
                    cas = 5;
                    break;
                case 5: 
                    column = sx;
                    line = sy;
                    break;
            }
        }
        results[i] = circle;
    }
    int res = 0;
    for (int i = 0; i < 4; i++) {
        if (results[i] > res) res = results[i];
    }
    printf("\nResult = %i", res / 2);
    return 0;
}