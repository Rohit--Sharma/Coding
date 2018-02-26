#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int movesToIdealList(int num, long int sum)
{
	int value = 1;
	
	while (num) {
		if ((sum - value) >= num-1) {
			sum -= value;
			num--;
			value++;
		} else {
			return num;
		}
	}
	
	return 0;
}

int main (int argc, char *argv[])
{
	int t, n;
	long int s;
	
	scanf("%d", &t);
	while (t--) {
		scanf("%d%ld", &n, &s);
		
		printf("%d\n", movesToIdealList(n, s));
	}
	
	return 0;
}
