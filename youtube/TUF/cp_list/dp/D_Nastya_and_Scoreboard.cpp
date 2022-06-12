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

map<string,ll> hm;
// map<ll,string> rhm;

string rhm[10];

void mapStrings()
{
    vector<string> vs={ "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
    ll i;
    fo(i,10)
    {
        rhm[i]=vs[i];
    }
}

const ll N=1e3+5;

ll dp[N][N][10];

ll isValidTransf(string &s1,ll num)
{
    ll diff=0;
    ll i;
    string s2=rhm[num];
    fo(i,s1.size())
    {
        if(s1[i]=='0' && s2[i]=='1')
            diff++;
        else if(s1[i]=='1' && s2[i]=='0')
        {
            diff=-1;
            return diff;
        }
    }
    return diff;
}

ll n,k;
vector<string> vs;

ll helper(ll i,ll remOp,ll num,vector<vi> &cost)
{

    if(i==n && remOp==0)
    {
        return dp[i][remOp][num]=1;
    }
    
    if(remOp<0)
        return 0;

    if(i==n || cost[i][num]==-1)
        return dp[i][remOp][num]=0;



    if(dp[i][remOp][num]!=-1)
        return dp[i][remOp][num];

    ll j;
    ll check=0;
    fo(j,10)
    {
        
    }
         check|=helper(i+1,remOp-cost[i][num],j,cost);
    

    return dp[i][remOp][num]=check;
}

void solve()
{
    mapStrings();
    cin>>n>>k;
    ll i;
    vs.resize(n);
    mem(dp,-1);
    vector<vi> cost(n+1,vi(10));
    fo(i,n)
    {
        cin>>vs[i];
    }

    fo(i,n)
    {
        ll j;
        fo(j,10)
        {
            cost[i][j]=isValidTransf(vs[i],j);
        }
    }
    

    // debug(vs);
    
    ll flag=0;

    fo(i,10)
    {
        helper(0,k,i,cost);
    }

    // debug(cost);

    ll j=k;

    string ans;

    for(i=0;i<n;i++)
    {
        ll num;
        for(num=9;num>=0;num--)
        {
            if(dp[i][j][num]==1)
            {
                char ch=num+48;
                // debug(ch)
                ans+=ch;
                j-=cost[i][num];
            }
            if(j==0)
                break;
        }
        if(j==0)
            break;
    }

    // fo(i,n)
    // {
    //     // debug(i)
    //     ll j;
    //     fo(j,k+1)
    //     {
    //         debug(j)
    //         ll p;
    //         fo(p,10)
    //         {
    //             // debug(p)
    //             // debug(dp[i][j][p]);
    //         }
    //         cout<<endl;
    //     }
    // }
    if(ans.size()==0)
    {
        cout<<-1<<endl;
        return;
    }

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