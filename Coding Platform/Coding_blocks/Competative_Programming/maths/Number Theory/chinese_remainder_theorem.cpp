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

void extended(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return;
    }
    ll x1,y1;
    extended(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
}

ll modulo_inverse(ll a,ll m)
{
    ll x,y;
    extended(a,m,x,y);
    x=(x%m+m)%m;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,i,M=1;
    cin>>n;
    ll md[n],rem[n];
    fo(i,n)
    {
        cin>>md[i];
        M=M*md[i];
    }    
    fo(i,n)
        cin>>rem[i];
    ll res=0;
    for(ll i=0;i<n;i++)
    {
        ll m=M/md[i];
        ll inv=modulo_inverse(m,md[i]);
        deb(inv);
        deb(m);
        res+=(rem[i]*inv*m);
    }
    res=res%M;
    cout<<res<<endl;
 return 0;
}
ll fxp(ll a,ll b,ll m) {
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp(a*a,b/2,m);
    return fxp(a,b-1,m)*a;
}
