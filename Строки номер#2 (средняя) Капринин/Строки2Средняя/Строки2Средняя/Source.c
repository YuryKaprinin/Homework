#include <stdio.h>
#include <string.h>
void f(char* s)
{
	for (int i = 0; i < strlen(s); ++i)
	{
		s[i] = tolower(s[i]);//Функция преобразования в строчные буквы
	}
}

int main()
{

	char s[100];
	gets(s);
	f(s);
	printf("%s", s);
	return 0;
}