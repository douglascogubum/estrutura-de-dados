/*
 ============================================================================
 Name        : Prompt.c
 Author      : Douglas Cogubum
 Version     : 1.0
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

void print_entry(char *entry) {
	printf("You entered: %s\n", entry);
}

int main(int argc, char *argv[]) {
	char input[201];
	int result;

	while(1) {
		printf("prompt> ");
		if (fgets(input, 200, stdin) == NULL) {
			printf("An error ocurred.\n");
			break;
		}

		if (strncmp(input, "put", 3) == 0) {
			put(input[4] - '0');
			list();
		}

		if (strncmp(input, "get", 3) == 0) {
			result = get(input[4] - '0');
			printf("%d\n", result);
		}

		if (strncmp(input, "list\n", 3) == 0) {
			list();
		}

		if (strncmp(input, "remove", 6) == 0) {
			removeList(input[7] - '0');
			list();
		}

		if (strncmp(input, "clear\n", 6) == 0) {
			clear();
		}

		if (strncmp(input, "first\n", 6) == 0) {
			result = first();
			printf("%d\n", result);
		}

		if (strncmp(input, "last\n", 5) == 0) {
			result = last();
			printf("%d\n", result);
		}

		if (strncmp(input, "sort\n", 5) == 0) {
			sort();
			list();
		}

		if (strncmp(input, "exit\n", 5) == 0) {
			printf("Leaving. Good bye.\n");
			break;
		}

		print_entry(input);
	}

	return EXIT_SUCCESS;
}
