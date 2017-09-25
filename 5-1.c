#include <stdio.h>
#include <ctype.h>

/*getint: get next integer from input into *pm */
int getint(int *pm)
{
	int c, sign;
	
	while(isspace(c = getch()))
		;

	if(!isdigit(c) && c != EOF && c != '+' && c != '-')
	{
		ungetch(c);
		return 0;
	}
}
