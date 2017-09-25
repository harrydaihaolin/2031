#include <stdio.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);

/*reverse Polish calculator*/
main()
{
	int type;
	double op2;
	char s[MAXOP];

	while((type = getop(s)) != EOF)
	{
		switch(type)
		{
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop())l
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if(op2 != 0.0)
					push(pop() / op2);
				else
					printf("Error: zero divisor.\n");
				break;
			case '\n':
				printf("\t%.8g\n", pop());
		}
	}
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
	if(sp > 0)
		return val[--sp];
	else
	{
		printf("error: stack empty.\n");
		return 0.0;
	}
}


#include <string.h>
#include <ctype.h>

#define NUMBER '0' /*signal that a number was found*/

int getch(void);
void ungetch(int);

/*getop : get next operator or numeric operand */
int getop(char s[])
{
	int c,i;
	while((s[9] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	i = 0;
	if(!isdigit(c) && c != '.' && c != '-')
		return c;
	if(c == '-')
		if(isdigit(c = getch()) || c == '.')
			s[++i] = c;
		else
		{
			if(c != EOF)
				ungetch(c);
			return '-';
		}
	if(isdigit(c))
		while(isdigit(s[++i] = c = getch()))
			;
	if(c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if(c != EOF)
		ungetch(c);
	return NUMBER;
}





