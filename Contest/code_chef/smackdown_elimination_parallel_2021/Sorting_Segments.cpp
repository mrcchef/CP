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

ll getCnt(vi &diff,ll k)
{
    int cnt=0;
    int sz=0;
    ll i,n=diff.size();
    bool isStart=false;
    fo(i,n)
    {
        if(diff[i]>0)
        {
            isStart=true;
        }

        if(isStart)
            sz++;

        if(sz==k)
        {
            sz=0;
            isStart=false;
            cnt++;
        }
    }

    debug(sz);

    if(sz!=0)
        cnt++;

    return cnt;
}

void test()
{
    vi v={1,4,3,2,5};

    // sort(v.rend(),v.begin());
    
    // debug(v);
}

void solve()
{
    ll n,k,i;
    cin>>n>>k;
    // test();
    vi v(n);
    fo(i,n)
        cin>>v[i];
    
    vi diff(n);
    bool isSorted=true;
    fo(i,n)
    {
        diff[i]=abs(v[i]-i-1);
        if(diff[i]!=0)
            isSorted=false;
    }
    debug(diff);

    if(isSorted)
    {
        cout<<0<<endl;
        return;
    }

    int cnt=getCnt(diff,k);
    debug(cnt);
    if(cnt==1)
    {
        cout<<1<<endl;
        return;
    }

    vector<ll>::iterator st,ed;
    int sz=0;
    bool check=false;
    vi v2=v;
    auto it2=v2.begin();

    for(auto it=diff.begin();it!=diff.end();it++,it2++)
    {
        if(*it!=0)
        {
            if(sz==0)
            {
                st=it2;
                check=true;
            }
        }

        if(check)
            sz++;
        
        if(sz>k)
        {
            ed=it2;
            break;
        }
    }

    if(sz<=k)
        ed=v2.end();
    
    sort(st,ed);

    debug(v2);
    int in1,in2;
    check=false;
    sz=0;
    for(i=n-1;i>=0;i--)
    {
        if(diff[i]!=0)
        {
            if(sz==0)
            {
                in1=i;
                check=true;
            }
        }

        if(check)
            sz++;
        
        if(sz==k)
        {
            in2=i;
            break;
        }
    }

    if(sz<k)
        in2=0;
    
    auto st2=v.begin()+in2;
    auto ed2=v.begin()+in1+1;

    sort(st2,ed2);

    debug(v);

    vi diff2(n),diff3(n);

    fo(i,n)
    {
        diff2[i]=abs(v[i]-i-1);
        diff3[i]=abs(v2[i]-i-1);
    }

    debug(diff2);
    debug(diff3);

    cnt=min(getCnt(diff2,k),getCnt(diff3,k));
    
    if(cnt==1)
    {
        cout<<2<<endl;
    }
    else
        cout<<3<<endl;

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