#include <stdio.h>
#include <string.h>
int f(char* s)
{
	int n = 0;
	int len = strlen(s);
	for (int i = 0; i < len; ++i)
	{
		if ((s[i] > 47) && (s[i] < 58))
		{
			n++;
		}
	}
	return n;
}

int main()
{
	int a = 0;
	char s[100];
	gets(s);
	printf("%d", f(s));
	return 0;
}