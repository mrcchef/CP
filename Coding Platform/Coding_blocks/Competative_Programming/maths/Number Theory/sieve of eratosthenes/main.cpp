#include <iostream>
//Default value of global bool is false
//For int it is 0=zero
//char =\u0000
// similarly with float and double 0.0
using namespace std;
int const Nmax=100001;
bool isprime[Nmax];
void total_prime(int n)
{
    int i;
    isprime[0]=isprime[1]=false;
    isprime[2]=true;
    for(i=3;i<=n;i+=2)  // Since all the even numbers are not prime so we are not including them.
        isprime[i]=true;
    for(i=3;i<=n;i+=2)
        if(isprime[i])
            for(int j=i*i;j<=n;j+=i) // Starting with square of prime no. p b/c every previous no. to the p^2 must have a factor smaller prime factor than p; 
                isprime[j]=false;
}
int main()
{
    int limit,i;
    cin>>limit;
    if(limit<=1)
        cout<<"No prime Numbers"<<endl;
    total_prime(limit);
    for(int i=2;i<=limit;i++)
        if(isprime[i])
            cout<<i<<" ";
    return 0;
}
