#include <iostream>
#include <cstdio>
#define SIZE 200
#define INF 0x7fffffff
#define MAX(a, b) (a > b ? a : b)

using namespace std;

int dis[SIZE][SIZE];
int C, S, Q;

void floyd(){
	int temp;
	for(int i = 1; i <= C; ++i){
		dis[i][i] = 0;
	}

	for(int k = 1; k <= C; ++k){
		for(int i = 1; i <= C; ++i){
			for(int j = 1; j <= C; ++j){
				temp = MAX(dis[i][k], dis[k][j]);
				if(temp < dis[i][j]){
					dis[i][j] = temp;
				}
			}
		}
	}
}

int main(){
	int start, end, cases = 0;
	int a, b;
	char temp[100];
	while(++cases){
		cin >> C >> S >> Q;
		if(C == 0 && S == 0 && Q == 0){
			break;
		}
		for(int i = 1; i <= C; ++i){
			for(int j = 1; j <= C; ++j){
				dis[i][j] = INF;
			}
		}
		for(int i = 0; i < S; ++i){
			cin >> a >> b;
			cin >> dis[a][b];
			dis[b][a] = dis[a][b];
		}

		floyd();

		if(cases > 1){
			cout << endl;
		}
		cout << "Case #" << cases << endl;
		for(int i = 0; i < Q; ++i){
			cin >> start >> end;
			sprintf(temp, "%d", dis[start][end]);
			cout << (dis[start][end] < INF ? temp : "no path") << endl;
		}
	}
}
