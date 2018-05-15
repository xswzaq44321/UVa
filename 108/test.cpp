#include <cstdio>
#define SIZE 110

int array[SIZE][SIZE];
int dp[SIZE][SIZE];
int N;

int main(){
	while(scanf("%d", &N) != EOF){
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < N; ++j){
				scanf("%d", &array[i][j]);
			}
		}

		int MAX = -1e8;
		for(int m = 0; m < N; ++m){
			for(int i = 0; i < N; ++i){
				for(int j = 0; j < N; ++j){
					dp[i][j] = 0;
				}
			}
			for(int i = 0; i < N; ++i){
				for(int j = m; j < N; ++j){
					for(int k = m; k <= j; ++k){
						dp[i][j] += array[i][k];
					}
				}
			}
			for(int i = 0; i < N; ++i){
				for(int j = m; j < N; ++j){
					int temp = 0;
					for(int k = i; k < N; ++k){
						temp += dp[k][j];
						if(temp > MAX){
							MAX = temp;
						}
					}
				}
			}
		}
		printf("%d\n", MAX);
	}
}
