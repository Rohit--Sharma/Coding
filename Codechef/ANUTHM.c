#include <stdio.h>
#include <stdlib.h>

void computeProbabilities(float mat[1001][1001], int r, int c)
{
	int i, j;
	float ans = 0;
	
	mat[1][1] = 1;
	
	for (i = 1; i <= r; i += 1) {
		for (j = 1; j <= c; j += 1) {
			if (i+1 <= r && j+1 <= c) {
				mat[i][j+1] += (mat[i][j] / 2.0);
				mat[i+1][j] += (mat[i][j] / 2.0);
			} else if (j+1 <= c) {
				mat[i][j+1] += mat[i][j];
			} else if (i+1 <= r) {
				mat[i+1][j] += mat[i][j];
			}
		}
	}
	
	for (i = 1; i <= r; i += 1) {
		for (j = 1; j <= c; j += 1) {
			ans += mat[i][j];
			printf("%f ", mat[i][j]);
		}
		printf("\n");
	}
	
	printf("Answer: %f\n", ans);			// or directly r+c-1
}

int main (int argc, char *argv[])
{
	int t, n, m;
	float probMatrix[1001][1001] = {0};
	int i, j;
	
	scanf("%d", &t);
	
	while (t--) {
		scanf("%d%d", &n, &m);
		
		computeProbabilities(probMatrix, n, m);
		
		for (i = 1; i <= n; i += 1) {
			for (j = 1; j <= m; j += 1) {
				probMatrix[i][j] = 0;
			}
		}
	}
	
	return 0;
}
