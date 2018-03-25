#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX 100000

int gcd(long long int a, long long int b){
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

int main(){
	long long int a, b, c, d;
	float n;
	long long int m;
	int arr[2][MAX], arrCount = 0;
	while(scanf("%d %d %f", &a, &b, &n) != EOF){
		memset(arr, 0, MAX * 2);
		arrCount = 0;
		for(m = ceil(1.0/b/n); m < MAX; m++){
			int div = gcd(a * m + 1, b * m);
			if((d = (b * m) / div) < MAX){
				c = (a * m + 1) / div;
				arr[0][arrCount] = c;
				arr[1][arrCount++] = d;
				printf("%d %d\n", d, m);
			}
		}
		for(int i = 0; i < arrCount; i++){ // find minimal d
			if(d > arr[1][i]){
				d = arr[1][i];
				c = arr[0][i];
			}
		}
		printf("%d %d\n", c, d);
		exit(0);
	}
}
