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
#define endl "\n"
#define deb(x) cout << #x << "=" << x << endl
const ll mod = 1e9+7;

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

ll m_m(ll a,ll b,ll m) //m_m refers to modulor multiplication
{
    ll res=0;
    a=a%m;
    while(b)
    {
        if(b&1)
        {
            res+=a; // b will always be 1 at the last so finally all the values will be added at res
            res=res%m;
        }
        a=(a*2)%m;
        b=b/2;
    }
    return res;
}

ll m_e(ll a,ll b,ll m)
{
    ll res=1;
    a=a%m;
    while(b)
    {
        if(b&1)
        {
            res=m_m(res,a,m);
            res=res%m;
        }
        a=m_m(a,a,m);
        a=a%m;
        b=b/2;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll a,b,c;
    cin>>a>>b>>c;
    cout<<fxp(a,b,c)<<endl;
    cout<<m_e(a,b,c);

 return 0;
}

