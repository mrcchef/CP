// Aim to find Numbers whose frequency is 1 in the array
// Idea is to XOR all the elements in set.
// In the result xor, all repeating elements would nullify each other.
// The result would contain the set bits where two non-repeating elements differ.
// 2, 3, 7, 9, 11, 2, 3, 11 Result Xor will contain XOR of 7 and 9 = 14
// (0111 XOR 1001 = 1110)
// Get a number which has only one set bit of the xor.
// Since we can easily get the rightmost set bit, let us use it.

// set_bit_no = xor & ~(xor-1) = (1110) & ~(1101) = 0010
// Now, if we take any set bit of the result xor (set_bit_no) and again do XOR of the subset where that particular bit is set, 
// we get the one non-repeating element.  
// And for other non-repeating element we can take the subset where that particular bit is not set.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,z=0,x=0,y=0;
    cout<<"Enter Size of Array ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        z^=a[i];
    }
    z=z^(z&z-1);
    for(int i=0;i<n;i++)
    {
        if(a[i] & z)
            x^=a[i];
        else
            y^=a[i];
    }
    cout<<x<<" "<<y;
}