#include<bits/stdc++.h>
using namespace std;
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
#define deb(x) cout << #x << "=" << x << endl
const ll mod = 1e9+7;

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}


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
        list<ll> *child;
        ll parent[n+1];
        parent[1]=0;
        child=new list<ll>[n+1]; 
        ll height[n+1]={0};
        height[1]=1;
        set<ll> s;
        for(i=1;i<=n;i++)
            s.insert(i);
        fo(i,n-1)
        {
            ll x;
            cin>>x;
            child[x].pb(i+2);
            parent[i+2]=x;
            height[i+2]=height[x]+1;
            if(s.count(x)==1)
                s.erase(x);
        }
        ll cal[n+1]={0};
        for(i=n;i>0;i--)
        {
            for(auto x:child[i])
            {
                cal[i]=cal[i]+cal[x]+1;
            }
        }
        ll ans=0,res=0;
        for(auto it=s.begin();it!=s.end();it++)
        {
            i=*it;
            ans=0;
            while(parent[i]!=0)
            {
                ll sz=cal[i];
                ans+=sz+1;
                i=parent[i];
            }
            res=max(res,ans+cal[i]+1);

        }
        cout<<res<<endl;

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