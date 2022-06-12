#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
#include <string>
#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define deb(x) cout << #x << "=" << x << endl
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

ll sum_digits(ll n)
{
    ll sum=0;
    while(n)
    {
        ll r=n%10;
        n=n/10;
        sum+=r;
    }
    return sum;
}

int main()
{
    ll n,m;
    cin>>n;
    m=n;
    ll sum1=sum_digits(n),sum2=0;
    for(ll i=2;i*i<=n;i++)
    {
        ll f=0;
        if(n%i==0)
        {
            while((n%i)==0)
            {
                f++;
                n=n/i;
            }
            sum2+=sum_digits(i)*f;
            // deb(sum2);
        }
    }
    if(n!=1)
    {
        sum2+=sum_digits(n);
    }
    if(sum1==sum2)
        cout<<1;
    else
        cout<<0;
 return 0;
}
