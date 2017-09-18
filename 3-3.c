#include <stdio.h>
#include <string.h>

void shellsort(int v[], int n);
void reverse(char s[]);
void expand(char s1[], char s2[]);

int main()
{
	char first[3] = "A-H";
	char second[100];
	
	expand(first, second);

	printf("%s\n", second);

	return 0;
}

void shellsort(int v[], int n)
{
	int gap, i, j, temp;
	
	for(gap = n/2; gap > 0; gap /= 2)
		for(i = gap; i < n; i++)
			for(j = i - gap; j >= 0 && v[j] > v[j + gap]; i -= gap)
			{
				temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
			}
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


/* Expand: expand shorthand notations in s1 into string s2 */
void expand(char s1[], char s2[])
{
	char c;
	int i, j;
	
	i = j = 0;
	while((c = s1[i++]) != '\0')
		if(s1[i] == '-' && s1[i + 1] >= c)
		{
			i++;
			while(c < s1[i])
			{
				s2[j++] = c++;
			}
		}
		else
		{
			s2[j++] = c;
		}
	s2[j] = '\0';
}
