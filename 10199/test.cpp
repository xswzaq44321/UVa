#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <set>
#define SIZE 1000
#define MIN(a, b) (a < b ? a : b)

using namespace std;

int low[SIZE], dfn[SIZE];
int dfsn;
vector<int> adj[SIZE];
map<string, int> city;
string city_str[SIZE];
set<string> ans;
int N;

void DFS(int prev, int cur){
	bool cut = false;
	int child = 0;
	low[cur] = dfn[cur] = ++dfsn;
	for(int i = 0; i < adj[cur].size(); ++i){
		int next = adj[cur][i];
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
		ans.insert(city_str[cur]);
	}
}

void initial(){
	dfsn = 0;
	city.clear();
	ans.clear();
	city.clear();
	for(int i = 0; i <= N; ++i){
		low[i] = 0;
		dfn[i] = 0;
		adj[i].clear();
	}
}

int main(){
	int cases = 0;
	int R;
	while(++cases){
		initial();
		scanf("%d", &N);
		if(N == 0) break;
		for(int i = 0; i < N; ++i){
			string temp;
			cin >> temp;
			city[temp] = i;
			city_str[i] = temp;
		}
		scanf("%d", &R);
		for(int i = 0; i < R; ++i){
			string temp1, temp2;
			cin >> temp1 >> temp2;
			adj[city[temp1]].push_back(city[temp2]);
			adj[city[temp2]].push_back(city[temp1]);
		}

		for(int i = 0; i < N; ++i){
			if(!dfn[i]){
				DFS(-1, i);
			}
		}

		if(cases != 1){
			cout << endl;
		}
		cout << "City map #" << cases << ": " << ans.size() << " camera(s) found" << endl;
		for(set<string>::iterator it = ans.begin(); it != ans.end(); ++it){
			cout << *it << endl;
		}
	}
}
