#include <stdio.h>
#define SIZE 1010

int combined[SIZE][2];
void Merge(int *list[], int low, int high) {
	int k = 0, mid = (low + high) / 2;
	int i = low, j = mid + 1;
	while (i <= mid && j <= high) {
		if (list[i][0] < list[j][0]){
			count += abs(i - low - k);
			combined[k++] = list[i++];
		}else if(list[i][0] > list[j][0]){
			count += abs(j - low - k);
			combined[k++] = list[j++];
		}else{ // list[i][0] == list[j][0]
			if (list[i][1] < list[j][1]){
				count += abs(i - low - k);
				combined[k++] = list[i++];
			}else if(list[i][1] > list[j][1]){
				count += abs(j - low - k);
				combined[k++] = list[j++];
			}
		}
	}
	while (i <= mid){
		count += abs(i - low - k);
		combined[k++] = list[i++];
	}
	while (j <= high){
		count += abs(j - low - k);
		combined[k++] = list[j++];
	}
	for (i = low, j = 0; i <= high; i++, j++){
		list[i] = combined[j];
	}
}

void Mergesort(int *list[], int low, int high) {
	if (high > low) {
		Mergesort(list, low, (low + high) / 2);
		Mergesort(list, (low + high) / 2 + 1, high);
		Merge(list, low, high);
	}
}

int main(){
	int T;
	int N, M, K;
	int citie[SIZE][2];
	scanf("%d", &T);
	while(T--){
		scanf("%d %d %d", &N, &M, &K);
		for(int i = 0; i < K; i++){
			scanf("%d %d ", &NArr[i], &MArr[i]);
		}
	}
}
