#include <stdio.h>
#define Size 4
void pattern (int n, int n2, char arr[]);
int main ()
{
    int n;
    char arr[Size];
    scanf ("%d", &n);
    int n2 = n * 2;
    int i = 0;
    while (i < 4)
    {
        scanf ("%c", &arr[i]);
        i++;
    }
    pattern (n, n2, arr);
    return 0;
}

void pattern (int n, int n2, char arr[])
{
    int i = 0;
    do
    {
        int j = 0;
        while (j < n2)
	    {
            // printf("i: %d, j: %d",i,j);
	        if (i + j >= n - 1 && j < n && i < n)
	            printf ("%c ", arr[0]);
	        else if (j - i <= n && j >= n && i < n) // 1st mistake
	            printf ("%c ", arr[1]);
	        else if (i - j <= n && j < n && i >= n)
	            printf ("%c ", arr[2]);
	        else if (i + j <= n2 + n - 1 && j >= n && i >= n)
	            printf ("%c ", arr[3]);
	        else
	            printf ("  ");
	        j++;
	    }
        // printf("i: %d",i);
	    
        printf ("\n");
        i++;
    }
    while (i < n2);
}
