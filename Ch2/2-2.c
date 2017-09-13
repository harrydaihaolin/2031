#include <stdio.h>

int main()
{	
	int lim = 5;
	char c = 'h';
	char* s; 
	//for(i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
	//Here is a version without using for loop
	enum loop { NO, YES };
	enum loop okloop = YES;
	
	int i = 0;
	while(okloop == YES)
	{
		if( i >=  lim - 1)
			okloop = NO; // outside of valid range.
		else if((c = getchar()) == '\n')
			okloop = NO;
		else if(c == EOF)
			okloop = NO;
		else
		{
			s[i] = c;
			++i;
		}
	}
	return 0;
}
