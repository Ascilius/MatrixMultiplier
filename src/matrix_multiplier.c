#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTRSIZE 128

bool debug = false;

void read_matrix(FILE* file, int r, int c, int m[r][c]) {
	for (int i = 0; i < r; ++i) {
		char line[MAXSTRSIZE];
		fgets(line, MAXSTRSIZE, file);
		if (debug)
			printf("Debug: line: %s", line);

		char* tok = strtok(line, " \n");
		for (int j = 0; j < c; ++j) {
			int num = atoi(tok);
			if (debug)
				printf("\ttok: %d\n", num);

			m[i][j] = num;

			tok = strtok(NULL, " \n");
		}
	}
}

// dot product of specified column from m1 and row from m2
int dot_product(int r1, int n, int m1[r1][n], int c2, int m2[n][c2], int r, int c) {
	int sum = 0;
	for (int i = 0; i < n; ++i)
		sum += m1[r][i] * m2[i][c];
	return sum;
}

int main(int argc, char* args[]) {

	// command line inputs
	if (argc != 3) {
		printf("Usage: build/mm [input filename] [debug mode (0|1)]\n");
		exit(1);
	}
	char* filename = args[1];
	debug = args[2][0] == '1';

	// matrix inputs
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		printf("ERROR: Unable to open \"%s\"!\n", filename);
		exit(1);
	}
	
	// matrix 1 (input 1)
	int r1 = -1; // number of rows in m1
	int c1 = -1;  
	fscanf(file, "%d %d\n", &r1, &c1);
	if (debug)
		printf("Debug: Parsing a %d x %d matrix...\n", r1, c1);
	int m1[r1][c1];
	read_matrix(file, r1, c1, m1);
	if (debug) {
		for (int i = 0; i < r1; ++i) {
			for (int j = 0; j < c1; ++j)
				printf("%d ", m1[i][j]);
			printf("\n");
		}
	}

	// matrix 2 (input 2)
	int r2 = -1;
	int c2 = -1;  
	fscanf(file, "%d %d\n", &r2, &c2);
	if (debug)
		printf("Debug: Parsing a %d x %d matrix...\n", r2, c2);
	int m2[r2][c2];
	read_matrix(file, r2, c2, m2);
	if (debug) {
		for (int i = 0; i < r2; ++i) {
			for (int j = 0; j < c2; ++j)
				printf("%d ", m2[i][j]);
			printf("\n");
		}
	}

	// determining if inputs are valid
	int n = c1;
	if (c1 != r2) {
		printf("ERROR: Invalid dimensions, these matrices cannot be multiplied.");
		exit(1);
	}

	// matrix 3 (output)
	int r3 = r1;
	int c3 = c2;
	int m3[r3][c3];
	if (debug)
		printf("Debug: Calculating a %d x %d matrix...\n", r3, c3);

	// calculating (single thread)
	// TODO: improve through shared memory parallelism
	for (int i = 0; i < r3; ++i) {
		for (int j = 0; j < c3; ++j)
			m3[i][j] = dot_product(r1, n, m1, c2, m2, i, j);
	}
	
	// printing results
	for (int i = 0; i < r3; ++i) {
		for (int j = 0; j < c3; ++j)
			printf("%d\t", m3[i][j]);
		printf("\n");
	}

	// TODO: confirming answers using linear algebra library
	if (debug) {
		
	}

	return 0; // program completed successfully :)
}