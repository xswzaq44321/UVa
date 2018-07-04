#include <cstdio>
#include <cmath>
#include <algorithm>
#define SIZE 1000

// P�������W���G���I�C
// CH���Y�]�W�����I�C�]�w���f�ɰw��V�ƦC�C�i�H���@�@��stack�C
struct Point {int x, y;} P[SIZE], CH[SIZE+1];
int N;

// �V�qOA�e�n�V�qOB�C�j��s��ܱqOA��OB���f�ɰw����C
double cross(Point o, Point a, Point b)
{
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

// �p��C�̮y�Фj�p�ƧǡA���� y �A�� x�C
bool compare(Point a, Point b)
{
	return (a.y < b.y) || (a.y == b.y && a.x < b.x);
}

int Andrew_monotone_chain()
{
	// �N�Ҧ��I�̷Ӯy�Фj�p�Ƨ�
	std::sort(P, P+N, compare);

	int m = 0;  // m ���Y�]���I�ƥ�

	// �]�U�b��
	for (int i=0; i<N; ++i)
	{
		while (m >= 2 && cross(CH[m-2], CH[m-1], P[i]) <= 0) m--;
		CH[m++] = P[i];
	}

	// �]�W�b���A���ΦA�]�J��~�]�L�����I�A���|�A�]�@���_�I
	for (int i=N-2, t=m+1; i>=0; --i)
	{
		while (m >= t && cross(CH[m-2], CH[m-1], P[i]) <= 0) m--;
		CH[m++] = P[i];
	}

	if(N == 1){
		CH[m++] = P[0];
	}

//	m--;    // �̫�@���I�O���ƥX�{�⦸���_�I�A�G�n��@�C
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
