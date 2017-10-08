#include <stdio.h>

static void strCat(char *s, char *t);

static void strCat(char *s, char *t)
{
	while(*s)
		s++;
	while(*s++ = *t++)
		;
}	

int main()
{
	char *s = "Hello";
	char *t = " World";
	strCat(s,t);
	printf("%s\n", s);
	return 0;
}
