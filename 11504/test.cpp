#include <iostream>
#include <vector>
#include <cstdio>
#include <stack>
#define SIZE 100100
#define MIN(a, b) (a < b ? a : b)

using namespace std;

int dfn[SIZE], low[SIZE];
int dfnc;
stack<int> stk;
bool inStk[SIZE];
vector<int> adj[SIZE];
int scc[SIZE];
int indegree[SIZE];
int N;
int C = 0;

int DFS(int v){
	int top;
	dfn[v] = low[v] = ++dfnc;
	stk.push(v);
	inStk[v] = true;
	for(int i = 0; i < adj[v].size(); ++i){
		int next = adj[v][i];
		if(!dfn[next]){
			DFS(next);
			low[v] = MIN(low[v], low[next]);
		}else if(inStk[next]){
			low[v] = MIN(low[v], dfn[next]);
		}
	}

	if(dfn[v] == low[v]){
		C++;
		indegree[C] = 0;
		do{
			top = stk.top();
			stk.pop();
			inStk[top] = false;
			scc[top] = C;
		}while(top != v);
	}
}

void initial(){
	dfnc = 0;
	while(stk.size()) stk.pop();
	C = 0;
	for(int i = 0; i <= N; ++i){
		dfn[i] = low[i] = 0;
		inStk[i] = false;
		adj[i].clear();
		scc[i] = 0;
	}
}

int main(){
	int cases;
	int n, m;
	int x, y;
	scanf("%d", &cases);
	while(cases--){
		initial();
		scanf("%d %d", &n, &m);
		N = n;
		for(int i = 0; i < m; ++i){
			scanf("%d %d", &x, &y);
			adj[x].push_back(y);
		}

		for(int i = 1; i <= N; ++i){
			if(!dfn[i]){
				DFS(i);
			}
		}
		for(int i = 1; i <= N; ++i){
			for(int j = 0; j < adj[i].size(); ++j){
				int v = adj[i][j];
				if(scc[i] != scc[v]){
					indegree[scc[v]]++;
				}
			}
		}

		int ans = 0;
		for(int i = 1; i <= C; ++i){
			if(indegree[i] == 0){
				ans++;
			}
		}
		printf("%d\n", ans);
	}
}
