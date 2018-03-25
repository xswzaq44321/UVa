#include <iostream>
#include <vector>
#include <math.h>
#define MAX 10000000
using namespace std;
vector<int> prime;
bool is_prime(int n){
	for(int i = 0; prime[i] * prime[i] <= n; i++){
		if(n % prime[i] == 0){
			return false;
		}
	}
	return true;
}

void make_prime(){
	prime.push_back(2);
	prime.push_back(3);
	for(int i = 5, gap = 2; i < MAX; i += gap, gap = 6 - gap){
		if(is_prime(i))
			prime.push_back(i);
	}
}

int main(){
	make_prime();
	long long int N;
	while(cin >> N){
		if(N == -1) exit(0);
		for(long long int i = 0; N != 1 && i < prime.size(); i++){
			for(; (N % prime[i]) == 0 ; N /= prime[i]){
				printf("    %-d\n", prime[i]);
			}
		}
		if(N != 1){
			printf("    %-lld\n", N);
		}
		printf("\n");
	}
}
