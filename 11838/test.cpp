#include <iostream>
#include <vector>
#include <cstring>
#define SIZE 2010
#define MIN(a, b) (a < b ? a : b)
using namespace std;

vector<int> stk;
bool inStk[SIZE];
int adjMatrix[SIZE][SIZE];
int scc[SIZE];
int N, M;
int V, W, P;

void DFS1(int i){
	inStk[i] = true;
	for(int j = 1; j <= N; ++j){
		if(adjMatrix[i][j] && !inStk[j]){
			DFS1(j);
		}
	}
	stk.push_back(i);
}

void DFS2(int i, int c){
	scc[i] = c;
	inStk[i] = true;
	for(int j = 1; j <= N; ++j){
		if(adjMatrix[j][i] && !inStk[j]){
			DFS2(j, c);
		}
	}
}

void kosaraju(){
	int c = 1;
	memset(inStk, false, sizeof(inStk));
	for(int i = 1; i <= N; ++i){
		if(!inStk[i]){
			DFS1(i);
		}
	}
	memset(inStk, false, sizeof(inStk));
	for(int i = N; i > 0; --i){
		if(!inStk[stk[i]]){
			DFS2(stk[i], c++);
		}
	}
}

void initial(){
	stk.clear();
	stk.push_back(0); // trash data
	for(int i = 0; i < SIZE; ++i){
		inStk[i] = false;
		for(int j = 0; j < SIZE; ++j){
			adjMatrix[i][j] = 0;
		}
		scc[i] = 0;
	}
}

int main(){
	while(1){
		bool G = true;
		initial();
		cin >> N >> M;
		if(N == 0 && M == 0) break;
		for(int i = 0; i < M; ++i){
			cin >> V >> W >> P;
			adjMatrix[V][W] = 1;
			if(P == 2){
				adjMatrix[W][V] = adjMatrix[V][W];
			}
		}

		kosaraju();

		for(int i = 1; i <= N; ++i){
			//cout << scc[i] << " ";
			if(scc[i] == 2){
				G = false;
			}
		}
		//cout << endl;
		cout << (G ? 1 : 0) << endl;
	}
}
