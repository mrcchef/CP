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

void create2DPrefix(vector<vi> &arr,vector<vi> &pref,ll n,ll m)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            pref[i][j]=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+arr[i][j];
        }
    }
}

int cnt=0;
bool checkRes(vector<vi> &arr,ll n,ll m,ll k,ll val)
{
    int i,j;

    vector<vi> pref(n+2,vi(m+2,0));
    create2DPrefix(arr,pref,n,m);
    if(cnt==10)
        debug(pref);

    for(i=1;i+k-1<=n;i++)
    {
        for(j=1;j+k-1<=m;j++)
        {
            ll r1=i;
            ll c1=j;
            ll r2=i+k-1;
            ll c2=j+k-1;
            ll sum=pref[r2][c2]-pref[r1-1][c2]-pref[r2][c1-1]+pref[r1-1][c1-1];
            debug(mp(i,j));
            debug(mp(r2,c2));
            // debug()
            debug(sum);
            if(sum==k*k*val)
                return true;   


            // ll x,y;
            // ll flag=1;
            // for(x=i;x<i+k;x++)
            // {
            //     for(y=j;y<j+k;y++)
            //     {
            //         if(arr[x][y]!=val)
            //         {
            //             flag=0;
            //             break;
            //         }
            //     }
            // }

            // if(flag==1)
            //     return true;
        }

    }
    return false;

}

void solve()
{
    ll n,m,k;
    cin>>n>>m>>k;

    ll i,j;

    vector<vi> arr(n+1,vi(m+1,0));

    vector<pii> v(n*m);

    fo(i,n*m)
    {
        cin>>v[i].first;
        cin>>v[i].second;
    }

    string res="Draw";

    fo(i,n*m)
    {
        debug(i);
        cnt++;
        if(i&1)
        {
            // Bob
            arr[v[i].first][v[i].second]=2;
            bool check=checkRes(arr,n,m,k,2);
            debug(arr);

            if(check)
            {
                res="Bob";
                break;
            }  
        }
        else
        {
            arr[v[i].first][v[i].second]=1;
            bool check=checkRes(arr,n,m,k,1);
        debug(arr);

            if(check)
            {
                res="Alice";
                break;
            }   
        }
    }

    cout<<res<<endl;
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