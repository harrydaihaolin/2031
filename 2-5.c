#include <stdio.h>

int any(char s1[], char s2[]);

int main()
{
	int res = any("sasaar", "Hello World");
	printf("%d\n",res);
	return 0;
}

int any(char s1[], char s2[])
{
	int i, j;
	for(i = 0; s1[i] != '\0'; i++)
	{
		for(j = 0; s2[j] != '\0'; j++)
		{
			if(s1[i] == s2[j])
			{
				return i;
			}
		}
	}
	return -1;
}










