#include <stdio.h>
#include <stdlib.h>

void word_count(FILE *fp, int data[3]) {
        if (fp == NULL) {
                fprintf(stderr, "File not open.\n");
                exit(1);
        }
	data[0] = 0;
	data[1] = 0;
	data[2] = 0;
        int in_word = 0;
        int ch;
        while ((ch = fgetc(fp)) != EOF) {
                data[2]++;
                if (ch == '\n')
                        data[0]++;
                if (ch == ' ' || ch == '\t' || ch == '\n') {
                        in_word = 0;
                } else if (!in_word) {
                        data[1]++;
                        in_word = 1;
                }
        }
}

int main() {
	char filename[256];
	printf("Filename: ");
	scanf("%s", filename);
	
	FILE *fp = fopen(filename, "r");
	int data[3];
	word_count(fp, data);
	printf("lines: %d, words: %d, chars: %d\n", data[0],  data[1], data[2]);
	fclose(fp);
	return 0;
}

