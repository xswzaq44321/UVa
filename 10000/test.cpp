#include <iostream>
#include <cstdio>
#include <vector>
#define SIZE 110

using namespace std;

int N, M;
int start;
int dis[SIZE];
vector<int>u, v;
//int u[SIZE], v[SIZE];
int caseCount;

void bellmanFord(int source = 0){
	for(int i = 0; i <= N; ++i){
		dis[i] = -1;
	}
	dis[source] = 0;

	for(int i = 0; i < N - 1; ++i){
		for(int j = 0; j < M; ++j){
			int a = u[j], b = v[j];
			if(dis[a] != -1){
				if(dis[a] + 1 > dis[b]){
					dis[b] = dis[a] + 1;
				}
			}
		}
	}
}

int main(){
	while(1){
		u.clear();
		v.clear();
		int a, b;
		cin >> N;
		if(N == 0) break;
		cin >> start;
		for(M = 0; cin >> a >> b && (a != 0 && b != 0); ++M){
			u.push_back(a);
			v.push_back(b);
//			u[M] = a;
//			v[M] = b;
		}
		++caseCount;

		bellmanFord(start);
		int max = 0, end = start;
		for(int i = 1; i <= N; ++i){
			if(dis[i] > max){
				max = dis[i];
				end = i;
			}
		}

		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", caseCount, start, max, end);
	}
}
