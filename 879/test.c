#include <stdio.h>
#define SIZE 10000

int p[SIZE];

int Find(int x){
	if(x == p[x]) return x;
	return p[x] = Find(p[x]);
}

void Union(int x, int y){
	int X = Find(x);
	int Y = Find(y);

	p[X] = Y;
}

int main(){
	int cases;
	scanf("%d", &cases);
	while(cases--){
		scanf("%d");
	}
}
