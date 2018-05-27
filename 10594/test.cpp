#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#define INF 0x3fffffff
#define SIZE 110
#define MIN(a, b) (a < b ? a : b)

long long int dis[SIZE], parent[SIZE];
long long int cap[SIZE][SIZE], flow[SIZE][SIZE], cost[SIZE][SIZE];
bool inqueue[SIZE];
std::vector<int> edge[SIZE];
std::queue<int> que;
long long int N, M;
long long int D, K;

bool SPFA(long long int source, long long int sink){
	for(long long int i = 0; i <= N; ++i){
		dis[i] = INF;
		inqueue[i] = false;
	}
	dis[source] = 0;
	inqueue[source] = true;
	que.push(source);
	while(!que.empty()){
		long long int u = que.front();
		inqueue[u] = false;
		que.pop();
		for(long long int v : edge[u]){
			if(flow[v][u] > 0 && dis[u] - cost[v][u] < dis[v]){
				dis[v] = dis[u] - cost[v][u];
				parent[v] = u;
				if(!inqueue[v]){
					que.push(v);
					inqueue[v] = true;
				}
			}else if(cap[u][v] > flow[u][v] && dis[u] + cost[u][v] < dis[v]){
				dis[v] = dis[u] + cost[u][v];
				parent[v] = u;
				if(!inqueue[v]){
					que.push(v);
					inqueue[v] = true;
				}
			}
		}
	}
	if(dis[sink] == INF){
		return false;
	}else{
		return true;
	}
}

long long int MCMF(long long int source, long long int sink){
	long long int minCost = 0;
	while(SPFA(source, sink)){
		minCost += (D > K ? K * dis[sink] : D * dis[sink]);
		D -= K;
		for(long long int i = sink; i != source; i = parent[i]){
			long long int pre = parent[i];
			flow[pre][i] += 1;
			flow[i][pre] -= 1;
		}
		if(D <= 0) break;
	}
	return (D > 0 ? -1 : minCost);
}

void init(){
	for(int i = 0; i <= N; ++i){
		for(int j = 0; j <= N; ++j){
			flow[i][j] = 0;
		}
		edge[i].clear();
	}
}

int main(){
	while(scanf("%d %d", &N, &M) == 2){
		init();
		long long int u, v, c;
		for(long long int i = 0; i < M; ++i){
			scanf("%lld %lld %lld", &u, &v, &c);
			edge[u].push_back(v);
			edge[v].push_back(u);
			cost[u][v] = cost[v][u] = c;
			cap[u][v] = cap[v][u] = 1;
		}
		scanf("%lld %lld", &D, &K);

		long long int ans = MCMF(1, N);

		if(ans == -1){
			printf("Impossible.\n");
		}else{
			printf("%lld\n", ans);
		}
	}
}
