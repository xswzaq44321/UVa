#include <stdio.h>
#include <string.h>

int Find(int x, int *p){
	if(x == p[x]) return x;
	return p[x] = Find(p[x], p);
}

void Union(int x, int y, int *p){
	int X = Find(x, p);
	int Y = Find(y, p);
	p[X] = Y;
}

int main(){
	int n, m, cases = 1;
	for(; scanf("%d %d", &n, &m) != EOF && (n != 0 || m != 0); cases++){
		int student[n + 1];
		int religion[n + 1];
		int studentI, studentJ;
		int temp, religionCount = 0, duplicated = 0;
		for(int i = 0; i < n + 1; i++){
			student[i] = i;
		}
		memset(religion, 0, n + 1);

		for(int i = 0; i < m; i++){
			scanf("%d %d", &studentI, &studentJ);
			Union(studentI, studentJ, student);
		}

		for(int i = 1; i < n + 1; i++){
			temp = Find(i, student);
			duplicated = 0;

			for(int j = 0; j < religionCount; j++){ //check same group
				if(temp == religion[j]){
					duplicated = 1;
					break;
				}
			}

			if(!duplicated){
				religion[religionCount++] = temp;
			}
		}

		printf("Case %d: %d\n", cases, religionCount);
	}
}
