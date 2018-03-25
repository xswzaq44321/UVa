#include <stdio.h>
#define MAX_DIMENSION 6

int solution[MAX_DIMENSION];
int S[20];
int K;
int newline = 0;

void backtracking(int digit, int dimension){
	if(dimension == MAX_DIMENSION){
		for(int i = 0; i < MAX_DIMENSION; i++){
			if(i) printf(" ");
			printf("%d", solution[i]);
		}
		printf("\n");
		return;
	}
	for(int i = digit; i < K; i++){
		//fprintf(stderr, "{sol[%d] = S[%d]}\n", dimension, i);
		solution[dimension] = S[i];
		backtracking(i + 1, dimension + 1);
	}
	return;
}

int main(){
	while(scanf("%d", &K) != EOF && K != 0){
		newline = newline ? printf("\n") : 1;
		for(int i = 0; i < K; i++){
			scanf("%d", &S[i]);
		}
		backtracking(0, 0);
	}
}
