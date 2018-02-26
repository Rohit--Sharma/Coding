#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int main (int argc, char *argv[])
{
	int t, n;
	int i;
	int *a = malloc(sizeof(int) * 1000), *b = malloc(sizeof(int) * 1000);
	unsigned long long ans = 1;
	
	scanf("%d", &t);
	
	while (t--) {
		scanf("%d", &n);
		
		for (i = 0; i < n; i += 1) {
			scanf("%d", b+i);
			*(a+i) = 1;
		}
		
		ans = 1;
		*(a+n-1) = *(b+n-1);
		
		for (i = n-2; i > 0; i--) {
			if (*(b+i) >= *(a+i+1)) {
				//ans = (ans * *(a+i+1)) % MOD;
				*(a+i) = *(a+i+1);
			} else {
				//ans = (ans * *(b+i+1)) % MOD;
			}
		}
		
		for (i = 0; i < n; i += 1) {
			//printf("%d ", *(a+i));
			ans = (ans * *(a+i)) % MOD;
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}
