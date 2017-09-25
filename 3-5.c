#include <stdio.h>
#include <string.h>


void reverse(char s[]);
void itob(int n, char s[], int b);

int main()
{
	int number = -1234;
	char string[100];
	int base = 16;
	itob(number, string, base);
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

/*itob: convert n to characters in s - base b*/
void itob(int n, char s[], int b)
{
	int i, j, sign;
	void reverse(char s[]);

	/* if n is a negative integer then make it positive */
	if((sign = n) < 0)
	{
		n = -n;
	}
	
	/* if the base is not higher than 10 then keep the same otherwise make it abcdef.....*/
	/* Notice that here we generate digits in reverse order and add the '-' to the end and finally reverse it.*/
	i = 0;
	do
	{
		j = n % b;
		s[i++] = (j <= 9) ? j + '0' : j + 'a' - 10;
	}
	while ((n /= b) > 0);

	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';

	reverse(s);
}

