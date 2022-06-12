// corrected
#include <stdio.h>
void pattern (int n, int n2, char arr[]);
int main ()
{
    int n;
    char arr[4]={'@','#','$','%'};
    scanf("%d", &n);
    
    int n2 = n * 2;
    int i = 0;
    pattern (n, n2, arr);
    return 0;
}

void pattern (int n, int n2, char arr[])
{
    int i = 0;
    int j=0;
    char res[n2][n2];
    do
    {
        do
	    {
            if(i==j || i+j+1==n2)
                res[i][j]='?';
	        else if (i>=j && j < n && i < n)
                res[i][j]=arr[0];
	        else if (i+j>=n2-1 && j >= n && i < n) 
	            res[i][j]=arr[1];
	        else if (i+j <= n2-1 && j < n && i >= n)
	            res[i][j]=arr[2];
	        else if ( j>=i && j >= n && i >= n)
	            res[i][j]=arr[3];
	        else
                res[i][j]=' ';
	        j++;
            j%=n2;
	    }
        while(j!=0);
        i++;
    }
    while (i < n2);

    for(i=0;i<n2;i++)
    {
        for(j=0;j<n2;j++)
        {
            printf("%c ",res[i][j]);
        }
        printf("\n");
    }
}

// // bugged
// #include <stdio.h>
// void pattern (int n, int n2, char arr[]);
// int main ()
// {
//     int n;
//     char arr[4]={'@','#','$','%'};
//     scanf("%d", &n);
    
//     int n2 = n * 2;
//     int i = 0;
//     pattern (n, n2, arr);
//     return 0;
// }

// void pattern (int n, int n2, char arr[])
// {
//     int i = 0;
//     int j=0;
//     char res[n2][n2];
//     do
//     {
//         do
// 	    {
//             if(i==j || i+j+1==n2)
//                 res[i][j]='?';
// 	        if (i>=j && j < n && i <= n)
//                 res[i][j]=arr[0];
// 	        else if (i+j>=n2-1 && j >= n && i < n) 
// 	            res[i][j]=arr[1];
// 	        else if (i+j+1 <= n2 && j < n && i >= n)
// 	            res[i][j]=arr[2];
// 	        else if ( j>=i && j >= n && i >= n)
// 	            res[i][j]=arr[1];
// 	        else
//                 res[i][j]=' ';
// 	        j++;
//             j%=n2;
// 	    }
//         while(j!=0);
//         i++;
//     }
//     while (i < n2);

//     for(i=0;i<n2;i++)
//     {
//         for(j=0;j<n2;j++)
//         {
//             printf("%c ",res[i][j]);
//         }
//         printf("\n");
//     }
// }