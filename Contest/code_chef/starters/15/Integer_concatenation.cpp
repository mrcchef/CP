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

static bool compare(string &s1,string &s2)
{
    return stoll(s1)<stoll(s2);
}

ll binarySearch1(ll st,ll ed,vector<string> &vs,string &num,ll l,ll r)
{
    ll pos=ed+1;
    while(st<=ed)
    {
        ll mid=(st+ed)/2;
        string s=vs[mid];
        ll lf=stoll(num+s);

        if(lf>r)
        {
            ed=mid-1;
        }
        else
        {
            pos=mid;
            st=mid+1;
        }
    }   

    return pos;
}

ll binarySearch2(ll st,ll ed,vector<string> &vs,string &num,ll l,ll r)
{
    ll pos=0;
    while(st<=ed)
    {
        ll mid=(st+ed)/2;

        string s=vs[mid];
        ll lf=stoll(num+s);

        if(lf>=l)
        {
            pos=mid;
            ed=mid-1;
        }
        else
        {
            st=mid+1;
        }
    }   

    return pos;
}

void solve()
{
    ll n;
    ll l,r;
    cin>>n>>l>>r;

    vi v(n+1);

    ll i,j;
    fo(i,n)
        cin>>v[i+1];

    sort(v.begin()+1,v.end());

    vi flag1(n+1,-1);
    vi flag2(n+1,-1);

    // debug(v);
    j=n;
    Fo(i,1,n)
    {
        ll num=v[i];
        while(j>0 && stoll(to_string(num)+to_string(v[j]))>r)
        {
            j--;
        }

        if(j==0)
            continue;
        
        flag1[i]=j;
    }

    j=1;

    for(i=n;i>=1;i--)
    {
         ll num=v[i];
        while(j<=n && stoll(to_string(num)+to_string(v[j]))<l)
            j++;
        
        if(j==n+1)    
            continue;

        flag2[i]=j;
    }

    debug(flag1);
    debug(flag2);
    ll cnt=0;
    Fo(i,1,n)
    {
        if(flag1[i]==-1 || flag2[i]==-1 || flag1[i]<flag2[i])
        {
            continue;
        }

        ll len=flag1[i]-flag2[i]+1;

        cnt+=len;
    }

    cout<<cnt<<endl;

}

void solve(ll x)
{
    ll n;
    string l,r;
    cin>>n;
    cin>>l>>r;
    ll i;

    ll intl=stoll(l);
    ll intr=stoll(r);

    vector<string> vs(n+1);
    fo(i,n)
        cin>>vs[i+1];

    sort(vs.begin()+1,vs.end(),compare);
    ll cnt=0;
    ll in;
 
    ll j;

    j=n;

    ll k;

    vi flag1(n+1,-1);
    vi flag2(n+1,-1);

    Fo(i,1,n)
    {
        string num=vs[i];
        while(j>0 && stoll(num+vs[j])>intr)
        {
            j--;
        }

        if(j==0)
            continue;
        
        flag1[i]=j;

        // ll st=binarySearch2(1,n,vs,num,intl,intr);

        // if(st==0 || st>j)
        //     continue;

        // ll R=stoll(num+vs[j]);
        // ll L=stoll(num+vs[st]);

        // if(R>intr || R<intl || L<intl || L>intr)
        //     continue;

        // ll len=j-st+1;

        // cnt+=len;     

    }

    j=1;

    for(i=n;i>=1;i--)
    {
        string num=vs[i];
        // debug(num);
        // debug(j);
        while(j<n && stoll(num+vs[j])<intl)
            j++;
        
        // debug(j);
        if(j==n)    
            continue;

        flag2[i]=j;
    }

    // debug(flag1);
    // debug(flag2);

    Fo(i,1,n)
    {
        if(flag1[i]==-1 || flag2[i]==-1 || flag1[i]<flag2[i])
        {
            continue;
        }

        ll len=flag1[i]-flag2[i]+1;

        cnt+=len;
    }
    ll cnt1=0;

    Fo(i,1,n)
    {
        string num=vs[i];
        ll ed=binarySearch1(1,n,vs,num,intl,intr);

        ll st=binarySearch2(1,n,vs,num,intl,intr);

        if(ed==n+1 || st==0)
            continue;
        
        ll R=stoll(num+vs[ed]);
        ll L=stoll(num+vs[st]);

        if(R>intr || R<intl || L<intl || L>intr)
            continue;

        ll len=ed-st+1;

        cnt1+=len; 
    }

    debug(cnt1);
    cout<<cnt<<endl;
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