#include <cstdio>
#include <cstring>
#include <vector>
#define SIZE 3000

int llink[SIZE], rlink[SIZE]; // no touching
bool used[SIZE]; // no touching
std::vector<int> edge[SIZE]; // begin at 1

// Augumenting Path
bool DFS(int now){
	int next;

	// Try all vetices on the right side
	for(int i = 0; i < (int)edge[now].size(); ++i){
		next = edge[now][i];

		// Visit once only
		if(!used[next]){
			used[next] = true;

			// Unmatched vertex, or augumenting path found
			if(!rlink[next] || DFS(rlink[next])){
				// Update matching
				llink[now] = next;
				rlink[next] = now;
				return true;
			}
		}
	}

	// No augumenting path is found
	return false;
}

// Maximum Bipatite Matching
int Bipartite(int nL, int nR){
	int ans = 0;

	// Numbering from 1 to nL/nR
	memset(llink, 0, (nL + 1)*sizeof(int));
	memset(rlink, 0, (nR + 1)*sizeof(int));

	// Try all vertices on the left side
	for(int i = 1; i <= nL; ++i){
		// Visit once only
		memset(used, false, (nR + 1)*sizeof(bool));
		if(DFS(i)) ++ans;
	}
	return ans;
}

int main(){
	int N;
	scanf("%d", &N);
	for(int n = 1; n <= N; ++n){
		int u, v;
		scanf("%d %d", &u, &v);
		for(int i = 0; i < u; ++i){
			for(int j = 0; j < v; ++j){
				int flag;
				scanf("%d", &flag);
				if(flag){
					edge[1 + i].push_back(1 + j);
				}
			}
		}

		printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n", n, Bipartite(u, v));

		for(int i = 0; i <= u; ++i){
			edge[i].clear();
		}
	}
}
