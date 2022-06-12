#include<bits/stdc++.h>
using namespace std;

#define mod 1e9+7
#define ll  long long int


ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }

void EEA(ll a,ll b,ll &x,ll &y)
{
    if(a==1)
    {
        x=1;
        y=0;
        return;
    }
    ll x1,y1;
    EEA(b%a,a,x1,y1);
    y=x1;
    x=y1-(b/a)*y;
    
}

ll ModInverse(ll a,ll m)
{
    if(__gcd(a,m)!=1 || a==0 || m==0 ) // __gcd(a,m) is a inbuild funtion to find gcd. time completicy is log(max(a,b)). carefully handle the case for
    {                           // 0,0 and x,0 and 0,x
        return -1;
    }                            
    ll x,y;
    EEA(a,m,x,y);
    x=(x%m+m)%m;
    return x;

}

void calfact(ll f[])
{
    f[0]=1;
    for(ll i=1;i<=29;i++)
    {
        f[i]=f[i-1]*i;
    }
}

void calinvfact(ll f[],ll inf[])
{
    inf[0]=inf[1]=ModInverse(f[0],mod);
    for(ll i=2;i<=29;i++)
    {
        inf[i]=ModInverse(f[i],mod);
    }
}

ll result(ll n,ll r,ll f[],ll invf[])
{
    ll ans=mpro(mpro(invf[r],invf[n-r],mod),f[n],mod);
    return ans;
}
// Here we can reduce our time complexity to O(n)

int main()
{
    ll t;
    cin>>t;
    ll fact[30];
    ll invfact[30];
    calfact(fact);
    calinvfact(fact,invfact);
    for(ll i=0;i<=5;i++)
        cout<<fact[i]<<" "<<invfact[i]<<endl;
    while(t--)
    {
        ll n,r;
        cin>>n>>r;
        if(n<r)
            cout<<"Not Possible"<<endl;
        else
        {
            cout<<result(n,r,fact,invfact)<<endl;
            // cout<<mpro(fact[n-r+1],invfact[r],mod)<<endl;
        }
    }
}