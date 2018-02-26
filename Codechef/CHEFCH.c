#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{
	int t;
	char *s = malloc(100000);
	
	int len, ans1, ans2, i;
	
	scanf("%d", &t);
	
	while (t--) {
		scanf("%s", s);
		
		len = strlen(s);
		ans1 = 0; ans2 = 0;
		
		for (i = 0; i < len; i += 2) {
			if (*(s+i) != '-') {
				ans1++;
			}
			if (i+1 < len && *(s+i+1) != '+') {
				ans1++;
			}
			if (*(s+i) != '+') {
				ans2++;
			}
			if (i+1 < len && *(s+i+1) != '-') {
				ans2++;
			}
		}
		if (ans1 < ans2) {
			printf("%d\n", ans1);
		} else {
			printf("%d\n", ans2);
		}
	}
	
	return 0;
}
