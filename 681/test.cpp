#include <cstdio>
#include <cmath>
#include <algorithm>
#define SIZE 1000

// P為平面上散佈的點。
// CH為凸包上的頂點。設定為逆時針方向排列。可以視作一個stack。
struct Point {int x, y;} P[SIZE], CH[SIZE+1];
int N;

// 向量OA叉積向量OB。大於零表示從OA到OB為逆時針旋轉。
double cross(Point o, Point a, Point b)
{
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

// 小於。依座標大小排序，先排 y 再排 x。
bool compare(Point a, Point b)
{
	return (a.y < b.y) || (a.y == b.y && a.x < b.x);
}

int Andrew_monotone_chain()
{
	// 將所有點依照座標大小排序
	std::sort(P, P+N, compare);

	int m = 0;  // m 為凸包頂點數目

	// 包下半部
	for (int i=0; i<N; ++i)
	{
		while (m >= 2 && cross(CH[m-2], CH[m-1], P[i]) <= 0) m--;
		CH[m++] = P[i];
	}

	// 包上半部，不用再包入方才包過的終點，但會再包一次起點
	for (int i=N-2, t=m+1; i>=0; --i)
	{
		while (m >= t && cross(CH[m-2], CH[m-1], P[i]) <= 0) m--;
		CH[m++] = P[i];
	}

	if(N == 1){
		CH[m++] = P[0];
	}

//	m--;    // 最後一個點是重複出現兩次的起點，故要減一。
	return m;
}

void init(){
	for(int i = 0; i <= N + 1; ++i){
		P[i].x = 0;
		P[i].y = 0;
		CH[i].x = 0;
		CH[i].y = 0;
	}
}

int main(){
	int K;
	scanf("%d", &K);
	printf("%d\n", K);
	for(int Case = 0; Case < K; ++Case){
		scanf("%d", &N);
		init();
		for(int i = 0; i < N; ++i){
			scanf("%d %d", &P[i].x, &P[i].y);
		}
		scanf("%*d");

		int m = Andrew_monotone_chain();

		printf("%d\n", m);
		for(int i = 0; i < m; ++i){
			printf("%d %d\n", CH[i].x, CH[i].y);
		}
		if(Case < K - 1){
			printf("%d\n", -1);
		}
	}
}
