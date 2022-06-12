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
// const ll inf=1e18;
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
    ll n,i;
    cin>>n;
    vector<string> vs(3);

    fo(i,3)
    {
        cin>>vs[i];
    }

    ll j,k;
    i=j=k=0;

    string res;

    while(i<2*n && j<2*n && k<2*n)
    {
        ll count=(vs[0][i]=='0')+(vs[1][j]=='0')+(vs[2][k]=='0');
        char ch;
        
        if(count>=2)
        {
            ch='0';
        }
        else
            ch='1';
        
        res+=ch;

        if(vs[0][i]==ch)
            i++;
        
        if(vs[1][j]==ch)
            j++;

        if(vs[2][k]==ch)
            k++;
        
        debug(i)
        debug(j)
        debug(k)
    }

    ll rem=3*n-res.size();
    debug(i);
    debug(j);
    debug(k);
    if(i!=2*n && 2*n-i<=rem)
    {
        res+=vs[0].substr(i);
    }
    else if(j!=2*n && 2*n-j<=rem)
    {
        res+=vs[1].substr(j);
    }
    else if(k!=2*n && 2*n-k<=rem)
    {
        res+=vs[2].substr(k);
    }

    ll req=3*n-res.size();

    fo(i,req)
        res+='1';

    cout<<res<<endl;


}

void helper(ll in,string s,vector<pii> &cnt)
{
    ll c=0;
    ll i=0;
    ll n=s.size();
    fo(i,n)
    {
        if(s[i]=='0')
            c++;
    }

    cnt.pb({c,in});
}

void solve2()
{
    ll n,i;
    cin>>n;
    vector<string> vs(3);

    vector<pii> cnt;

    fo(i,3)
    {
        cin>>vs[i];
        helper(i,vs[i],cnt);
    }

    sort(all(cnt));

    string s1,s2;
    ll len;
    char ch;
    if(cnt[1].first>n)
        s1=vs[cnt[1].second],s2=vs[cnt[2].second],ch='0',len=cnt[1].first;
    else
        s1=vs[cnt[0].second],s2=vs[cnt[1].second],ch='1',len=2*n-cnt[1].first;
    
    string res;

    string lcs;
    fo(i,len)
        lcs+=ch;
    ll k=0;
    ll j;
    i=j=0;

    debug(lcs);

    len=min(len,n);

    while(k<len)
    {
        while(i<2*n && s1[i]!=ch)
            res+=s1[i++];

        while(j<2*n && s2[j]!=ch)
            res+=s2[j++];

        res+=ch;
        k++;
        i++;
        j++;
    }

    debug(res);

    while(i<2*n)
        res+=s1[i++];
    
    while(j<2*n)
        res+=s2[j++];

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
        solve2();   
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

