#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#define SIZE 300

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
	int n, m, s, v;
	while(scanf("%d %d %d %d", &n, &m, &s, &v) != EOF){
		double gopher[n][2], hole[m][2];
		for(int i = 0; i < n; ++i){
			scanf("%lf %lf", &gopher[i][0], &gopher[i][1]);
		}
		for(int i = 0; i < m; ++i){
			scanf("%lf %lf", &hole[i][0], &hole[i][1]);
		}
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				double r = sqrt(pow(gopher[i][0] - hole[j][0], 2) + pow(gopher[i][1] - hole[j][1], 2));
				if(r / v <= s){
					edge[i + 1].push_back(j + 1);
				}
			}
		}

		int ans = Bipartite(n, m);

		printf("%d\n", n - ans);

		for(int i = 0; i <= n; ++i){
			edge[i].clear();
		}
	}
}
