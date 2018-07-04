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

bool DFS2(int now){
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
	edge[1].push_back(2);
	edge[2].push_back(2);
	edge[3].push_back(1);
	edge[3].push_back(3);
	edge[3].push_back(4);
	edge[4].push_back(2);
	edge[4].push_back(4);
	edge[5].push_back(4);

	int llinkcpy[SIZE];
	strcpy(llinkcpy, llink);
	for(int i = 1; i <= 5; ++i){
		if(!llinkcpy[i]){
			DFS(i);
		}
	}
}
