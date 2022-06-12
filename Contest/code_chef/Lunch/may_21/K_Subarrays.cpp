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

void solve()
{
    ll n,k;
    cin>>n>>k;
    ll i;
    vi v(n+1);
    ll mx=INT_MIN;
    ll sm=0;
    Fo(i,1,n)
    {
        cin>>v[i];
        sm+=v[i];
        if(sm>mx)
        {
            mx=sm;
        }

        if(sm<0)
            sm=0;
    
    }
    if(mx>=0)
        mx=max(mx,sm);
    // debug(mx)
    // if(k==1)
    // {
    //     cout<<mx<<endl;
    //     return;
    // }
    // else
    // {
        vector<vi> dp(n+1,vi(k+1,0));



        // ll dp[n+1][3][2];
        vector<vi> subSum(n+1,vi(k+1,0));
        // mem(dp,0);

        dp[1][1]=subSum[1][1]=v[1];

        for(i=2;i<=n;i++)
        {
            ll val;
            if(subSum[i-1][1]==0)
                val=v[i];
            else
                val=subSum[i-1][1]+v[i]+dp[i-1][1]-subSum[i-1][1];

            if(dp[i][1]<val)
            {
                dp[i][1]=val;
                subSum[i][1]=dp[i][1];
            }
            // dp[i][1]=max(dp[i][1],dp[i-1][1]+v[i]);

            if(dp[i][1]<dp[i-1][0]+v[i]*1)
            {
                dp[i][1]=dp[i-1][0]+v[i]*1;
                subSum[i][1]=v[i];
            }
// 
            // dp[i][1]=max(dp[i][1],dp[i-1][0]+v[i]*1);

            if(dp[i][1]<dp[i-1][1])
            {
                dp[i][1]=dp[i-1][1];
                subSum[i][1]=0;
            }

            // dp[i][1]=max(dp[i][1],dp[i-1][1]);
            
            // for 2
            if(i>2)
            {
                if(subSum[i-1][2]==0)
                    val=v[i]*2;
                else
                    val=((subSum[i-1][2]+v[i])*2)+(dp[i-1][2]-subSum[i-1][2]*2);
                debug(subSum[i-1][2]+v[i])
                debug(dp[i-1][2])

                debug(subSum[i-1][2])
                debug((dp[i-1][2]-subSum[i-1][2]*2))
                debug(val);
                if(dp[i][2]<val)
                {
                    dp[i][2]=val;
                    subSum[i][2]=subSum[i-1][2]+v[i];
                }

                if(dp[i][2]<dp[i-1][2])
                {
                    dp[i][2]=dp[i-1][2];
                    subSum[i][2]=0;
                }
            }
            
            if(dp[i][2]<dp[i-1][1]+v[i]*2)
            {
                dp[i][2]=dp[i-1][1]+v[i]*2;
                subSum[i][2]=v[i];
            }
            // dp[i][2]=max(dp[i][2],(dp[i-1][2]+v[i])*2);

            // dp[i][2]=max(dp[i][2],dp[i-1][1]+v[i]*2);

            
            // if(i>2)
            // dp[i][2]=max(dp[i][2],dp[i-1][2]);
            
            // ll j=0;
            // for(j=0;j<n;j++)
            //     debug(dp[j])
            debug(i)
            debug(dp)
            debug(subSum)
        }

        cout<<dp[n][k]<<endl;
    // }
}

int main()
{
    fastio
    #ifdef ONLINE_JUDGE
         freopen("Error.txt", "w", stderr);
    #endif
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
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}
ll msum(ll a,ll b,ll m) { return ((a%m+b%m)+m)%m; }
ll msub(ll a,ll b,ll m) { return ((a%m-b%m)+m)%m; }
ll mpro(ll a,ll b,ll m) { return (((a%m)*(b%m)+m))%m; }