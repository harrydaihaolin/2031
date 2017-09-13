#include <stdio.h>

int main()
{
	return 0;
}

void squeeze(char[] s1, char[] s2)
{
	int i, j, k;
	
	/* as long as s1 is a not a null character */
	for(i = k = 0; s1[i] != '\0'; i++) 
	{
		/* as long as string s2 starts in not null characters and also characters are not the same. */
		for(j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++) 
			;
		/* If s2 characters are null then it means it is not copied to the resulting string  */
		if(s2[j] == '\0')
			s1[k++] = s1[i];
	}
	s1[k] = '\0';
	
}
