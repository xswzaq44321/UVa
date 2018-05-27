#include <cstdio>
#include <cstring>
#define MIN(a, b) (a < b ? a : b)
#define INF 0x3fffffff
#define SIZE 1000

int v[SIZE], pa[SIZE]; // visited, parent
int cap[SIZE][SIZE], flow[SIZE][SIZE];
int N;

bool DFS(int cur, int t, int n){
	v[cur] = 1;
	if(cur == t) return true;
	for(int i = 1; i <= n; ++i){
		if(v[i]) continue;

		if(cap[cur][i] - flow[cur][i] > 0 || flow[i][cur] > 0){
			pa[i] = cur;
			if(DFS(i, t, n)) return true;
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
		if(!DFS(s, t, n)) break;
		ret += findFlow(s, t, n);
	}
	return ret;
}

void init(){
	for(int i = 0; i < SIZE; ++i){
		for(int j = 0; j < SIZE; ++j){
			cap[i][j] = flow[i][j] = 0;
		}
	}
}

int main(){
	int CASE;
	scanf("%d", &CASE);
	for(int T = 0; T < CASE; ++T){
		int M, ans;
		scanf("%d %d", &N, &M);
		for(int i = 1; i <= N; ++i){
			int K;
			scanf("%d", &K);
			for(int j = 0; j < K; ++j){
				int sticker;
				scanf("%d", &sticker);
				++cap[i][N + sticker];
			}
		}
		for(int i = 2; i <= N; ++i){
			for(int j = N + 1; j <= N + M; ++j){
				if(cap[i][j]) --cap[i][j];
				else cap[j][i] = 1;
			}
		}
		for(int i = N + 1; i <= N + M; ++i){
			cap[i][N + M + 1] = 1;
		}

		ans = fordFulkerson(1, N + M + 1, N + M + 1);

		printf("Case #%d: %d\n", T + 1, ans);
		init();
	}
}
