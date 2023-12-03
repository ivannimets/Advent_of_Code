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

    	}
    	printf ("p. %i. %i%i ", page, num1, num2); 
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