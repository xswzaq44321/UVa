#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 999999
using llt = long long int;

llt N, M, D, K;
vector<int> edge[105];
llt cap[105][105], flow[105][105], cost[105][105];
llt pre[105], dis[105];

void Initial();
llt  MCMF(llt S, llt T);
bool SPFA(llt S, llt T);
llt  FindMinFlow(llt S, llt T);
void UpdateFlow(llt S, llt T, llt bottleneck);

int main()
{
    while (scanf("%d %d", &N, &M) == 2) {
        Initial();

        llt u, v, c;
        for (llt i = 0; i < M; ++i) {
            scanf("%lld %lld %lld", &u, &v, &c);
            edge[u].push_back(v);
            edge[v].push_back(u);
            cost[u][v] = cost[v][u] = c;
        }
        scanf("%lld %lld", &D, &K);

        for (llt i = 1; i <= N; ++i)
            for (llt j : edge[i]) cap[i][j] = K;
        edge[0].push_back(1);
        cap[0][1] = D;

        llt result = MCMF(0, N);

        if (result == -1) puts("Impossible.");
        else printf("%lld\n", result);
    }
}
void Initial()
{
    for (llt i = 0; i <= N; ++i)
        edge[i].clear();
    memset(flow, 0, sizeof(flow));
}
llt MCMF(llt S, llt T)
{
    llt max_flow = 0;
    llt min_cost = 0;
    while (SPFA(S, T)) {
        llt ff = FindMinFlow(S, T);
        UpdateFlow(S, T, ff);
        max_flow += ff;
        min_cost += (ff * dis[T]);
    }
    if (max_flow != D) return -1;
    else return min_cost;
}
bool SPFA(llt S, llt T)
{
    fill(begin(dis), end(dis), INF);
    dis[S] = 0;
    queue<int> Q;
    bool inQueue[105] = {0};
    Q.push(S);
    inQueue[S] = true;

    while (!Q.empty()) {
        llt u = Q.front();
        inQueue[u] = false;
        Q.pop();

        for (llt v : edge[u]) {
            if (flow[v][u] > 0 && dis[u] + (-cost[v][u]) < dis[v]) {
                dis[v] = dis[u] + (-cost[v][u]);
                pre[v] = u;
                if (!inQueue[v]) {inQueue[v] = true; Q.push(v);}
            }
            else if (cap[u][v] > flow[u][v] && dis[u] + cost[u][v] < dis[v]) {
                dis[v] = dis[u] + cost[u][v];
                pre[v] = u;
                if (!inQueue[v]) {inQueue[v] = true; Q.push(v);}
            }
        }
    }
    if (dis[T] == INF) return false;
    else return true;
}
llt FindMinFlow(llt S, llt T)
{
    llt bottleneck = INF;
    for (llt u = T; u != S; u = pre[u])
        bottleneck = min(bottleneck, cap[pre[u]][u] - flow[pre[u]][u]);
    return bottleneck;
}
void UpdateFlow(llt S, llt T, llt bottleneck)
{
    for (llt u = T; u != S; u = pre[u]) {
        flow[pre[u]][u] += bottleneck;
        flow[u][pre[u]] -= bottleneck;
    }
}
