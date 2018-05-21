#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#define SIZE 100
#define PRIME_MOD 1073676287

using namespace std;

typedef long long int lli;
char s[1000000];
lli h[1000000], hBase[1000000];
char s2[200][SIZE];
lli h2[200][SIZE], hBase2[200][SIZE];
void hashInit(char *s, lli *h, lli *hBase, int len, lli prime = 0xdefaced){
	hBase[0] = 1;
	for(int i = 1; i <= len; ++i){
		h[i] = (h[i - 1] * prime + s[i - 1]) % PRIME_MOD;
		hBase[i] = (hBase[i - 1] * prime) % PRIME_MOD;
	}
}

lli getHash(lli *h, lli *hBase, int a, int b){
	return (h[b + 1] - (h[a] * hBase[b - a + 1]) % PRIME_MOD + PRIME_MOD) % PRIME_MOD;
}

int main(){
	while(1){
		int n;
		scanf("%d ", &n);
		if(n == 0){
			break;
		}
		for(int i = 0; i < n; ++i){
			scanf("%s", s2[i]);
		}
		scanf("%s", s);
		int len = 0;
		int count = 0;
		vector<string> ans;
		for(; s[len]; ++len);
		hashInit(s, h, hBase, len);
		for(int i = 0; i < n; ++i){
			int len2 = 0;
			for(; s2[i][len2]; ++len2);
			hashInit(s2[i], h2[i], hBase2[i], len2);
			int subCount = 0;
//			fprintf(stderr, "len2 = %d\n", len2);
			for(int j = 0; j <= len - len2; ++j){
				if(getHash(h, hBase, j, j + len2 - 1) == getHash(h2[i], hBase2[i], 0, len2 - 1)){
					++subCount;
				}
			}
			if(count < subCount){
				count = subCount;
				ans.clear();
				ans.push_back(string(s2[i]));
			}else if(count == subCount){
				ans.push_back(string(s2[i]));
			}
		}
		printf("%d\n", count);
//		fprintf(stderr, "ans.size() = %d\n", ans.size());
		for(vector<string>::iterator i = ans.begin(); i != ans.end(); ++i){
			cout << *i << endl;
		}
	}
}
