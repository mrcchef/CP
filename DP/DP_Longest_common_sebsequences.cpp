#include<climits>
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

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
        }
        ll f[n]={0};
        f[0]=1;
        for(ll i=1;i<n;i++)
        {
            ll op=0;
            for(ll j=i-1;j>=0;j--)
            {
                if(a[j]<a[i])
                {
                    op=max(op,f[j]);
                }
            }
            f[i]=op+1;
        }
        ll m=INT_MIN;
        for(ll i=0;i<n;i++)
        {
            m=max(m,f[i]);
        }
        cout<<m<<endl;
    }
 return 0;
}
