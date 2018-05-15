#include <cstdio>

int main(){
	int N, cases = 0;
	while(scanf("%d", &N) != EOF && N != 0){
		// a complete undirected graph has n(n-1)/2 edges, & a spanning tree has n-1 edges, so maximum number is n/2
		printf("Case %d: %d\n", ++cases, N / 2);
	}
}
