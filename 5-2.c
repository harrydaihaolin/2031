#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

/*getfloat: get next floating-point number from input*/
int getfloat(float *pn)
{
	float c, sign;
	float power;

	while(isspace(c = getch()))
		;

	if(!isdigit(c) && c != EOF && c != '+' && c != '-')
	{
		ungetch(c); /*it's not a number*/
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if(c == '+' || c == '-')
		c = getch();
	for(*pn = 0.0; isdigit(c); c = getch())
		*pn = 10.0 * *pn + (c - '0'); /*integer part*/
	if(c == '.')
	 	c = getch();
	for(*pn = 0.0; isdigit(c); c = getch())
		*pn = 10.0 * *pn + (c - '0'); /*fraction part*/
	*pn *= sign / power;
	if(c != EOF)
		ungetch(c);
	return c;
}


