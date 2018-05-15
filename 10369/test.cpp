#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int N, S, P;
int set[550];
double usedEdges[550];
struct Point{
	int x, y;
}point[550];
struct Edge{
	int a, b;
	double len;
}edge[550 * 550];

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
	for(int i = 0; i < P; ++i){
		usedEdges[i] = 0;
		point[i] = {0, 0};
		edge[i] = {0, 0, 0};
		set[i] = i;
	}
}

int main(){
	scanf("%d", &N);
	while(N--){
		int edgeCount = 0;
		scanf("%d %d", &S, &P);
		init();
		for(int i = 0; i < P; ++i){
			scanf("%d %d", &point[i].x, &point[i].y);
		}

		for(int i = 0; i < P; ++i){
			for(int j = i + 1; j < P; ++j){
				edge[edgeCount++] = {i, j, sqrt(pow(point[i].x - point[j].x, 2) + pow(point[i].y - point[j].y, 2))};
			}
		}
		sort(edge, edge + edgeCount, [](Edge a, Edge b){
				return (a.len < b.len);
				});
		for(int i = 0, branchCount = 0; branchCount != P - 1; ++i){
			if(find(edge[i].a) != find(edge[i].b)){
				Union(edge[i].a, edge[i].b);
				usedEdges[branchCount] = edge[i].len;
				++branchCount;
			}
		}
		sort(usedEdges, usedEdges + P - 1, [](double a, double b){
				return (a > b);
				});

		printf("%.2f\n", usedEdges[S - 1]);
	}
}
