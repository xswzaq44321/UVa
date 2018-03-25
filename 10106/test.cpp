#include <iostream>
#include <string.h>
#define BIG_NUM_SIZE 1000

using namespace std;

void addition(short* term, short* summand, short* addend){
	int i, carry = 0;
	for(i = 0; i < BIG_NUM_SIZE; i++){
		term[i] = summand[i] + addend[i] + carry;
		carry = term[i]/10;
		term[i] %= 10;
	}
}

void multiplication(short *result, short *term1, short *term2){
	short temp[BIG_NUM_SIZE];
	short carry;
	for(int i = 0; i < BIG_NUM_SIZE; i++){
		memset(temp, 0, BIG_NUM_SIZE);
		carry = 0;
		for(int j = 0; j < BIG_NUM_SIZE - i; j++){
			temp[j + i] = term1[j] * term2[i] + carry;
			carry = temp[j + i] / 10;
			temp[j + i] %= 10;
		}
		addition(result, result, temp);
	}
}

int main(){
	short X[BIG_NUM_SIZE] = {0}, Y[BIG_NUM_SIZE] = {0}, result[BIG_NUM_SIZE] = {0};
	char tempX[BIG_NUM_SIZE] = {'\0'}, tempY[BIG_NUM_SIZE] = {'\0'};
	for(; scanf("%s %s", tempX, tempY) != EOF; memset(result, 0, BIG_NUM_SIZE), memset(tempX, 0, BIG_NUM_SIZE), memset(tempY, 0, BIG_NUM_SIZE)){
//		printf("tempX = %s, tempY = %s\n", tempX, tempY);
		for(int i = BIG_NUM_SIZE - 1, j = 0, k = 0; i >= 0; i--){
			tempX[i] != 0 ? X[j++] = tempX[i] - '0' : X[i] = 0;
			tempY[i] != 0 ? Y[k++] = tempY[i] - '0' : Y[i] = 0;
		}
		multiplication(result, X, Y);
//		printf("\nresult = ");
		for(int i = BIG_NUM_SIZE - 1, flag = 0; i >= 0; i--){
			if(flag){
				printf("%d", result[i]);
			}else if(result[i] != 0){
				flag = 1;
				printf("%d", result[i]);
			}else if(i == 0){ // if no output at all, output a 0
				printf("0");
			}
		}
		printf("\n");
	}
}
