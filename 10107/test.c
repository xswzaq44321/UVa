#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
	return (*(int*)a - *(int*)b);
}

int main(){
	int arr[10000] = {0};
	int count = 0, median = 0;
	for(; scanf(" %d", &arr[count]) != EOF; count++){
		qsort(arr, count + 1, sizeof(int), compare);
		if(count % 2){ // is even
			median = (arr[count / 2] + arr[count / 2 + 1]) / 2;
		}else{ // is odd
			median = arr[count / 2];
		}
		printf("%d\n", median);
	}
}
