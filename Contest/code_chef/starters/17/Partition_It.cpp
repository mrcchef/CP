//LinkedIn:https://www.linkedin.com/in/abhijeettamrakar/
//GitHub:https://github.com/mrcchef/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0) ; cout.tie(0);

#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
    #define debug(x);
#endif
 
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<=n;i++)
#define ll long long
#define ull unsigned long long
#define lld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define endl "\n"
const ll MOD = 1e9+7;
const ll MOD1= 998244353;
const ll inf=1e18;
#define popcount(x) __builtin_popcount(x)
#define all(x) x.begin(),x.end()
#define mem(a,v) memset(a,v,sizeof(a))
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))

// debugging code
// ---------------------------------------------------------------------------------------------------------------------------------
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// ---------------------------------------------------------------------------------------------------------------------------------

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

void swap(ll &a,ll &b);
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
ll msum(ll a,ll b,ll m);
ll msub(ll a,ll b,ll m);
ll mpro(ll a,ll b,ll m);

const ll N=1e5+5;
vi check(N,1);

vi lcf(N);

void cal()
{
    ll i;
    check[0]=0;
    lcf[1]=1;

    for(i=2;i<N;i++)
    {
        if(check[i]==1)
        {
            lcf[i]=i;
            for(ll j=2*i;j<N;j+=i)
            {
                if(check[j]==0)
                    continue;
                lcf[j]=i;
                check[j]=0;
            }
        }
    }
}

class DSU{
    public:
    ll n;
    vi parent;
    vi rank;
    
    DSU(ll n)
    {
        this->n=n;
        parent=vi(n+1,-1);
        rank=vi(n+1,1);
    }

    ll getParent(ll node)
    {
        if(parent[node]==-1)
            return node;
        return parent[node]=getParent(parent[node]);
    }

    bool isCyclePresent(ll node1,ll node2)
    {
        ll par1=getParent(node1);
        ll par2=getParent(node2);

        return par1==par2;
    }

    void mergeSet(ll node1,ll node2)
    {
        ll par1=getParent(node1);
        ll par2=getParent(node2);

        if(par1==par2)
            return;
        
        if(rank[par1]<rank[par2])
        {
            parent[par1]=par2;
            rank[par2]+=rank[par1];
        }
        else
        {
            parent[par2]=par1;
            rank[par1]+=rank[par2];
        }
    }
};


void solve()
{
    ll n,k;
    cin>>n>>k;
    ll i;

    DSU dsu(n);
    Fo(i,1,n)
    {
        ll num=i;
        while(num!=1)
        {
            ll fc=lcf[num];
            dsu.mergeSet(fc,i);
            num=num/fc;
        }
    }

    map<ll,vi> hm;

    Fo(i,1,n)
    {
        ll par=dsu.getParent(i);
        hm[par].pb(i);
    }

    ll sz=hm.size();
    vector<pair<ll,ll>> arr(sz+1);

    i=0;
    for(auto &val:hm)
    {
        i++;
        arr[i]={val.first,val.second.size()};
    }

    debug(arr);

    vector<vi> dp(sz+1,vi(n+1,0));
    vector<vi> dp2(sz+1,vi(n+1,0));
    dp[0][0]=dp2[0][0]=1;

    ll j;
    for(i=1;i<=sz;i++)
    {
        ll par=arr[i].first;
        ll len=arr[i].second;
        for(j=1;j<=n;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=len)
            {
                dp[i][j]|=dp[i-1][j-len];
            }
        }
    }

    

    if(!dp[sz][k] && !dp[sz][n-k])
    {
        cout<<"No"<<endl;
        return;
    }

    i=sz;
    j=k;

    vi ans;

    while(i>=1 && j>=1)
    {
        ll par=arr[i].first;
        ll len=arr[i].second;

        if(dp[i-1][j])
        {
            i=i-1;
        }
        else if(j>=len && dp[i-1][j-len])
        {
            i=i-1;
            for(auto &val:hm[par])
            {
                ans.pb(val);
            }
            j=j-len;
        }
    }

    cout<<"Yes"<<endl;

    for(auto &val:ans)
        cout<<val<<" ";
    cout<<endl;
}

int main()
{
    fastio
    #ifdef ONLINE_JUDGE
         freopen("Error.txt", "w", stderr);
    #endif
    int t=1;
    cin>>t;
    cal();
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
        return fxp((a*a)%m,b/2,m);
    return (fxp(a,b-1,m)*a)%m;
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
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}
ll msum(ll a,ll b,ll m) { return ((a%m+b%m)+m)%m; }
ll msub(ll a,ll b,ll m) { return ((a%m-b%m)+m)%m; }
ll mpro(ll a,ll b,ll m) { return (((a%m)*(b%m)+m))%m; }