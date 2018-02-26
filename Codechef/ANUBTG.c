#include <stdio.h>
#include <stdlib.h>

int cmpIntegers(const void *a, const void *b)
{
	return (*(int *)b - *(int *)a);
}

int main (int argc, char *argv[])
{
	int t;
	scanf("%d", &t);
	
	int n, i, total;
	
	int *arr;
	
	while (t--) {
		total = 0;
		
		scanf("%d", &n);
		
		arr = malloc(sizeof(int) * n);
		
		for (i = 0; i < n; i += 1) {
			scanf("%d", arr+i);
		}
		
		qsort(arr, n, sizeof(int), cmpIntegers);

		for (i = 0; i < n; i += 4) {
			if (i < n) {
				total += *(arr+i);
			}
			if (i+1 < n) {
				total += *(arr+i+1);
			}
		}		
		
		printf("%d\n", total);
		
		free(arr);
	}
	
	return 0;
}
