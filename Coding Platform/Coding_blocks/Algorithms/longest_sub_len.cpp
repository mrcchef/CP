#include <climits>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define ll long long int
#define mod 1e9+7

ll fxp(ll a,ll b,ll m)
{
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp(a*a,b/2,m);
    return fxp(a,b-1,m)*a;
}

void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

int lss(ll a[],ll n)
{
    ll f[n];
    f[0]=1;
    for(ll i=1;i<n;i++)
    {
        f[i]=1;
        for(ll j=i-1;j>=0;j--)
        {
            if(a[j]<a[i])
            {
                ll pos_res=f[j]+1;
                if(pos_res>f[i])
                    f[i]=pos_res;
            }
        }
    }
    ll m=INT_MIN;
    for(ll i=0;i<n;i++)
        m=max(m,f[i]);
    return m;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++) cin>>a[i];
        ll res=lss(a,n);
        cout<<res<<endl;
	}
	return 0;
}

