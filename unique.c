#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void unique(FILE *fp){
	if (fp == NULL) {
		printf("this file is not open");
		exit(1);
	}
	char *current = NULL;
	char *previous = NULL;
	size_t line = 0;
	while (getline(&current, &line, fp) != -1) {
	       if (strcmp(previous, current) == 0 || previous == NULL) {
			printf("%s\n", current);
	       }
	       free(previous);
	       previous = current;
	}
	free(previous);
	free(current);
}


int main() {
	char filename[256];
	printf("Filename: ");
	scanf("%s", filename);
	
	FILE *fp = fopen(filename, "r");
	unique(fp);
	fclose(fp);
	return 0;
}
