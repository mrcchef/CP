
//https://cp-algorithms.com/algebra/phi-function.html
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

//Time completixity O(root n) for 1.

ll phi(ll n) {
    ll result = n;
    for (ll i = 2; i * i <= n; i++) { // Basically this approch is based on removal of all the non coprime numbers 
        if (n % i == 0) { // If a no. if divisible by n then all the multiple of the number i must not be coprime with n.
            while (n % i == 0)
                n /= i; // We removed all the multiple of i;
            result -= result / i; //we have subtracted the total no. of numbers which are multiple of n
        }
    }
    if (n > 1)
        result -= result / n; // If n is greator than 1 it means n is prime and divisor of original no. so we will remove all multiple of n; 
    return result;
}

// this is based on a property that This interesting property was established by Gauss:

// ∑d|nϕ(d)=n
// Here the sum is over all positive divisors d of n.

// For instance the divisors of 10 are 1, 2, 5 and 10. Hence ϕ(1)+ϕ(2)+ϕ(5)+ϕ(10)=1+1+4+4=10.
//ϕ(10)=10-(ϕ(1)+ϕ(2)+ϕ(5))
// T.C=O(nlogn)
ll phi_1_to_n(ll n)
{
    ll phi[n+1];
    phi[0]=0;
    phi[1]=1;
    for(ll i=2;i<=n;i++)
        phi[i]=i-1;        // subtracting by ϕ(1)
    for(ll i=2;i<=n;i++)    
    {
        for(ll j=i*2;j<=n;j+=i)
            phi[j]=phi[j]-phi[i]; // subtracting by ϕ(i) to all the multiple of i less than or eqaul to n
    }
    return phi[n];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll res=phi(n);
        cout<<"Factorisation method:"<<res<<endl;
        ll res1=phi_1_to_n(n);
        cout<<"Sieve method:"<<res1<<endl;     
    }
 return 0;
}

