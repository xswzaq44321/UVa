#include <iostream>
#include <vector>
#define SIZE 1010
#define INF 0x7fffffff

using namespace std;

int N, M;
int dis[SIZE];
int w[SIZE][SIZE];
int count[SIZE];
bool inQueue[SIZE];
int now;
vector<int> queue;

bool SPFA(int source = 0){
	for(int i = 0; i < N; ++i){
		dis[i] = INF;
		inQueue[i] = false;
		count[i] = 0;
	}
	dis[source] = 0;
	inQueue[source] = true;
	queue.push_back(source);
	
	while(queue.size()){
		now = queue.at(0);
		inQueue[now] = false;
		queue.erase(queue.begin());
		for(int i = 0; i < N; ++i){
			if(w[now][i] != INF && dis[now] != INF){
				if(dis[now] + w[now][i] < dis[i]){
					dis[i] = dis[now] + w[now][i];
					if(!inQueue[i]){
						queue.push_back(i);
						inQueue[i] = true;
						++count[i];
						if(count[i] >= N) return true;
					}
				}
			}
		}
	}
	return false;
}

int main(){
	int c;
	cin >> c;
	while(c--){
		cin >> N >> M;
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < N; ++j){
				w[i][j] = INF;
			}
		}
		for(int i = 0; i < M; ++i){
			int a, b, temp;
			cin >> a >> b;
			cin >> temp;
			if(temp < w[a][b]) w[a][b] = temp;
		}

		cout << (SPFA() ? "possible" : "not possible") << endl;
	}
}
