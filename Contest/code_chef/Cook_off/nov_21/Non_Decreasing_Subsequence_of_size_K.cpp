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

vi ans;

void helper(ll i,ll n,ll k,vi &v,vi &arr,mii &hm)
{
    debug(mp(i,arr));
    if(!ans.empty())
        return;

  
    if(arr.size()==k)
    {
        ans=arr;
        debug(arr);
        return;
    }

    if(i==n)
        return;

    ll sz=arr.size();
    ll cnt=hm[v[i]];
    if(sz+cnt<=k)
    {
        for(ll j=cnt;j>=1;j--)
            arr.pb(v[i]);
        helper(i+1,n,k,v,arr,hm);
        
        for(ll j=cnt;j>=1;j--)
            arr.pop_back();
    }

    helper(i+1,n,k,v,arr,hm);
}

bool check(vi &arr,ll k)
{
    ll n=arr.size();
    vi dp(n+1,0);

    for(ll i=1;i<=n;i++)
    {
        if(i==1)
        {
            dp[1]=1;
        }
        else
        {
            dp[i]=dp[i-1];
            dp[i]+=arr[i-1]>=arr[i-2]?1:0;
        }
    }

    return dp[n]==k;
}

void solve()
{
    ll n,i,k;
    cin>>n>>k;

    vi v(n);
    vi unv;
    mii hm;
    ans.clear();
    fo(i,n)
    {
        cin>>v[i];
        hm[v[i]]++;
        if(hm[v[i]]==1)
            unv.pb(v[i]);
    }
    
    sort(all(v));
    sort(all(unv));

    vi arr;

    if(n<k)
    {
        cout<<-1<<endl;
        return;
    }

    for(auto &val:hm)
    {
        if(val.second>k)
        {
            cout<<-1<<endl;
            return;
        }
    }

    vi res;

    for(i=0;i<n;i++)
    {
        if(i<k)
            res.pb(v[i]);
        else
        {
            ll ele=v[i];
            for(ll j=res.size()-1;j>=0;j--)
            {
                vi temp=res;
                debug(res);
                debug(j);
                temp.insert(temp.begin()+j,ele);
                debug(temp);

                if(check(temp,k))
                {
                    res=temp;
                    break;
                }
            }
        }
    }

    for(auto &val:res)
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