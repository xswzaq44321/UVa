#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 500000

long long int count = 0;
int n = 0;
int combined[MAX_SIZE];
void Merge(int list [], int low, int high) {
	int k = 0, mid = (low + high) / 2;
	int i = low, j = mid + 1;
	while (i <= mid && j <= high) {
		if (list[i] < list[j]){
			count += abs(i - low - k);
			combined[k++] = list[i++];
		}
		else{
			count += abs(j - low - k);
			combined[k++] = list[j++];
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
//	for(int i = 0; i < n; i++){
//		printf("%d ", list[i]);
//	}
//	printf("\n");
}

void Mergesort(int list[], int low, int high) {
	if (high > low) {
		Mergesort(list, low, (low + high) / 2);
		Mergesort(list, (low + high) / 2 + 1, high);
		Merge(list, low, high);
	}
}

int main(){
	int array[MAX_SIZE];
	while(1){
		scanf(" %d", &n);
		if(n == 0){
			exit(0);
		}
		for(int i = 0; i < n; i++){
			scanf(" %d", &array[i]);
		}
		count = 0;

		Mergesort(array, 0, n-1);

//		for(int i = 0; i < n; i++){
//			printf("%d ", array[i]);
//		}
		printf("%lld", count / 2);
		printf("\n");
	}
}
