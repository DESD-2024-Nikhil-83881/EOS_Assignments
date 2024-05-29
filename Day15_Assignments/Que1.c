#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void* sortarray_func(void *param) {
	int *arr = (int*)param;
	int i, j, *res;
	int  min_idx,n=10;

	for (i = 0; i < n-1; i++)
	{
		min_idx = i;
		for (j = i+1; j < n; j++){
			if (arr[j] < arr[min_idx]){
				min_idx = j;
				}
}
			int temp = arr[min_idx];
		arr[min_idx] = arr[i];
		arr[i] = temp;

	}
	res = (int*)malloc(sizeof(arr));
	res = arr;
	return res;

	}

	int main(){
		int ret, *result;
		int arr[10] = {10,22,33,55,44,55,78,56,45,20};

		pthread_t it;

		ret = pthread_create(&it, NULL, sortarray_func, arr);
		printf("main thread waiting for thread...\n");
		getchar();
		pthread_join(it, (void**) &result);
		for(int i=0; i<10; i++){
			printf("%d\n",arr[i]);
		}
		return 0;
	}
