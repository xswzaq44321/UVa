#include <stdio.h>
int main(){
	int n;
	int array[10000];

	while(scanf("%d", &n) != EOF){
		for(int i = 0; i < n; i++){
			scanf(" %d", &array[i]);
		}

		int count = 0;
		for(int i = 1; i < n; i++){
			int temp = array[i];
			int j;
			for(j = i - 1; j >= 0; j--){
				if(array[j] > temp){
					array[j + 1] = array[j];
					count++; //one swap
				}else{
					break;
				}
			}
			array[j + 1] = temp;
		}

		//	for(int i = 0; i < n; i++){
		//		printf("%d ", array[i]);
		//	}
		printf("Minimum exchange operations : %d\n", count);
	}
}
