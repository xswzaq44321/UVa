#include <iostream>
#define SIZE 2010
#define INF 0x7fffffff

using namespace std;

int N, M;
int dis[SIZE];
int w[SIZE];
int u[SIZE], v[SIZE];
int parent[SIZE];
int now;

bool bellmanFord(int source = 0){
	for(int i = 0; i < N; ++i){
		dis[i] = INF;
		parent[i] = 0;
	}
	dis[source] = 0;

	for(int i = 0; i < N - 1; ++i){
		for(int j = 0; j < M; ++j){
			int a = u[j], b = v[j];
			if(dis[a] != INF){
				if(dis[a] + w[j] < dis[b]){
					dis[b] = dis[a] + w[j];
					parent[b] = a;
				}
			}
		}
	}

	for(int i = 0; i < M; ++i){
		int a = u[i], b = v[i];
		if(dis[a] != INF){
			if(dis[a] + w[i] < dis[b]){
//				cerr << "i, a, b = " << i << " " << a << " " << b << endl;
//				cerr << "dis[a], w[i], dis[b] = " << dis[a] << " " << w[i] << " " << dis[b] << endl;
//				for(int j = b; j; j = parent[j]){
//					cerr << j << " ";
//				}
//				cerr << "0" << endl;
				return true;
			}
		}
	}
	return false;
}

int main(){
	int c, temp;
	cin >> c;
	while(c--){
		cin >> N >> M;
		for(int i = 0; i < M; ++i){
			w[i] = INF;
		}
		for(int i = 0; i < M; ++i){
			cin >> u[i] >> v[i];
			cin >> temp;
			if(temp < w[i]) w[i] = temp;
		}

		cout << (bellmanFord() ? "possible" : "not possible") << endl;
	}
}
