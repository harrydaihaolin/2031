#include <stdio.h>

/*strncpy: copy n characters from t to s*/
void strncpy(char *s, char *t, int n)
{
	for( ; *s && n--; s++)
		*s++ = *t++;
	while(n-- > 0)
		*s++ = '\0';
}

/*strncat: concatenate n characters of t to the end of s*/
void strncat(char *s, char *t, int n)
{
	for( ; *s; s++)
		;
	for( ; *t && n--; t++)
		*s++ = *t++;
}

/*strncmp: compare at most n characters of t with s*/	
int strncmp(char *s, char *t, int n)
{
	for( ; *s == *t; s++, t++)
		/*check if the string is at end or n is at end*/
		if(*s == '\0' || --n < 0)
			return 0;
	return *s - *t;
}


