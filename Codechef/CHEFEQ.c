#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int noOperations(int *array, int size, int *count)
{
	bzero(count, sizeof(int) * 100000);
	
	int i, max = -1;
	
	for (i = 0; i < size; i += 1) {
		(*(count + *(array + i)))++;
	}
	
	for (i = 0; i < 100000; i += 1) {
		if (*(count+i) > max) {
			max = *(count + i);
		}
	}
	
	return size - max;
}

int main (int argc, char *argv[])
{
	int t, n;
	int *a = malloc(sizeof(int) * 100000);
	int *count = malloc(sizeof(int) * 100000);
	
	int i;
	
	scanf("%d", &t);
	
	while (t--) {
		scanf("%d", &n);
		
		for (i = 0; i < n; i += 1) {
			scanf("%d", a+i);
		}
		
		printf("%d\n", noOperations(a, n, count));
	}
	
	free(a);
	free(count);
	
	return 0;
}
