#include <stdio.h>
#include <stdlib.h>

int board[8][8] = {0};
int place[8] = {0};
int max = 0;
void backtracking(int n){
	if(n == 8){
		int sum = 0;
		for(int i = 0; i < 8; i++){
			sum += board[i][place[i]];
		}
		if(max < sum) max = sum;
		return;
	}
	for(int i = 0; i < 8; i++){
		int danger = 0;
		for(int j = n - 1; j >= 0 && danger != 1; j--){
			if(place[j] == i) danger = 1;
			if(abs(n - j) == abs(i - place[j])) danger = 1;
		}
		if(!danger){
			place[n] = i;
			backtracking(n + 1);
		}
	}
}

int main(){
	int k;
	scanf(" %d ", &k);
	while(k--){
		max = 0;
		for(int i = 0; i < 8; i++){ // scanning
			for(int j = 0; j < 8; j++){
				scanf(" %d ", &board[i][j]);
			}
		}

		backtracking(0);
		printf("%5d\n", max);
	}
}
