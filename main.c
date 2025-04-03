#include <stdio.h>
#include <stdbool.h>

void algorithmX(int n);
void populateWithInt(int*vector, int n);
bool testK(int* L, int k);
void printA(char*A, int n);
int count = 1;

void main() {
	int n = 10;
	algorithmX(n);
}

void algorithmX(int n) {
	int L[26] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	int U[26] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
	char A[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','X','W','Y','Z'};
	int k, p, q;

	//X1
X1:
	populateWithInt(L, n);
	L[n] = 0;
	k = 1;

	//X2
X2:
	p = 0;
	q = L[0];
	
	//X3
X3:
	A[k] = q+64;
	if (!testK(A, k)) {
		goto X5;
	}
	if (k == n) {
		//Visit A
		printA(A, n); //????
		goto X6;
	}

	//X4
X4://
	U[k] = p;
	L[p] = L[q];
	k++;
	goto X2;

	//X5
X5:
	//A[k] ++;
	p = q;
	q = L[p];
	if (q != 0) {
		goto X3;
	}

	//X6
X6:
	k--;
	if (k == 0) {
		goto XEND;
	}
	p = U[k];
	q = A[k]-64;
	L[p] = q;
	goto X5;

XEND:
	printf("---------- END ----------");
}

void populateWithInt(int* vector, int n) {
	for (int i = 0; i < n; i++) {
		vector[i] = i+1;
	}
}

bool testK(int* L, int k) {

	return true;

}

void printA(char*A, int n) {
	for (int i = 1; i <= n; i++) {
		printf("%c", A[i]);
	}
	printf(" - %d", count);
	printf("\n");
	count++;
}
