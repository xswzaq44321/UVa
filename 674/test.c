#include <stdio.h>
#define MAX 7500

int main(){
	int dp[MAX] = {1, 0, 0};
	int v[5] = {1, 5, 10, 25, 50};
	int N;
	for(int k = 0; k < 5; k++){
		for(int i = v[k]; i < MAX; i++){
			if(dp[i - v[k]]){
				dp[i] += dp[i - v[k]];
			}
		}
	}
	while(scanf("%d", &N) != EOF){
		printf("%d\n", dp[N]);
	}
}
