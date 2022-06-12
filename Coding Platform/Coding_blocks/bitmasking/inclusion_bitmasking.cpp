#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define ll long long int
#define mod 1e9+7

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll fxp(ll a,ll b,ll m) {
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp(a*a,b/2,m);
    return fxp(a,b-1,m)*a;
}
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

//QUestion is to find the total no. of numbers less than n which are divisible than prime numbers less than 20;

ll primes[]={2,3,5,7,11,13,17,19};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,res=0;
        cin>>n;
        ll sets=(1<<8)-1; //b/c there are 8 prime numbers and total no. of sub seqences will be 2^8 -1 for excluding empty set.
        for(ll i=1;i<=sets;i++)
        {
            ll denom=1;
            ll setbits=__builtin_popcount(i); // built in funtion which returns no. of set bits
            for(ll j=0;j<8;j++)
            {
                if(i&(1<<j))
                    denom*=primes[j];
            }
            if(setbits&1)
            {
                res+=n/denom;
            }
            else
            {
                res-=n/denom;
            }
        }
        cout<<res<<endl;
    }
 return 0;
}
