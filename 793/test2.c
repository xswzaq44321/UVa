#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 1000

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
	char pair[SIZE][3] = {{0}};
	char buffer[100] = {0};

	scanf("%d", &N);
#ifdef DEBUG
	fprintf(stderr, "[%d]\n", N);
#endif
	for(int i = 0; i < N; i++){
		memset(pair, 0, SIZE*3);
		scanf("%d ", &n);
		int network[n + 1];
		int pairCount = 0, successCount = 0, failCount = 0;

		for(int j = 0; j < n + 1; j++){ // set up of the network
			network[j] = j;
		}

		// read in all pairs buffer[0] != '\n'
		for(; fgets(buffer, 100, stdin) != NULL && sscanf(buffer, "%c %d %d", &pair[pairCount][0], &pair[pairCount][1] ,&pair[pairCount][2]) == 3; pairCount++, memset(buffer, 0, 10));
#ifdef DEBUG
		for(int j = 0; j < pairCount; j++){
			printf("%c %d %d\n", pair[j][0], pair[j][1], pair[j][2]);
		}
		exit(0);
#endif
		for(int j = 0; j < pairCount; j++){
			int x = -1, y = -2;
			if(pair[j][0] == 'q'){ // see if two computer is connected
				x = Find(pair[j][1], network);
				y = Find(pair[j][2], network);
				if(x == y){
					successCount++;
				}else{
					failCount++;
				}
			}
			if(pair[j][0] == 'c'){ // connect all the computer
				Union(pair[j][1], pair[j][2], network);
			}
		}

		if(i != 0){
			printf("\n\n");
		}
		printf("%d,%d", successCount, failCount);
	}
}
