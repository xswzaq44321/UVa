#include <iostream>
#include <vector>
using namespace std;

int ugly[1500];
vector<int> prime;

bool isPrime(int n){
	for(int i = 0; prime[i] * prime[i] <= n; ++i){
		if(n % prime[i] == 0)
			return false;
	}
	return true;
}

void makePrime(){
	prime.push_back(2);
	prime.push_back(3);
	for(int i = 5, gap = 2; i < 30000; i += gap, gap = 6 - gap){
		if(isPrime(i)){
			prime.push_back(i);
		}
	}
}

bool isUgly(int n){
	for(int i = 3; prime[i] <= n; i++){
		if(!(n % prime[i])) return false;
	}
	return true;
}

void makeUgly(){
	ugly[0] = 1;
	for(int i = 2, count = 1; ugly[1499] == 0; i++){
		if(isUgly(i)){
			ugly[count++] = i;
		}
	}
}

int main(){
	makePrime();
	makeUgly();
	printf("The 1500'th ugly number is %d.", ugly[1499]);
}
