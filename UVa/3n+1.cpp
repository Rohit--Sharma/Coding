#include <stdio.h>

int cycleLength(int a)
{
	int ans = 1;
	while (a != 1) {
		if (a % 2) {
			a = 3*a + 1;
			a >>= 1;
			ans += 2;
		} else {
			a >>= 1;
			ans++;
		}
	}	
	return ans;
}

int maxCycleLength(int x, int y)
{
	int temp;
	if (x > y) {
		temp = x; x = y; y = temp;
	}
	
	int ans = -1;
	
	for (unsigned int i = x; i <= y; i += 1) {
		if ((temp = cycleLength(i)) > ans) {
			ans = temp;
		}
	}
	
	return ans;
}

int main (int argc, char const* argv[])
{
	int i, j;
	
	while (scanf("%d%d", &i, &j) != EOF) {
		
		printf("%d %d %d\n", i, j, maxCycleLength(i, j));
	}
	
	return 0;
}
