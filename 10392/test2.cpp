#include <iostream>
#include <cstring>
#include <math.h>
#define MAX 1000000000

using namespace std;
bool is_prime[MAX];
void eratosthenes(){
	memset(is_prime, 1, sizeof(is_prime));
	is_prime[0] = false;
	is_prime[1] = false;

	for(int i = 2; i <= sqrt(MAX); i++){
		if(is_prime[i]){
			for(int j = i + i; j < MAX; j += i){
				is_prime[j] = false;
			}
		}
	}
}

int main(){
	eratosthenes();
	long long int N;
	while(cin >> N){
		for(int i = 0; i <= N && N != 1; i++){
			if(!is_prime[i]) continue;
			for(; N % i == 0; N /= i){
				printf("    %-d\n", i);
			}
		}
	}
}
