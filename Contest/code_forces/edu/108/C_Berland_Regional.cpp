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
#define deb1(x)                cout<<#x<<": "<<x<<endl
#define deb2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define deb3(x, y, z)          cout<<#x<<":"<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
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
    unordered_map<ll,vi> hm;
    unordered_map<ll,vi> sz;
    unordered_map<ll,vi> sm;
    
    vi v(n);

    fo(i,n)
        cin>>v[i];
    
    fo(i,n)
    {
        ll val;
        cin>>val;
        hm[v[i]].pb(val);
    }

    for(auto &val:hm)
    {
        sort(val.second.begin(),val.second.end(),greater<ll>());
        vi tv=val.second;
        vi tsm(tv.size()+1,0);
        sz[tv.size()].pb(val.first);
        Fo(i,1,tv.size())
        {
            tsm[i]=tsm[i-1]+tv[i-1];
        }

        sm[val.first]=tsm;
    }

    ll ans[n+1]={0};

    Fo(i,1,n)
    {
        if(i==1)
        {
            for(auto &val:sm)
            {
                ll sz=hm[val.first].size();
                ans[i]+=val.second[sz];
            }  
        }
        else
        {
            ans[i]=ans[1];
            // for(auto val:sm)
            // {
            //     ll sz=hm[val.first].size();
            //     ll rem=sz%i;
            //     if(rem==0)
            //         continue;

            //     // trace6(i,rem,val.second[sz]-val.second[sz-rem],val.second[sz],val.second[sz-rem],val.first);
            //     ans[i]-=(val.second[sz]-val.second[sz-rem]);
            // }
            
            for(auto &sizes:sz)
            {
                if(sizes.first%i==0)
                    continue;
                ll rem=sizes.first%i;
                for(auto &val:sizes.second)
                {
                   ans[i]-=(sm[val][sizes.first]-sm[val][sizes.first-rem]);
                }
            }

        }
    }

    Fo(i,1,n)
        cout<<ans[i]<<" ";
    cout<<endl;
}

int main()
{
    fastio
    int t=1;
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