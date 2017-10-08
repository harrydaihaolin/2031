#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define BUFSIZE 100

static char buf[BUFSIZE];
static int bufp = 0;
int getch(void);
void ungetch(int);

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

/*getint: get next integer from input into *pm*/
/****************** 
* In this case it treats + or - not followed by a digit as a valid
* representation of zero.	
******************/
static int getint(int *pn)
{
	int c, d, sign;

	/*skip white space*/	
	while(isspace(c = getch()))
		;

	if(!isdigit(c) && c != EOF && c != '+' && c != '-')
	{
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if(c == '+' || c == '-')
	{
		d = c; /*remember sign char*/
		if(!isdigit(c = getch()))
		{
			if(c != EOF) /*push back non-digit*/
				ungetch(c); /*push back sign char*/
			ungetch(c); 
			return d; /*return sign char*/
		}
	}
	for(*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if(c != EOF)
		ungetch(c);
	return c;
}




