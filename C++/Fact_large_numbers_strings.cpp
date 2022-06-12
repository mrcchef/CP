#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
#include <string>
using namespace std;
#define ll long long int
const double mod = 1e9+7;

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

void multiply(ll a[],ll &n,ll num)
{
    // 1230000 multiply by 4
    ll carry=0;
    ll product;
    for(ll i=0;i<n;i++)
    {
        product=(a[i])*num+carry;
        a[i]=product%10;
        carry=product/10;
    }
    // for extra carry 
    while(carry>0)
    {
        a[n]=carry%10;
        carry=carry/10;
        n++;
    }
}

void big_fact(ll number)
{
    ll a[1000]={0};
    a[0]=1;
    ll n=1; // this denotes the no. of indexes which are filled before n
    for(ll i=2;i<=number;i++)
    {
        multiply(a,n,i);
    }

    for(ll i=n-1;i>=0;i--)
        cout<<a[i];
    cout<<endl<<n<<" digits"<<endl;
}

int main()
{
    ll n;
    cin>>n;
    big_fact(n);
 return 0;
}
