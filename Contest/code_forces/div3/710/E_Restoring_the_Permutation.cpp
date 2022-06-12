#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0) ; cout.tie(0);
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<=n;i++)
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define endl "\n"
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<" : "<<f<<endl
const ll mod = 1e9+7;
#define popcount(x) __builtin_popcount(x)
#define all(x) x.begin(),x.end()
#define mem(a,v) memset(a,v,sizeof(a))
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

void solve()
{
    ll n,i;
    cin>>n;
    vi v(n);
    fo(i,n) 
        cin>>v[i];

    ll mx[n];
    ll mn[n];
    ll prev;

    ll cmx[n+1]={0};
    ll cmn[n+1]={0};

    ll mne=0;
    ll mnx;

    set<ll> st1;
    set<ll> st2;

    ll ls;

    fo(i,n)
    {
        if(i==0)
        {
            for(ll j=1;j<v[i];j++)
            {
                st1.insert(j);
                st2.insert(-j);
            }
            mn[i]=v[i];
            mx[i]=v[i];
            ls=i;
            prev=v[i];
        }
        else
        {
            if(prev<v[i])
            {
                for(ll j=prev+1;j<v[i];j++)
                {
                    st1.insert(j);
                    st2.insert(-j);
                }
                // for(ll j=ls+1;j<i;j++)
                // {
                //     mn[j]=*st1.begin();
                //     mx[j]=*st2.begin();
                //     mx[j]=-mx[j];
                //     st1.erase(st1.begin());
                //     st2.erase(st2.begin());
                // }
                mn[i]=v[i];
                mx[i]=v[i];
                ls=i;
                prev=v[i];
            
            }
            else
            {
                mn[i]=*st1.begin();
                mx[i]=*st2.begin();
                mx[i]=-mx[i];
                st1.erase(st1.begin());
                st2.erase(st2.begin());
            }
            
        }
    }

    
    // if(st1.size()>=1)
    // for(ll j=ls+1;j<n;j++)
    // {
    //     mn[j]=*st1.begin();
    //     mx[j]=*st2.begin();
    //     mx[j]=-mx[j];
    //     st1.erase(st1.begin());
    //     st2.erase(st2.begin());
    // }

    for(i=0;i<n;i++)
        cout<<mn[i]<<" ";
    cout<<endl;

    for(i=0;i<n;i++)
        cout<<mx[i]<<" ";
    cout<<endl;

}

int main()
{
    fastio
    int t;
    cin>>t;
    while(t--)
    {
        solve();   
    }
 return 0;
}
ll fxp(ll a,ll b,ll m) {
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp(m_m(a,a,m),b/2,m);
    return m_m(fxp(a,b-1,m),a,m);
}
ll m_m(ll a,ll b,ll m) 
{
    ll res=0;
    a=a%m;
    while(b)
    {
        if(b&1)
        {
            res+=a; 
            res=res%m;
        }
        a=(a*2)%m;
        b=b/2;
    }
    return res;
}