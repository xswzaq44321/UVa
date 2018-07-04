#include <cstdio>
#include <cmath>
#include <algorithm>
#define SIZE 1000

// P�������W���G���I�C
// CH���Y�]�W�����I�C�]�w���f�ɰw��V�ƦC�C�i�H���@�@��stack�C
struct Point {double x, y;} P[SIZE], CH[SIZE+1];
int N;

// �V�qOA�e�n�V�qOB�C�j��s��ܱqOA��OB���f�ɰw����C
double cross(Point o, Point a, Point b)
{
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

// �p��C�̮y�Фj�p�ƧǡA���� x �A�� y�C
bool compare(Point a, Point b)
{
	return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}

int Andrew_monotone_chain()
{
	// �N�Ҧ��I�̷Ӯy�Фj�p�Ƨ�
	std::sort(P, P+N, compare);

	int m = 0;  // m ���Y�]���I�ƥ�

	// �]�U�b��
	for (int i=0; i<N; ++i)
	{
		while (m >= 2 && cross(CH[m-2], CH[m-1], P[i]) < 0) m--;
		CH[m++] = P[i];
	}

	// �]�W�b���A���ΦA�]�J��~�]�L�����I�A���|�A�]�@���_�I
	for (int i=N-2, t=m+1; i>=0; --i)
	{
		while (m >= t && cross(CH[m-2], CH[m-1], P[i]) < 0) m--;
		CH[m++] = P[i];
	}

	if(N == 1){
		CH[m++] = P[0];
	}

//	m--;    // �̫�@���I�O���ƥX�{�⦸���_�I�A�G�n��@�C
	return m;
}

void init(){
	for(int i = 0; i <= N; ++i){
		P[i].x = 0;
		P[i].y = 0;
		CH[i].x = 0;
		CH[i].y = 0;
	}
}

int main(){
	for(int Case = 1;;++Case){
		scanf("%d", &N);
		if(N == 0)
			break;
		init();
		for(int i = 0; i < N; ++i){
			scanf("%lf %lf", &P[i].x, &P[i].y);
		}

		int m = Andrew_monotone_chain();
		double len = 0;

		if(Case > 1){
			printf("\n");
		}
		printf("Region #%d:\n", Case);
		for(int i = m - 1; i >= 0; --i){
			if(i != m - 1){
				printf("-");
				len += sqrt(pow(CH[i].x - CH[i + 1].x, 2) + pow(CH[i].y - CH[i + 1].y, 2));
			}
			printf("(%.1lf,%.1lf)", CH[i].x, CH[i].y);
		}
		printf("\n");
		printf("Perimeter length = %.2lf\n", len);
	}
}
