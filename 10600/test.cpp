#include <cstdio>
#include <algorithm>
#define SIZE 110

int set[SIZE];
int usedEdges[SIZE];
int N, M, Q;
struct Edge{
	int a;
	int b;
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

int prim(){
	int totalCost = 0;
	for(int i = 0; i <= N; ++i){
		set[i] = i;
	}
	for(int n = 1; n < N; ++n){
		int index = 0, len = 1e8;
		for(int i = 0; i < M; ++i){
			if((find(edge[i].a) == Q && find(edge[i].b) != Q)){
				if(edge[i].len < len){
					index = i;
					len = edge[i].len;
				}
			}else if((find(edge[i].a) != Q && find(edge[i].b) == Q)){
				if(edge[i].len < len){
					index = i;
					len = edge[i].len;
				}
			}
		}
		if(find(edge[index].a) == Q){
			Union(edge[index].a, edge[index].b);
		}else{
			Union(edge[index].b, edge[index].a);
		}
		if(len == 1e8){
			return 1e8;
		}
		usedEdges[n] = index;
		totalCost += len;
	}
	return totalCost;
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &N, &M);
		for(int i = 0; i < M; ++i){
			edge[i] = {0, 0, 0};
		}
		for(int i = 0; i <= N; ++i){
			usedEdges[i] = 0;
		}
		for(int i = 0; i < M; ++i){
			scanf("%d %d %d", &edge[i].a, &edge[i].b, &edge[i].len);
		}

		Q = edge[0].a;
		int totalCost = prim(), totalCost2 = 1e8;
		int usedEdgesBak[SIZE];
		for(int i = 1; i < N; ++i){
			usedEdgesBak[i] = usedEdges[i];
		}
		for(int i = 1; i < N; ++i){
			int tempEdge = usedEdgesBak[i];
			Edge temp = edge[tempEdge];
			edge[tempEdge] = {0, 0, 0};
			int min = prim();
			edge[tempEdge] = temp;
			if(min < totalCost2){
				totalCost2 = min;
			}
		}

		printf("%d %d\n", totalCost, totalCost2);
	}
}
