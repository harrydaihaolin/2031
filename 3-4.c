#include <stdio.h>
#include <string.h>


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

/* reverse string s in place */
void reverse(char s[])
{
        int c, i, j;

        for(i = 0, j = strlen(s) - 1; i < j; i++, j--)
        {
                c = s[i];
                s[i] = s[j];
                s[j] = c;
        }
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


