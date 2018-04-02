#include <stdio.h>
#include <string.h>
#define MAX(X, Y) (X > Y ? X : Y)
#define SIZE 10000

int num[SIZE], LIS[SIZE];

int main(){
	int n, max, testNumber = 0;
	while(++testNumber){
		max = 0;
		scanf("%d", &num[0]);
		if(num[0] == -1){
			break;
		}
		for(n = 1; scanf("%d", &num[n]) && num[n] != -1; ++n);

		for(int k = 0; k < n; ++k){
			LIS[k] = 1;
			for(int i = 0; i < k; ++i){
				if(num[i] >= num[k]){
					LIS[k] = MAX(LIS[k], LIS[i] + 1);
				}
			}
		}

		for(int i = 0; i < n; ++i){
			max = MAX(LIS[i], max);
		}
		if(testNumber > 1) printf("\n");
		printf("Test #%d:\n", testNumber);
		printf("  maximum possible interceptions: %d\n", max);
	}
}
