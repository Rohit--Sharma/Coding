#include <stdio.h>
#include <string.h>

void printReverse(char *str, int len)
{
	while (len) {
		putchar(str[--len]);
	}
	return;
}

int main (int argc, char const* argv[])
{
	char c;
	char buff[512];
	int i;
	
	while((c = getchar()) != EOF) {
		i = 0;
		while (c != ' ' && c != '\n') {
			buff[i++] = c;
			c = getchar();
		}
		printReverse(buff, i);
		putchar(c);
	}
	
	return 0;
}
