#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <utility>
#define SIZE 1010
#define MIN(a, b) (a < b ? a : b)

using namespace std;

int low[SIZE], dfn[SIZE];
int dfsn;
vector<int> adj[SIZE];
set<pair<int, int>> ans;
int N, M;

void DFS(int prev, int cur){
	int child = 0;
	low[cur] = dfn[cur] = ++dfsn;
	for(vector<int>::iterator idx = adj[cur].begin(); idx != adj[cur].end(); ++idx){
		if(!dfn[*idx]){
			DFS(cur, *idx);
			low[cur] = MIN(low[cur], low[*idx]);
			++child;
			if(low[*idx] > dfn[cur]){
				if(cur < *idx){
					ans.insert(make_pair(cur, *idx));
				}else{
					ans.insert(make_pair(*idx, cur));
				}
			}
		}else if(*idx != prev){
			low[cur] = MIN(low[cur], dfn[*idx]);
		}
	}
}

void init(){
	dfsn = 0;
	ans.clear();
	for(int i = 0; i <= N; ++i){
		low[i] = 0;
		dfn[i] = 0;
		adj[i].clear();
	}
}

int main(){
	int x, y;
	int cases = 0;
	while(++cases){
		init();
		scanf("%d %d", &N, &M);
		if(N == 0 && M == 0) break;
		for(int i = 0; i < M; ++i){
			scanf("%d %d", &x, &y);
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		for(int i = 0; i < N; ++i){
			if(!dfn[i]){
				DFS(-1, i);
			}
		}

		printf("%d", ans.size());
		for(set<pair<int, int>>::iterator it = ans.begin(); it != ans.end(); ++it){
			printf(" %d %d", it->first, it->second);
		}
		printf("\n");
	}
}
