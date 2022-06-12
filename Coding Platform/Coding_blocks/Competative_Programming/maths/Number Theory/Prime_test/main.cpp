/*#include <iostream>

using namespace std;

bool prime_check(int n)
{
    if(n<=1)
        return false;
    for(int i=2;i*i<=n;i++)
        if(n%i==0)
            return false;
        return true;
}

int main()
{
    int n;
    cin>>n;

    if(prime_check(n))
        cout<<"True";
    else
        cout<<"False";

    return 0;
}*/
#include<iostream>
using namespace std;

void prime_factorisation(int n)
{
    int i,x;
    x=n;
    for(i=2;i<=x/2;i++)
    {
        if(n%i==0)
            cout<<i<<" ";
        while(n%i==0)
            n=n/i;

    }
}

int main()
{
int n;
cin>>n;
prime_factorisation(n);

}
