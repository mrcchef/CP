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

class fenwick{
    public:
        long long n;
        vector<long long> fen;
        
        fenwick(ll sz)
        {   
            n=sz;
            fen.assign(sz+1,0);
        }
        
        void update(long long in,long long val)
        {
            long long i=in;
            while(i<=n)
            {
                ll range=(i&(-i));
                if(val==1)
                    fen[i]+=val;
                else // xor operation update
                {   
                    debug(i); 
                    debug(mp(fen[i],range));
                    fen[i]=range-fen[i];
                    debug(fen[i]);
                }
                i=i+(i&(-i));
            }
        }

        long long sum(long long in)
        {
            long long i=in;
            long long sm=0;
            while(i>=1)
            {
                sm+=fen[i];
                i=i-(i&(-i));
            }

            return sm;
        }

        long long rsum(long long l,long long r)
        {
            return sum(r)-sum(l-1);
        }

        void rupdate(long long l,long long r,long long val)
        {
            update(l,val);
            if(r+1>n)
                return;
            update(r+1,-val);
        }

        int findLowerBound(long long val)
        {
            int cur=0;
            int prevsum=0;

            for(int i=log2(n);i>=0;i--)
            {
                if((cur+(1LL<<i))<=n && prevsum+fen[cur+(1LL<<i)]<val)
                {
                    cur=cur+(1LL<<i);
                    prevsum+=fen[cur];
                }
            }

            return (cur+1);
        }
};

void solve()
{
    ll n,i;
    cin>>n;
    vi v(n+1);
    fo(i,n)
        cin>>v[i+1];
    
    vector<fenwick> fn(20,fenwick(n));

    Fo(i,1,n)
    {
        ll j;
        for(j=0;j<20;j++)
        {
            if(v[i]&(1<<j))
            {
                fn[j].update(i,1);
            }
        }
    }

    ll q;
    cin>>q;

    fo(i,q)
    {
        ll type;
        cin>>type;
        ll st,ed;
        cin>>st>>ed;
        debug(type);
        debug(st);
        debug(ed);

        if(type==1)
        {
            ll j;
            ll sm=0;
            for(j=0;j<20;j++)
            {
                ll cnt=fn[j].rsum(st,ed);
                debug(mp(j,cnt));
                sm+=cnt*(1<<j);
                debug(sm);
            }
            cout<<sm<<endl;
        }
        else
        {
            debug("in");
            ll x;
            cin>>x;
            ll j;
            for(j=0;j<20;j++)
            {
                if(x&(1<<j))
                {
                    debug(j);
                    fn[j].rupdate(st,ed,0);
                }
            }
        }
    }
    debug("Hello");

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