#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
	FILE* input;
	input = fopen("input.txt", "r");

	int num1, num2;
	int flag;
	int res = 0;
	int page = 1;
	int i;
	char line[100];
	char ch = getc(input);
    while (ch != EOF) {
    	for (i = 0; i < 95; i++) line[i] = '\0';
    	while(ch != '\n') {
    		strncat(line, &ch, 1);
    		ch = getc(input);
    	}
    	for (i = 0; i < 95; i++) {
    		if (line[i] == '1' || line[i] == '2' || line[i] == '3' || line[i] == '4' || line[i] == '5' || line[i] == '6' || line[i] == '7' || line[i] == '8' || line[i] == '9'){
    			if (flag == 0) {
    				num1 = (int)(line[i]) - (int)('0');
    				num2 = (int)(line[i]) - (int)('0');
    				flag = 1;
    			} else num2 = (int)(line[i]) - (int)('0');
    		}
    		if (line[i] == 'o' && line[i + 1] == 'n' && line[i + 2] == 'e') {
    			if (flag == 0) {
    				num1 = 1;
    				num2 = 1;
    				flag = 1;
    			} else num2 = 1;
    		}
    		if (line[i] == 't' && line[i + 1] == 'w' && line[i + 2] == 'o') {
    			if (flag == 0) {
    				num1 = 2;
    				num2 = 2;
    				flag = 1;
    			} else num2 = 2;
    		}
    		if (line[i] == 't' && line[i + 1] == 'h' && line[i + 2] == 'r' && line[i+ 3] == 'e' && line[i + 4] == 'e') {
    			if (flag == 0) {
    				num1 = 3;
    				num2 = 3;
    				flag = 1;
    			} else num2 = 3;
    		}
    		if (line[i] == 'f' && line[i + 1] == 'o' && line[i + 2] == 'u' && line[i+ 3] == 'r') {
    			if (flag == 0) {
    				num1 = 4;
    				num2 = 4;
    				flag = 1;
    			} else num2 = 4;
    		}
    		if (line[i] == 'f' && line[i + 1] == 'i' && line[i + 2] == 'v' && line[i+ 3] == 'e') {
    			if (flag == 0) {
    				num1 = 5;
       				num2 = 5;
    				flag = 1;
    			} else num2 = 5;
    		}
    		if (line[i] == 's' && line[i + 1] == 'i' && line[i + 2] == 'x') {
    			if (flag == 0) {
    				num1 = 6;
    				num2 = 6;
    				flag = 1;
    			} else num2 = 6;
    		}
    		if (line[i] == 's' && line[i + 1] == 'e' && line[i + 2] == 'v' && line[i+ 3] == 'e' && line[i + 4] == 'n') {
    			if (flag == 0) {
    				num1 = 7;
    				num2 = 7;
    				flag = 1;
    			} else num2 = 7;
    		}
    		if (line[i] == 'e' && line[i + 1] == 'i' && line[i + 2] == 'g' && line[i+ 3] == 'h' && line[i + 4] == 't') {
    			if (flag == 0) {
    				num1 = 8;
    				num2 = 8;
    				flag = 1;
    			} else num2 = 8;
    		}
    		if (line[i] == 'n' && line[i + 1] == 'i' && line[i + 2] == 'n' && line[i+ 3] == 'e') {
    			if (flag == 0) {
    				num1 = 9;
    				num2 = 9;
    				flag = 1;
    			} else num2 = 9;
    		}

    	}
    	printf ("%i%i ", num1, num2);
    	puts(line);
    	page++;
    	ch = getc(input);
    	flag = 0;
    	res = res + num2 + (num1 * 10);
    }
    if (feof(input))
        printf("\n End of file reached.");
    else
        printf("\n Something went wrong.");

    fclose(input);
    printf("\nResult: %i", res);

    return 0;
}