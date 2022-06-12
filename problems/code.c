#include <stdio.h>

int main()
{
    int num;
    printf("Enter a number:");
    scanf(" %d",&num);

    int cntOfBytes=sizeof(int);

    printf("\nNumber of bytes of data type: %d",cntOfBytes);

    printf("\nEntered num: %d",num);

    int cntOfOneBits=0;
    int cntOfZeroBits;

    int totalBits=8*cntOfBytes;

    for(int i=0;i<totalBits;i++)
    {
        if(num&(1<<i))
            cntOfOneBits++;
    }

    cntOfZeroBits=totalBits-cntOfOneBits;

    printf("\nCount of zero bits: %d",cntOfZeroBits);
    printf("\nCount of one bits: %d",cntOfOneBits);

    return 0;
}
