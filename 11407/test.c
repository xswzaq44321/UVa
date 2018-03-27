#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
	int t, N;
	int dp[10010] = {0}, v[100];
	memset(dp + 1, 20000, 10009 * sizeof(int));
	for(int i = 1; i <= 100; i++){
		v[i - 1] = i * i;
	}
	for(int k = 0; k < 100; k++){
		for(int i = v[k]; i < 10010; i++){
			if(dp[i - v[k]] + 1 < dp[i]) dp[i] = dp[i - v[k]] + 1;
		}
	}

	scanf("%d", &t);
	while(t--){
		scanf("%d", &N);
		printf("%d\r\n", dp[N]);
	}
}
