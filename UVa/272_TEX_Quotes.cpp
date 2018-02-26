#include <stdio.h>

int main (int argc, char const* argv[])
{
	bool flag = false;
	char c;

	while((c = getchar()) != EOF) {
		if (c == '"' && !flag) {
			putchar('`'); putchar('`'); flag = true;
		} else if (c == '"' && flag) {
			putchar('\''); putchar('\''); flag = false;
		} else
			putchar(c);
	}
	
	return 0;
}
