#include <stdio.h>
#define SIZE 100
#define MAX(X, Y) (X > Y ? X : Y)

int ans[SIZE], num[SIZE], LCS[SIZE][SIZE];

int main(){
	int n, temp;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &temp);
		ans[temp] = i;
	}
	while(scanf("%d", &temp) != EOF){
		num[temp] = 1;
		for(int i = 2; i <= n; ++i){
			scanf("%d", &temp);
			num[temp] = i;
		}

		for(int i = 1; i <= n + 1; ++i){
			for(int j = 1; j <= n + 1; ++j){
				if(i == 1 || j == 1){
					LCS[i][j] = 0;
				}else if(ans[i - 1] == num[j - 1]){
					LCS[i][j] = LCS[i - 1][j - 1] + 1;
				}else if(ans[i - 1] != num[j - 1]){
					LCS[i][j] = MAX(LCS[i - 1][j], LCS[i][j - 1]);
				}
			}
		}

		printf("%d\n", LCS[n + 1][n + 1]);
	}
}
