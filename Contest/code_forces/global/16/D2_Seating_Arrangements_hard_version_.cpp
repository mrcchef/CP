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
                fen[i]+=val;
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
    ll n,m,i,j;
    cin>>n>>m;

    ll sz=n*m;

    vi v(sz);
    vector<pii> arr(sz);
    map<ll,vi> hm;

    fo(i,sz)
    {
        cin>>v[i];
        arr[i]={v[i],i+1};
    }

    sort(all(arr));

    // stores pairs of 
    map<pii,ll> hm3;

    fo(i,sz)
    {
        hm[v[i]].pb(i+1);
        hm3[arr[i]]=i+1;
    }

    // for(auto val:hm)
    // {
    //     debug(val.first);
    //     debug(val.second);
    // }

    vector<fenwick> ds(n+1,fenwick(m+1));

    map<ll,set<pii>> hm2;
    // e1, e2, e3
    // e3, e1, e2
     
    ll ans=0;

    map<int,pii> cor;

    fo(i,sz)
    {
        ll in=hm3[arr[i]];
        ll r=(in+m-1)/m;
        ll c=in%m;

        // ll r=in/m;
        // ll c=in%m;
        // r+=1;
        // c+=1;
        if(c==0)
            c=m;

        cor[arr[i].second]={r,c};

        hm2[arr[i].first].insert({-c,r});
    }

    // 1 5 3
    // 1 3 5

    // 0 1 2
    // 

    // 
    // 2->5
    // 1->4
    // 1->3
    // 2->6
    // 2->1
    
    // 1->4,3
    // 2->5,6,1

    // 1 1 1
    // 1 1 2
    // 3 4 4

    // _  _ 1
    //    _

    // 3 4_ _4

    // 
    //  


    for(auto val:hm2)
    {
        debug(val);
    }

    // iterating on original array
    fo(i,sz)
    {
        // ll r,c;
        // r=cor[i].first;
        // c=cor[i].second;



        auto it=hm2[v[i]].begin();
        ll r=it->second;
        ll c=it->first*-1;

        debug(mp(r,c));
        debug(mp(v[i],i));
        hm2[v[i]].erase(it);

        ll tans=ds[r].rsum(1,c);
        if(1>=c)
            tans=0;
        debug(tans);
        ds[r].update(c,1);
        ans+=tans;
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