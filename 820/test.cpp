#include <cstdio>
#include <cstring>
#define MIN(a, b) (a < b ? a : b)
#define INF 0x3fffffff
#define SIZE 110

int v[SIZE], pa[SIZE]; // visited, path
int cap[SIZE][SIZE], flow[SIZE][SIZE];
int N;

bool DFS(int cur, int t, int n){
	v[cur] = 1;
	if(cur == t) return true;
	for(int i = 1; i <= n; ++i){
		if(v[i]) continue;

		if(cap[cur][i] - flow[cur][i] > 0 || flow[i][cur] > 0){
			pa[i] = cur;
			if(DFS(i, t, n)){
				return true;
			}
		}
	}
	return false;
}

int findFlow(int s, int t, int n){
	int pre;
	int f = INF;

	for(int i = t; i != s; i = pa[i]){
		pre = pa[i];

		if(cap[pre][i] - flow[pre][i] > 0){
			f = MIN(f, cap[pre][i] - flow[pre][i]);
		}else{
			f = MIN(f, flow[i][pre]);
		}
	}
	for(int i = t; i != s; i = pa[i]){
		pre = pa[i];

		if(cap[pre][i] - flow[pre][i] > 0){
			flow[pre][i] += f;
		}else{
			flow[i][pre] -= f;
		}
	}
	return f;
}

int fordFulkerson(int s, int t, int n){
	int ret = 0;

	while(1){
		memset(v, 0, sizeof(v));
		memset(pa, 0, sizeof(pa));
		if(!DFS(s, t, n)) break;
		ret += findFlow(s, t, n);
	}
	return ret;
}

void init(){
	for(int i = 0; i <= N; ++i){
		for(int j = 0; j <= N; ++j){
			cap[i][j] = 0;
			flow[i][j] = 0;
		}
	}
}

int main(){
	int s, t, c;
	int ans;
	int CASE = 0;
	while(++CASE){
		scanf("%d", &N);
		if(N == 0) break;
		scanf("%d %d %d", &s, &t, &c);
		for(int i = 0; i < c; ++i){
			int a, b, temp;
			scanf("%d %d %d", &a, &b, &temp);
			cap[a][b] += temp;
			cap[b][a] += temp;
		}

		ans = fordFulkerson(s, t, N);

		printf("Network %d\n", CASE);
		printf("The bandwidth is %d.\n\n", ans);
		init();
	}
}
