#include <stdio.h>
#include <string.h>

int main (int argc, char const* argv[])
{
	int n, nValPrinted;
	int ages[100];
	short temp;
	
	scanf("%d", &n);
	while (n != 0) {
		bzero(ages, sizeof(ages));
		nValPrinted = 0;
		for (unsigned int i = 0; i < n; i += 1) {
			scanf("%hd", &temp);
			ages[temp - 1]++;
		}
		
		for (unsigned int i = 0; i < 100; i += 1) {
			while (ages[i]--) {
				printf("%d", i+1);
				if (nValPrinted < n-1) {
					putchar(' ');
				}
				nValPrinted++;
			}
		}
		
		putchar('\n');
		
		scanf("%d", &n);
	}
	
	return 0;
}
