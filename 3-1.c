#include <stdio.h>

int binsearch(int x, int v[], int n);

int main()
{
	int n = 10;
	/* This is not legal in C90 standard, but why?  */
	int arr[n] = {1,2,3,4,5,6,7,8,9,10};
	int x = 2;
	int res = binsearch(x,arr,n);
	printf("%d\n", res);
	return 0;		
}

int binsearch(int x, int v[], int n)
{
	int low, high, mid;

        low = 0;
        high = n - 1;

        while (low <= high)
        {
                mid = (low + high) / 2;
                if(x < v[mid])
                {
                        high = mid - 1;
                }
                else if( x > v[mid])
                {
                        low = mid + 1;
                }
                else
                {
                        return mid;
                }
        }
        return -1;
}
