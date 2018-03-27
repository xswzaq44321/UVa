#include <stdio.h>

int main(){
	int summand, addend;
	while(1){
		scanf("%d %d", &summand, &addend);
		if(summand == 0 && addend == 0){
			break;
		}

		int carry = 0, count = 0;
		for(int a = summand, b = addend; a || b; a /= 10, b /= 10){
			carry = (a % 10 + b % 10 + carry) / 10;
			if(carry){
				++count;
			}
		}

		count ? printf("%d", count) : printf("No");
		printf(" carry operation");
		printf(count > 1 ? "s.\n" : ".\n");
	}
}
