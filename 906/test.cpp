#include <iostream>
#include <string.h>
#define MAX 2147483647

int gcd(long long int a, long long int b){
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

int main(){
	long long int a, b, c, d;
	double n;
	long long int m;
	while(scanf("%lld %lld %lf", &a, &b, &n) != EOF){
		for(d = 1; d < MAX; d++){
			c = (long long int)(d * a) / b + 1;
			//origional : c / d - a / b <= n
			//incase of too small to tell : c / d <= n + a / b
			bool pp = (((long double)c / d) <= n + (long double)a / b);
			if(pp){
				printf("%lld %lld", c, d);
				break;
			}
		}
		printf("\n");
	}
}
