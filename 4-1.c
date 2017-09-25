#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length*/

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

/* find all lines matching pattern */
int main()
{
	char line[MAXLINE];
	int found = 0;

	while(getline(line, MAXLINE) > 0)
		if(strindex(line, pattern) >= 0)
		{
			printf("%s", line);
			found++;
		}
		else if(strindex(line, "-exit") >= 0)
		{
			printf("Program exits.\n");
			break;
		}
	return found;
}

/* getline: get line into s, return length */
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

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
	int i, j, k;

	for(i = 0; s[i] != '\0'; i++)
	{
		/* as long as s array is not reaching the end, and k is not the end.*/
		/* try to compare every character if not matched then we skip it.*/
		for(j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++);
		
		/* if searching pattern is not empty and k is in the end. then return the index of s.*/
		if(k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}


/* strrindex return the position of rightmost occurence of t in s, or -1 if there is none. */
int strrindex(char s[], char t[])
{
	int i, j, k;
	
	pos = -1;
	for(i = 0; s[i] != '\0' ; i++)
	{
		for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);

		if(k > 0 && t[k] == '\0')
			pos = i;
	}
	return pos;
}

#include <string.h>

/*more efficient way.*/
int strrindex_2(char s[], char t[])
{
	int i,j,k;

	/* Compare the last words with the exact length of t array if not matched then step back. */
	for(i = strlen(s) - strlen(t); i >= 0; i--)
	{
		for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);

		if(k > 0 && t[k] == '\0')
			return i;
	}

	return -1;
}














