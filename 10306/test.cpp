#include <cstdio>
#include <cmath>
#define SIZE 310
#define INF 0x3fffffff
#define MIN(a, b) (a < b ? a : b)

int N, M, S;
int dp[SIZE][SIZE];
struct Coin{
	int a;
	int b;
}coin[SIZE];

void init(){
	for(int i = 0; i <= S; ++i){
		for(int j = 0; j <= S; ++j){
			dp[i][j] = INF;
		}
		coin[i].a = 0;
		coin[i].b = 0;
	}
	dp[0][0] = 0;
}

int main(){
	scanf("%d", &N);
	while(N--){
		scanf("%d %d", &M, &S);
		init();
		for(int i = 0; i < M; ++i){
			scanf("%d %d", &coin[i].a, &coin[i].b);
		}

		for(int i = 0; i < M; ++i){
			for(int j = coin[i].a; j <= S; ++j){
				for(int k = coin[i].b; k <= S; ++k){
					dp[j][k] = MIN(dp[j][k], dp[j - coin[i].a][k - coin[i].b] + 1);
				}
			}
		}

		int min = INF;
		for(int i = 0; i <= S; ++i){
			for(int j = 0; sqrt(pow(i, 2) + pow(j, 2)) <= S; ++j){
				if(pow(i, 2) + pow(j, 2) == pow(S, 2)){
					min = MIN(min, dp[i][j]);
				}
			}
		}

		if(min == INF){
			printf("not possible\n");
		}else{
			printf("%d\n", min);
		}
	}
}
