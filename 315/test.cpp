#include <iostream>
#include <string>
#include <sstream>
#define SIZE 1000
#define MIN(a, b) (a < b ? a : b);
using namespace std;

int low[SIZE], dfn[SIZE];
int dfsn;
int adjMatrix[SIZE][SIZE];
int ans;
int N;

void DFS(int prev, int cur){
	bool cut = false;
	int child = 0;
	low[cur] = dfn[cur] = ++dfsn;
	for(int i = 1; i <= N; ++i){
		int next;
		if(adjMatrix[cur][i] != 0){
			next = i;
		}else{
			continue;
		}
		if(!dfn[next]){
			DFS(cur, next);
			low[cur] = MIN(low[cur], low[next]);
			if(low[next] >= dfn[cur]){
				cut = true;
			}
			++child;
		}else if(next != prev){
			low[cur] = MIN(low[cur], dfn[next]);
		}
	}
	if((child > 1 || prev != -1) && cut){
		++ans;
	}
}

void initial(){
	for(int i = 0; i < SIZE; ++i){
		low[i] = dfn[i] = 0;
		dfsn = 0;
		for(int j = 0; j < SIZE; ++j){
			adjMatrix[i][j] = 0;
		}
		ans = 0;
	}
}

int main(){
	string line;
	char trash;
	while(1){
		initial();
		getline(cin, line);
		stringstream ss(line);
		ss >> N;
		if(N == 0) break;
		for(int i = 0; i <= N; ++i){
			int root, leaf;
			getline(cin, line);
			stringstream ss(line);
			ss >> root;
			if(root == 0) break;
			while(ss >> leaf){
				adjMatrix[root][leaf] = adjMatrix[leaf][root] = 1;
			}
		}

		DFS(-1, 1);

		cout << ans << endl;
	}
}
