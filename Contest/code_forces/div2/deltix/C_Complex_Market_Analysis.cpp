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

const ll N=1e6+5;
vi prime;
bool check[N];

void cal()
{
    for(ll i=1;i<=N;i++)
        check[i]=true;
    check[0]=check[1]=false;
    for(ll i=2;i<=N;i++)
    {
        if(check[i]==1)
        {
            prime.pb(i);
            for(ll j=i*i;j<=N;j+=i)
                check[j]=0;
        }
    } 
}

void solve()
{
    ll n,i,e;
    cin>>n>>e;
    vi v(n+1);

    fo(i,n)
        cin>>v[i+1];

    
    vi dp1(n+2,0),dp2(n+2,0);

    Fo(i,1,n)
    {
        if(v[i]==1)
            dp1[i]=1;
        else
            continue;
        
        ll pin=i-e;
        if(pin<1)
            continue;
    

        dp1[i]+=dp1[pin];
    }

    for(i=n;i>=1;i--)
    {
        if(v[i]==1)
            dp2[i]=1;
        else
            continue;
        
        ll pin=i+e;

        if(pin>n)
            continue;
        
        dp2[i]+=dp2[pin];
    }


    ll ans=0;

    Fo(i,1,n)
    {
        ll pin=i-e;

        ll fin=i+e;

        if(!check[v[i]])
            continue;
        
        ll tans=0;


        if(pin>=1)
            tans+=dp1[pin];
        
        if(fin<=n)
            tans+=dp2[fin];
        
        if(pin>=1 && fin<=n)
            tans+=dp2[fin]*dp1[pin];

        
        ans+=tans;
        debug(mp(i,ans));
    }


    cout<<ans<<endl;

    // Fo(i,1,n)
    // {
    //     ll pin=i-e;
    //     if(pin<1)
    //         continue;
        
    //     ll pnum=v[pin];

    //     if(v[i]!=1 && !check[v[i]])
    //         continue;

    //     if(check)



        // if(check[pnum] && v[i]==1)
        // {
        //     dp1[i]=dp1[pin];
        // }
        // else if(pnum==1 && v[i]==1)
        // {
        //     dp1[1]=dp1[pin];
        // }
        // else if(pnum==1 && check[v[i]])
        // {
        //     dp1[i]=dp1[pin];
        // }

        // sm1+=dp1[i];
    // }

    // for(i=n;i>=1;i--)
    // {
    //     ll pin=i+e;

    //     if(pin>n)
    //         continue;
        
    //     if(v[i]!=1)
    //         continue;

    //     ll num=v[pin];
    //     if(check[num])
    //     {
    //         dp2[i]=1;
    //     }
    //     else if(num==1)
    //     {
    //         dp2[i]=dp2[pin];
    //     }

    //     sm2+=dp2[i];
    // }

    debug(dp1);
    debug(dp2);
    // debug(sm1);
    // debug(sm2);

    // ans=sm1+sm2;

    // cout<<ans<<endl;
}

int main()
{
    fastio
    #ifdef ONLINE_JUDGE
         freopen("Error.txt", "w", stderr);
    #endif
    int t=1;
    cal();
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