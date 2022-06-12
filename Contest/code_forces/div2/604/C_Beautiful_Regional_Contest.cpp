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
#define deb(x) cout << #x << "=" << x << endl
const ll mod = 1e9+7;
#define popcount(x) __builtin_popcount(x)
#define all(x) x.begin(),x.end()
#define mem(a,v) memset(a,v,sizeof(a))

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
    vi arr;
    mii m;
    fo(i,n)
    {
        cin>>v[i];
        if(m[v[i]]==0)
            arr.pb(v[i]);
        m[v[i]]++;
    }

    if(arr.size()<3)
    {
        cout<<"0 0 0"<<endl;
        return; 
    }

    ll g=0,s=0,b=0;

    vi sm(arr.size()+1,0);

    // mii fm;

    for(i=1;i<=arr.size();i++)
    {
        sm[i]=sm[i-1]+m[arr[i-1]];
        // cout<<sm[i]<<" ";
        // fm[sm[i]]++;
    }
    // cout<<endl;
    ll tg,ts,tb;
    auto it=upper_bound(sm.begin(),sm.end(),n/2);
    
    it--;
    // deb(*it);
    
        tg=sm[1];
        // deb(tg);
        for(ll j=2;j<=sm.size() && sm[j]<=*it;j++)
        {
            // deb(sm[j]);
            ts=sm[j]-tg;
            tb=*it-ts-tg;
            // deb(ts);
            // deb(tb);
            if(ts<=tg || tb<=tg)  
                continue;
            
            if(tg+ts+tb>g+s+b)
            {
                g=tg;
                s=ts;
                b=tb;
            }
        }

    // }

    cout<<g<<" "<<s<<" "<<b<<endl;
    
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