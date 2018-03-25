#include <iostream>
#include <string>
using namespace std;

int gcd(int a, int b){
	if(a == 0){
		return b;
	}
	return gcd(b % a, a);
}

int main(){
	int STEP, MOD;
	while(cin >> STEP >> MOD){
		string choice = "Bad Choice";
		if(gcd(STEP, MOD) == 1){
			choice = "Good Choice";
		}
		printf("%10d%10d    %s\n\n", STEP, MOD, choice.c_str());
	}
}
