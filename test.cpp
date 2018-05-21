#include <cstdio>
#include <cstring>
#include <cstdlib>
#define SIZE 100
#define PRIME_MOD 1073676287

typedef long long int lli;
char s[SIZE];
lli h[SIZE], hBase[SIZE];
void hashInit(char *s, lli *h, lli *hBase, int len, lli prime = 0xdefaced){
	h[0] = 0;
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
	int t;
	scanf("%d\n", &t);
	while(t--){
		scanf("%*[\n]");
		scanf("%s", s);
		int len = 0;
		for(; s[len]; ++len);
		hashInit(s, h, hBase, len);
		for(int i = 1; i <= len; ++i){
			if(len % i){
				continue;
			}
			bool found = true;
			for(int j = i; j <= len - i && found; j += i){
				if(getHash(h, hBase, 0, i - 1) != getHash(h, hBase, j, j + i - 1)){
					found = false;
				}
			}
			if(found){
				printf("%d\n", i);
				break;
			}
			if(i == len){
				printf("%d\n", i);
			}
		}
		if(t){
			printf("\n");
		}
	}
}
