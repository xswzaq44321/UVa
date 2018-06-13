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

bool map[50][50] = {{false}};

int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		int h, w;
		int starCount = 0;
		scanf("%d %d", &h, &w);
		for(int i = 0; i < h; ++i){
			for(int j = 0; j < w; ++j){
				char temp;
				scanf(" %c", &temp);
				map[i][j] = (temp == '*');
				if(temp == '*') ++starCount;
			}
		}
		for(int i = 0; i < h; ++i){
			for(int j = 0; j < w; ++j){
				if(map[i][j]){
					int index1 = (i * w + j) / 2;
					int group = (i + j) % 2;
					if(map[i][j + 1]){
						int index2 = (i * w + j + 1) / 2;
						if(group){
							edge[1 + index2].push_back(1 + index1);
						}else{
							edge[1 + index1].push_back(1 + index2);
						}
					}
					if(map[i + 1][j]){
						int index2 = ((i + 1) * w + j) / 2;
						if(group){
							edge[1 + index2].push_back(1 + index1);
						}else{
							edge[1 + index1].push_back(1 + index2);
						}
//						printf("push %d & %d\n", index1, index2);
					}
				}
			}
		}

		int nL = (h*w + 1) / 2, nR = (h * w) / 2;
//		printf("[%d]", starCount);
		printf("%d\n", starCount - Bipartite(nL, nR));

//		for(int i = 1; i <= nL; ++i){
//			for(auto it:edge[i]){
//				printf("%d ", it);
//			}
//			printf(".\n");
//		}

		for(int i = 0; i <= nL; ++i){
			edge[i].clear();
		}
		memset(map, false, sizeof(map));
	}
}
