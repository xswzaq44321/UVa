#include <cstdio>
#include <algorithm>
#define SIZE 110

int N;
int n, m;
int set[SIZE];
struct Edge{
	int a, b;
	int len;
}edge[SIZE * SIZE];

int find(int x){
	if(x == set[x]){
		return x;
	}
	return set[x] = find(set[x]);
}

void Union(int x, int y){
	int X = find(x);
	int Y = find(y);
	set[Y] = X;
}

void init(){
	for(int i = 0; i < n; ++i){
		set[i] = i;
	}
	for(int i = 0; i < m; ++i){
		edge[i] = {0, 0, 0};
	}
}

int main(){
	scanf("%d", &N);
	for(int cases = 1; cases <= N; ++cases){
		scanf("%d %d", &n, &m);
		init();
		for(int i = 0; i < m; ++i){
			scanf("%d %d %d", &edge[i].a, &edge[i].b, &edge[i].len);
		}

		std::sort(edge, edge + m, [](Edge a, Edge b){
			return (a.len > b.len);
		});
		for(int i = 0; i < m; ++i){
			fprintf(stderr, "[%d %d %d]\n", edge[i].a, edge[i].b, edge[i].len);
		}
		int min = 1e8;
		for(int i = 0, branchCount = 0; branchCount != n - 1; ++i){
			if(find(edge[i].a) != find(edge[i].b)){
				if(edge[i].len < min){
					min = edge[i].len;
				}
				Union(edge[i].a, edge[i].b);
				++branchCount;
			}
		}
		printf("Case #%d: %d\n", cases, min);
	}
}
