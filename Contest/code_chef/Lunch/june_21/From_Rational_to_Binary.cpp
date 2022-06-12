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

bool check(ll x,ll y,ll num1,ll dem)
{
    ll resn1=x*dem+y*num1;
    ll resd1=y*dem;

    ll resg=__gcd(resn1,resd1);

    resn1/=resg;
    resd1/=resg;

    ll resn2=x*dem-num1*y;
    ll resd2=y*dem;

    ll resg2=__gcd(resn2,resd2);

    resn2/=resg2;
    resd2/=resg2;

    debug(resn1)
    debug(resd1)
    debug(resn2)
    debug(resd2)
    if(resn1==0 || (resn1==1 && resd1==1) || (resn1==1 && resd1==2)) 
        if(resn2==0 || (resn2==1 && resd2==1) || (resn2==1 && resd2==2))
            return true;
        
    return false;
}

bool isPowerOfTwo(int n)
{
   if(n==0)
   return false;
 
   return (ceil(log2(n)) == floor(log2(n)));
}

void solve()
{
    ll x,y;
    cin>>x>>y;
    
    ll mn=min(x,y-x);

    ll setBit=popcount(y);

    if(setBit<=1)
    {
        cout<<"Yes";
    }
    else
    {
        
        // ll num1=y-2*x;
        // ll dem=2*y;
        // if(num1<0)
        //     num1*=-1;
        // ll g=__gcd(num1,dem);
        // num1/=g;
        // dem/=g;


        // debug(num1);
        // debug(dem);

        // if(num1<=mn)
        // {
        //     if((x-num1==0 || 2*(x-num1)==y || x-num1==y) && (x+num1==0 || 2*(x+num1)==y || x+num1==y))
        //     {
        //         debug(1);
        //         cout<<"Yes";
        //     }
        //     else
        //     {
        //         cout<<"No";
        //     }
        //     cout<<endl;
        //     return;
        // }
        cout<<"No";
    }
    cout<<endl;
    return;
    // debug(mn);


    // if(num1+x)

    // ll num2=-num1;

    // string res;
    // if(check(x,y,num1,dem))
    //     res="Yes";
    // else if(check(x,y,num2,dem))
    //     res="Yes";
    // else
    //     res="No";
    // cout<<res<<endl;
    // // cout<<endl;
    // // if(x+num1)

    // // debug(num1);
    // // debug(dem);
    // // debug(num2);
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