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

ll dp[60][2];
ll dpcnt[60][2];

ll cnt(string &num,ll len,ll isTight)
{
    if(isTight==0)
        return pow(10,len);
    
    if(len==0)
        return 1;
    if(dpcnt[len][isTight]!=-1)
        return dpcnt[len][isTight];
    ll tcnt=0;

    ll up=9;
    if(isTight)
        up=num[num.size()-len]-'0';
    
    for(ll i=0;i<=up;i++)
    {
        tcnt+=cnt(num,len-1,isTight&(i==up));
    }

    return dpcnt[len][isTight]=tcnt;
}

ll helper(string &num,ll len,bool isTight)
{
    if(len==0)
        return 0;

    // debug(mp(len,isTight));

    if(dp[len][isTight]!=-1)
        return dp[len][isTight];

    ll ans=0;

    ll up=9;
    if(isTight)
        up=num[num.size()-len]-'0';
    // debug(up);
    for(ll i=0;i<=up;i++)
    {
        if(!isTight)
        {
            ans+=helper(num,len-1,0)+cnt(num,len-1,0)*i;
        }
        else
        {
            if(i==up)
            {
                ans+=helper(num,len-1,1)+cnt(num,len-1,1)*i;
            }
            else
            {
                ans+=helper(num,len-1,0)+cnt(num,len-1,0)*i;
            }
        }
        // debug(mp(i,ans))
    }
    // debug(mp(len,isTight))
    // debug(ans)
    return dp[len][isTight]=ans;
}

void solve()
{
    ll l,r;
    cin>>l>>r;
    
    if(l>=1)
        l--;
    string L=to_string(l);
    string R=to_string(r);

    ll llen=L.size();
    ll rlen=R.size();

    mem(dp,-1);
    mem(dpcnt,-1);
    ll tillR=helper(R,rlen,1);

    mem(dp,-1);
    mem(dpcnt,-1);
    ll tillL=helper(L,llen,1);


    cout<<tillR-tillL<<endl;

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