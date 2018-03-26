#include <stdio.h>

int dp[11][11][11][11][11][11];
int price[10], combo[10][10], comboPrice[10], order[10][10];

int main(){
	int I, C, O; // I for item count, C for combo count, O for order count
	int temp = 0;

	scanf("%d", &I); // scan item
	for(int i = 0; i < I; i++){
		scanf("%d", &price[i]);
	}
	scanf("%d", &C); // scan combo
	for(int i = 0; i < C; i++){
		for(int j = 0; j < I; j++){
			scanf("%d", &combo[i][j]);
		}
		scanf("%d", &comboPrice[i]);
	}
	scanf("%d", &O); // scan order
	for(int i = 0; i < O; i++){
		for(int j = 0; j < I; j++){
			scanf("%d", &order[i][j]);
		}
	}

	for(int a = 0; a < 10; a++){
		dp[a + 1][0][0][0][0][0] = dp[a][0][0][0][0][0] + price[0];
		for(int b = 0; b < 10; b++){
			dp[a][b + 1][0][0][0][0] = dp[a][b][0][0][0][0] + price[1];
			for(int c = 0; c < 10; c++){
				dp[a][b][c + 1][0][0][0] = dp[a][b][c][0][0][0] + price[2];
				for(int d = 0; d < 10; d++){
					dp[a][b][c][d + 1][0][0] = dp[a][b][c][d][0][0] + price[3];
					for(int e = 0; e < 10; e++){
						dp[a][b][c][d][e + 1][0] = dp[a][b][c][d][e][0] + price[4];
						for(int f = 0; f < 10; f++){
							dp[a][b][c][d][e][f + 1] = dp[a][b][c][d][e][f] + price[5];
						}
					}
				}
			}
		}
	}
	for(int i = 0; i < C; i++){
		for(int a = combo[i][0]; a < 10; a++){
			for(int b = combo[i][1]; b < 10; b++){
				for(int c = combo[i][2]; c < 10; c++){
					for(int d = combo[i][3]; d < 10; d++){
						for(int e = combo[i][4]; e < 10; e++){
							for(int f = combo[i][5]; f < 10; f++){
								temp = dp[a - combo[i][0]][b - combo[i][1]][c - combo[i][2]][d - combo[i][3]][e - combo[i][4]][f - combo[i][5]] + comboPrice[i];
								if(dp[a][b][c][d][e][f] > temp){
									dp[a][b][c][d][e][f] = temp; 
								}
							}
						}
					}
				}
			}
		}
	}

	for(int i = 0; i < O; i++){
		printf("%d\n", dp [order[i][0]] [order[i][1]] [order[i][2]] [order[i][3]] [order[i][4]] [order[i][5]]);
	}
}
