#include <stdio.h>
#include <string.h>

int dp[10][10][10][10][10][10];
int price[10], combo[10][10], comboPrice[10], order[10][10];

int main(){
	int I, C, O; // I for item count, C for combo count, O for order count
	int temp = 0;

	while(scanf("%d", &I) != EOF){
		memset(dp, 0, 1000000);
		memset(price, 0, 10);
		memset(combo, 0, 100);
		memset(comboPrice, 0, 10);
		memset(order, 0, 100);

		for(int i = 0; i < I; i++){ // scan item
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

		fprintf(stderr, "%d", I);
		for(int i = 0; i < I; i++){ // item
			fprintf(stderr, " %d", price[i]);
		}
		fprintf(stderr, "\n%d\n", C); // combo
		for(int i = 0; i < C; i++){
			for(int j = 0; j < I; j++){
				fprintf(stderr, "%d ", combo[i][j]);
			}
			fprintf(stderr, "%d\n", comboPrice[i]);
		}
		fprintf(stderr, "%d\n", O); // order
		for(int i = 0; i < O; i++){
			for(int j = 0; j < I; j++){
				fprintf(stderr, "%d ", order[i][j]);
			}
			fprintf(stderr, "\n");
		}

		for(int a = 0; a < 10; a++){
			if(a < 9){
				dp[a + 1][0][0][0][0][0] = dp[a][0][0][0][0][0] + price[0];
			}
			for(int b = 0; b < 10; b++){
				if(b < 9){
					dp[a][b + 1][0][0][0][0] = dp[a][b][0][0][0][0] + price[1];
				}
				for(int c = 0; c < 10; c++){
					if(c < 9){
						dp[a][b][c + 1][0][0][0] = dp[a][b][c][0][0][0] + price[2];
					}
					for(int d = 0; d < 10; d++){
						if(d < 9){
							dp[a][b][c][d + 1][0][0] = dp[a][b][c][d][0][0] + price[3];
						}
						for(int e = 0; e < 10; e++){
							if(e < 9){
								dp[a][b][c][d][e + 1][0] = dp[a][b][c][d][e][0] + price[4];
							}
							for(int f = 0; f < 10; f++){
								if(f < 9){
									dp[a][b][c][d][e][f + 1] = dp[a][b][c][d][e][f] + price[5];
								}
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
}
