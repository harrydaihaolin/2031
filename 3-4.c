#include <stdio.h>
#include <string.h>
#include "3.h"

void reverse(char s[]);
void itoa(int n, char s[]);

int main()
{
	int number = 1234;
	char string[100];
	itoa(number, string);
	printf("%s\n",string);
	return 0;
}

/* itoa: convert n to chars in s */
void itoa(int n, char s[])
{
	int i, sign;
	
	if((sign = n) < 0)
	{
		n = -n;
	}

	i = 0;
	
	do 
	{
		s[i++] = n % 10 + '0';		
	}
	while ((n /= 10) > 0);

	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s); //reverse the order back to normal.
}


