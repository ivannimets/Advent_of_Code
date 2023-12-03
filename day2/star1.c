#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	FILE* input;
	input = fopen("input.txt", "r");

	int res = 0;
	int flag;
	int number;
	int i,j;
	int game = 1;
	char line[200];
	char num[2];
	char ch = getc(input);
    while (game<=100) {
    	for (i = 0; i < 200; i++) line[i] = '\0';
    	while(ch != '\n') {
    		strncat(line, &ch, 1);
   			ch = getc(input);
    	}
    	printf("Game: %i  ", game);
    	flag = 0;
    	for (i = 6; i < 200; i++){
    		if (line[i] == 'b') {
    			for (j = 0; j < 2; j++) num[j] ='\0';
    			strncat(num, &line[i-3], 1);
    			strncat(num, &line[i-2], 1);
    			number = atoi(num);
    			printf("b%i ", number);
    			if (number > 14) {
    				flag = 1;
    				printf(" crash ");
    				break;
    			}
    		}
    	}
    	if (flag == 0){
    		for (i = 6; i < 200; i++){
    			if (line[i] == 'n') {
    				for (j = 0; j < 2; j++) num[j] ='\0';
    				strncat(num, &line[i-7], 1);
    				strncat(num, &line[i-6], 1);
    				number = atoi(num);
    				printf("g%i ", number);
    				if (number > 13) {
    					flag = 1;
    					printf(" crash ");
    					break;
    				}
    			}
    		}
    	}
    	if (flag == 0){
    		for (i = 6; i < 200; i++){
    			if (line[i] == 'd') {
    				for (j = 0; j < 2; j++) num[j] ='\0';
    				strncat(num, &line[i-5], 1);
    				strncat(num, &line[i-4], 1);
    				number = atoi(num);
    				printf("r%i ", number);
    				if (number > 12) {
    					flag = 1;
    					printf(" crash ");
    					break;
    				}
    			}
    		}
    	}
    	if (flag == 0) res = res + game;
    	printf(" res=%i", res);
    	printf("\n");
    	ch = getc(input);
    	game++;
    }

    fclose(input);
    printf("\nResult: %i", res);

    return 0;
}
