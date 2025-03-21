#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#include "functions.h"


void print_usage(bool err);


int main(int argc, const char **argv) {
	int arguments = 0;
	Stack st = init_stack();

	// Default behavior for invocation with no arguments
	if (argc == 1) {
		anchor(&st);	
		update_alias(&st);
		exit(EXIT_SUCCESS);	
	} else if (argc == 2) {
		if(strcmp(argv[1], "pop") == 0) {
			delete_anchor(&st);
			update_alias(&st);
		}

		if(strcmp(argv[1], "list") == 0) {
			display_anchors(&st);
		}

		if(strcmp(argv[1], "switch") == 0) {
			int index = 0;
			printf("Enter index: ");
			scanf("%d", &index);
			switch_anchor(&st, index);
			update_alias(&st);
		}
	} else if (argc > 3) { // Disallow multiple commands
		print_usage(true, argv[0]);
	}

	return 0;	
}


void print_usage(bool err, char *name) {
	FILE *target = stdout;
	if (err) target = stderr;

	fprintf(target, "USAGE: %s <pop|list|switch>\n", name);
	if (err) exit(EXIT_FAILURE);
}