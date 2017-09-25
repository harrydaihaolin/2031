#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100


/* rudimentary calculator */
int main()
{
	double sum, atof(char []);
	char line[MAXLINE];
	int getline(char line[], int max);

	sum = 0;
	while(getline(line, MAXLINE) > 0)
	{
		printf("\t%g\n", sum += atof(line));
	}	
	return 0;
}

int getline(char s[], int lim)
{
        int c, i;

        i = 0;
        /* if it doesn't reach the limit, and the characters is not EOF*/
        /* and also ensure the search string is not empty line.*/
        while( --lim > 0 && (c = getchar()) != EOF && c != '\n')
                s[i++] = c;
        if(c == '\n')
                s[i++] = c;
        s[i] = '\0';
        return i;
}

/* atof: convert string s to double */
double atof(char s[])
{
	double val, power;
	int i, sign;

	for(i = 0; isspace(s[i]); i++);

	sign = (s[i] == '-') ? -1 : 1; 

	if(s[i] == '+' || s[i] == '-')
		i++;
	for(val = 0.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
	}
	if(s[i] == '.')
		i++;
	for(power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	val =  sign * val / power;
	if(s[i] == 'e' || s[i] == 'E')
	{
		sign = (s[++i] == '-') ? -1 : 1;
		if(s[i] == '+' || s[i] == '-')
			i++;
		for(exp = 0; isdigit(s[i]); i++)
			exp = 10 * exp + (s[i] - '0');
		if(sign == 1)
			while(exp-- > 0)
				val *= 10;
		else
			while(exp-- > 0)
				val /= 10;
	}
	return val;
}


