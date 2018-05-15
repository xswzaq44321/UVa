#include <cstdio>
#include <algorithm>
#include <cmath>
#define SIZE 110

using namespace std;

struct Point{
	double x;
	double y;
}point[SIZE];
struct Edge{
	int a;
	int b;
	double len;
}edge[SIZE * SIZE];
int N, edgeSize;
double totalCost;
int set[SIZE];

bool cmp(Edge a, Edge b){
	return (a.len < b.len);
}

int find(int x){
	if(x == set[x])
		return x;
	return set[x] = find(set[x]);
}

void init(){
	for(int i = 0; i < N; ++i){
		set[i] = i;
		edge[i] = {0, 0, 0};
		point[i] = {0, 0};
	}
	totalCost = 0;
	edgeSize = 0;
}

void Union(int x, int y){
	int X = find(x);
	int Y = find(y);
	set[X] = Y;
}

int kruskal(){
	sort(edge, edge + edgeSize, cmp);
	for(int i = 0, branchCount = 0; branchCount != N - 1; ++i){
		if(find(edge[i].a) != find(edge[i].b)){
			Union(edge[i].a, edge[i].b);
			totalCost += edge[i].len;
			++branchCount;
		}
	}
}

int main(){
	int cases;
	scanf("%d", &cases);
	while(cases--){
		scanf("%d", &N);
		init();
		for(int i = 0; i < N; ++i){
			scanf("%lf %lf", &point[i].x, &point[i].y);
		}

		for(int i = 0; i < N; ++i){
			for(int j = i + 1; j < N; ++j){
				double len = sqrt(pow(point[i].x - point[j].x, 2) + pow(point[i].y - point[j].y, 2));
				edge[edgeSize++] = {i, j, len};
			}
		}
		kruskal();

		printf("%.2f\n", totalCost);
		if(cases){
			printf("\n");
		}
	}
}
