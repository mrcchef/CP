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

vi dp(N,-1);

ll helper(ll i,ll n,ll d,ll m,vi &v)
{
    if(i>n)
        return 0;
    
    ll ans=0;

    if(dp[i]!=-1)
        return dp[i];

    // when he doesn't opt to speak
    ans=max(ans,helper(i+1,n,d,m,v));

    if(v[i]>m)
        ans=max(ans,helper(i+d+1,n,d,m,v)+v[i]);
    else
        ans=max(ans,helper(i+1,n,d,m,v)+v[i]);
    
    debug(mp(i,ans));
    return dp[i]=ans;
}

void solve()
{
    ll n,d,m;
    cin>>n>>d>>m;
    ll i;

    vi v(n+1);

    vi arr1,arr2;

    arr1.pb(0);
    arr2.pb(0);

    fo(i,n)
    {
        cin>>v[i+1];
        if(v[i+1]>m)
            arr1.pb(v[i+1]);
        else
            arr2.pb(v[i+1]);
    }   

    sort(arr1.begin()+1,arr1.end(),greater<ll>());
    sort(arr2.begin()+1,arr2.end());

    ll sz1=arr1.size();
    ll sz2=arr2.size();
    vi pref1(sz1);
    vi pref2(sz2);

    Fo(i,1,sz1)
        pref1[i]=pref1[i-1]+arr1[i];
    
    Fo(i,1,sz2)
        pref2[i]=pref2[i-1]+arr2[i];

    // ll ans=helper(1,n,d,m,v);
    ll ans=0;
    
    ll j=1;

    for(i=2;i<=sz1;i++)
    {
        ll val1=arr1[i];
        ll val2=pref2[min(j+d-1,sz2)]-pref2[j-1];

        if(val1>val2)
        {
            ans+=val1;
            j=j+d;
        }

        if(j>sz2)
            break;
    }
    debug(ans);
    if(i<=sz1)
    {
        ll res=sz1-i+1;
        ll q=(res+d)/(d+1);

        ans+=pref1[min(i+q,sz1)]-pref1[i-1];
    }

    ans+=pref2[sz2]-pref2[j-1];

    ans+=arr1[1];

    cout<<ans<<endl;
}

int main()
{
    fastio
    #ifdef ONLINE_JUDGE
         freopen("Error.txt", "w", stderr);
    #endif
    int t=1;
    // cin>>t;
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