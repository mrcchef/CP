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
vi prime;
bool check[N];
vi distinctPrimeFact(N,0);
vi v;
ll n;

const ll sz=1e3+5;

vector<vi> dp(sz,vi(sz,-1));

void cal()
{
    for(ll i=1;i<N;i++)
        check[i]=true;
    check[0]=check[1]=false;
    for(ll i=2;i<N;i++)
    {
        if(check[i]==1)
        {
            prime.pb(i);
            distinctPrimeFact[i]=1;
            for(ll j=2*i;j<N;j+=i)
                check[j]=0,distinctPrimeFact[j]++;
        }
    } 
}

ll helper(ll i,ll j)
{
    if(i>j)
        return 0;
    
    if(dp[i][j]!=-1)
        return dp[i][j];

    ll op1=0,op2=0,op3=0;

    ll leftEle=v[i];
    ll rightEle=v[j];
    

    while(leftEle>0)
    {
        op1+=leftEle*distinctPrimeFact[leftEle];
        leftEle/=2;
    }

    op1+=helper(i+1,j);

    while(rightEle>0)
    {
        op2+=rightEle*distinctPrimeFact[rightEle];
        rightEle/=2;
    }

    op2+=helper(i,j-1);

    leftEle=v[i];
    rightEle=v[j];

    while(leftEle>0 || rightEle>0)
    {
        if(leftEle==rightEle)
        {
            op3+=leftEle*distinctPrimeFact[leftEle];
            leftEle/=2;
            rightEle/=2;
        }
        else if(leftEle>rightEle)
        {
            op3+=leftEle*distinctPrimeFact[leftEle];
            leftEle/=2;
        }
        else if(rightEle>leftEle)
        {
            op3+=rightEle*distinctPrimeFact[rightEle];
            rightEle/=2;
        }
    }

    op3+=helper(i+1,j-1);

    // return Min(op1,op2,op3);
    return dp[i][j]=Min(op1,op2,op3);

}

void solve()
{
    ll i;
    cin>>n;
    v.resize(n);
    fo(i,n)
        cin>>v[i];
    
    ll ans=helper(0,n-1);

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
        cal();
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