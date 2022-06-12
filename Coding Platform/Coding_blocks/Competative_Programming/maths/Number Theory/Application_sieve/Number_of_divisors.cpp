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

void solve(mii &m,ll n)
{
    for(ll i=2;i*i<=n;i++)
    {
        ll cnt=0;
        if(n%i==0)
        {
            while(n%i==0)
            {
                cnt++;
                n=n/i;
            }
            m[i]+=cnt;
        }
    }
    if(n>1)
    {
        m[n]+=1;
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,i;
        cin>>n;
        ll a[n];
        mii m;
        fo(i,n)
        {
            cin>>a[i];
        } 
        for(ll i=0;i<n;i++)
        {
            solve(m,a[i]);
        }
        ll res=1;
        for(auto it=m.begin();it!=m.end();it++)
        {
            res*=(it->second+1);
        }
        cout<<res<<endl;
    }
 return 0;
}
ll fxp(ll a,ll b,ll m) {
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp(a*a,b/2,m);
    return fxp(a,b-1,m)*a;
}
