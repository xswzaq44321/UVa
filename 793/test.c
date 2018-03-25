#include <stdio.h>
#include <stdlib.h>

int Find(int x, int *p){
	if(x == p[x]) return x;
	return p[x] = Find(p[x], p);
}

void Union(int x, int y, int *p){
	int X = Find(x, p);
	int Y = Find(y, p);
	p[X] = Y;
}

int main(){
	int N, n;
	char pair[100] = {0};

	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d ", &n);
		int network[n + 1];
		char pairCommand = 0;
		int pairA = 0, pairB = 0;
		int successCount = 0, failCount = 0;
		for(int j = 0; j < n + 1; j++){ // set up the network
			network[j] = j;
		}

		// read in all pairs
		while(fgets(pair, 100, stdin) != NULL && sscanf(pair, "%c %d %d", &pairCommand, &pairA ,&pairB) == 3){
			int x = -1, y = -2;
			if(pairCommand == 'q'){ // see if two computer is connected
				x = Find(pairA, network);
				y = Find(pairB, network);
				if(x == y){
					successCount++;
				}else{
					failCount++;
				}
			}
			if(pairCommand == 'c'){ // connect the computer
				Union(pairA, pairB, network);
			}
		}

		printf("%d,%d\n", successCount, failCount);
		if(i < N-1){
			printf("\n");
		}
	}
}
