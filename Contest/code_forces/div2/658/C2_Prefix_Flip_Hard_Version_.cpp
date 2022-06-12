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

vi stringTovector(string s)
{
    int n=s.size();
    vi v;
    ll i;
    fo(i,n)
    {
        ll num=s[i]-'0';
        v.pb(num);
    }

    return v;
}

char getCurChar(char ch,ll oper)
{
    if(oper%2==0)
        return ch;
    
    if(ch=='1')
        return '0';
    
    return '1';
}

void solve()
{
    ll n,i;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;

    deque<char> dq;

    fo(i,n)
        dq.push_back(s1[i]);

    vi res;
    ll isRev=0;
    ll oper=0;
    for(i=n-1;i>=0;i--)
    {
        char lastCh,firstCh;
        debug(isRev);
        if(isRev)
        {
            lastCh=dq.front();

            firstCh=dq.back();

            // lastCh=getCurChar(lastCh,oper);
            // firstCh=getCurChar(firstCh,oper);

            debug(lastCh);
            debug(firstCh);
            if(lastCh!=s2[i])
            {
                dq.pop_front();
                continue;
            }

            isRev^=1;
            if(lastCh=='1')
            {
                if(firstCh=='0')
                {
                   res.pb(i+1);
                }
                else
                {
                    res.pb(1);
                    res.pb(i+1);
                    dq.pop_back();
                    // isRev^=1;
                }
            }
            else
            {
                if(firstCh=='1')
                {
                    res.pb(i+1);
                }
                else
                {
                    res.pb(1);
                    res.pb(i+1);
                    dq.pop_back();
                    // isRev^=1;
                }
            }
        }
        else
        {
            lastCh=dq.back();
            // dq.pop_back();
            firstCh=dq.front();
            debug(lastCh);
            debug(firstCh);
            if(lastCh==s2[i])
            {
                dq.pop_back();
                continue;
            }

            isRev^=1;
            if(lastCh=='1')
            {
                if(firstCh=='1')
                {
                   res.pb(i+1);
                }
                else
                {
                    res.pb(1);
                    res.pb(i+1);
                    dq.pop_front();
                    // isRev^=1;
                }
            }
            else
            {
                if(firstCh=='0')
                {
                    res.pb(i+1);
                }
                else
                {
                    res.pb(1);
                    res.pb(i+1);
                    dq.pop_front();
                    // isRev^=1;
                }
            }
        }
    }

    cout<<res.size()<<" ";
    for(auto val:res)
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