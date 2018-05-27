#include <cstdio>
#include <cstring>
#define MIN(a, b) (a < b ? a : b)
#define INF 0x3fffffff
#define SIZE 300

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
	for(int i = 0; i <= 2*N + 1; ++i){
		for(int j = 0; j <= 2*N + 1; ++j){
			cap[i][j] = 0;
			flow[i][j] = 0;
		}
	}
}

int main(){
	int c;
	int B, D;
	int ans;
	while(scanf("%d", &N) != EOF){
		for(int i = 1; i <= N; ++i){
			scanf("%d", &cap[2 * i - 1][2 * i]);
		}
		scanf("%d", &c);
		for(int i = 0; i < c; ++i){
			int a, b, temp;
			scanf("%d %d %d", &a, &b, &temp);
			cap[2*a][2*b - 1] += temp;
		}
		scanf("%d %d", &B, &D);
		for(int i = 0; i < B; ++i){
			int b;
			scanf("%d", &b);
			cap[0][2 * b - 1] = INF;
		}
		for(int i = 0; i < D; ++i){
			int a;
			scanf("%d", &a);
			cap[2*a][2*N + 1] = INF;
		}

		ans = fordFulkerson(0, 2*N + 1, 2*N + 1);

		printf("%d\n", ans);
		init();
	}
}
