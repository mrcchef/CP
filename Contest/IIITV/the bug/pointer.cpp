// #include <stdio.h>
// #define Size 4
// void pattern(int n,int n2,char arr[]);

// int main()
// {
//     int n;
//     char arr[Size];
//     scanf("%d",&n);
//     int n2 = n*2;
//     int i=0;
//     while(i<4)
//     {
//         scanf("%s",&arr[i]);
//         i++;
//     }
//     pattern(n, n2, arr);
// 	return 0;
// }

// void pattern(int n,int n2,char arr[])
// {
//     float i=0;
//     do
//     {
//         int j=0;
//         while(j<n2)
//         {
//             if(i+j>=n-1 && j<n && i<n)
//                 printf("%c ",arr[0]);
//             else if(j-i<=n && j>=n && i<n)
//                 printf("%c ",arr[1]);
//             else if(i-j<=n && j<n && i>=n)
//                 printf("%c ",arr[2]);
//             else if(i+j<=n2+n-1 && j>=n && i>=n)
//                 printf("%c ",arr[3]);
//             else
//                 printf("  ");
//             j++;
//         }
//         printf("\n");
//         i++;
//     }
//     while(i<n2);
// }

//program to print diamond pattern
#include <stdio.h>
#define Size 4              //Defining constant size 
//Function to print diamond using 4 different symbol
void diamond(int n,int n2,char arr[]);
int main()
{
    int n;
    char arr[Size];             //Initiallizing array
    scanf("%d",&n);             //taking input to define size of pattern
    int n2 = n*2;
    int i=0;
    while(i<Size)                  //loop used input different character 
    {
        scanf("%s",&arr[i]);
        i++;
    }
    diamond(n, n2, arr);      //calling diamond function
	return 0;
}

void diamond(int n,int n2,char arr[])
{
    int i=0;
    do                             //loop used to print diamond pattern
    {
        int j=0;
        while(j<n2)
        { 
            //condition used used to check printing space
            if(i+j>=n-1 && j<n && i<n)
                printf("%c ",arr[0]);
                else if(j-i<=n && j>=n && i<n)
                 printf("%c ",arr[1]);
                 else if(i-j<=n && j<n && i>=n)
                  printf("%c ",arr[2]);
                  else if(i+j<=n2+n-1 && j>=n && i>=n)
                   printf("%c ",arr[3]);
                   else
                       printf("  ");
                   j++;
        }
        printf("\n");
        i++;
    }
    while(i<n2);
}