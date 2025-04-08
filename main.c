#include <stdio.h>
#include <stdbool.h>

void algorithmX(int n);
void populateWithInt(int*vector, int n);
bool testK(char* A, int k);
void printA(char*A, int n);
int permutationsCount = 0;
int comparisonsCount = 0;
int attributionsCount = 0;

void main() {
	FILE *file;
	file = fopen("result.csv", "w");
	fprintf(file, "Size,Permutations,Comparisons,Attributions,\n");
	for (int n = 1; n <= 10; n++) {
		permutationsCount = 0;
		comparisonsCount = 0; 
		attributionsCount = 0;
		algorithmX(n);
		fprintf(file, "%d,%d,%d,%d,\n", n, permutationsCount, comparisonsCount, attributionsCount);
	}	
	
	//printf("\n");
	//printf("Permutations = %d\n", permutationsCount);
	//printf("Attributions = %d\n", attributionsCount);
	//printf("Comparisons = %d\n", comparisonsCount);

	fclose(file);

}

void algorithmX(int n) {
	int L[26] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	int U[26] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
	char A[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','X','W','Y','Z'};
	int k, p, q;

X1:
	populateWithInt(L, n);
	L[n] = 0;
	k = 1;
	attributionsCount +=2;

X2:
	p = 0;
	q = L[0];
	attributionsCount += 2;
	
X3:
	A[k] = q+64; //ASCII
	attributionsCount++;
	comparisonsCount++;
	if (!testK(A, k)) {
		goto X5;
	}
	comparisonsCount++;
	if (k == n) {
		printA(A, n);
		goto X6;
	}

X4:
	U[k] = p;
	L[p] = L[q];
	k++;
	attributionsCount += 3;
	goto X2;

X5:
	p = q;
	q = L[p];
	attributionsCount += 2;
	comparisonsCount++;
	if (q != 0) {
		goto X3;
	}
X6:
	k--;
	attributionsCount++;
	comparisonsCount++;
	if (k == 0) {
		goto XEND;
	}
	p = U[k];
	q = A[k]-64;
	L[p] = q;
	attributionsCount += 3;
	goto X5;

XEND:
	printf("\n---------- END ----------\n");
}

void populateWithInt(int* vector, int n) {
	for (int i = 0; i < n; i++) {
		vector[i] = i+1;
	}
	attributionsCount += (n + 1) + n;
	comparisonsCount += (n + 1);
}

bool testK(char* A, int k) {
	int letter_A = 65;
	int letter_B = 66;
	int letter_C = 67;

	comparisonsCount++;
	if (k == 1) {
		comparisonsCount++;
		attributionsCount++;
		return A[1] <= letter_C ? false : true; //Remove permutations that start with A, B or C
	}
	else if (k == 2) {
		comparisonsCount += 2;
		attributionsCount++;
		return A[2] >= letter_B ? false : true; //Keep only permutations which second character is A
	}
	attributionsCount++;
	return true;
}

void printA(char*A, int n) {
	permutationsCount++;
	attributionsCount += n;
	comparisonsCount += n+1;
	for (int i = 1; i <= n; i++) {
		printf("%c", A[i]);
	}
	printf(" - %d", permutationsCount);
	printf("\n");
}
