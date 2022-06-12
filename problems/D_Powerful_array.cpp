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

const ll MAXELE=1e6+5; // max range of elements
const ll BLK=700; // block size

struct data{
    ll l,r,in;
    data(){}

    data(ll _l,ll _r,ll _in)
    {
        l=_l;
        r=_r;
        in=_in;
    }
};

bool compare(data &d1,data &d2)
{
    if(d1.l/BLK==d2.l/BLK)
        return d1.r<d2.r;
    return d1.l<d2.l;
}

class MosAlgo{
    public:
    ll ML,MR,res,q;
    vector<data> query;
    vi arr;
    vi freq;

    MosAlgo(ll _q,vector<data> _query,vector<ll> _arr)
    {
        q=_q,query=_query,arr=_arr,ML=0,MR=-1,res=0,freq.assign(MAXELE,0);
    }

    void addMo(ll in)
    {
        res-=freq[arr[in]]*freq[arr[in]]*arr[in];
        freq[arr[in]]++;
        res+=freq[arr[in]]*freq[arr[in]]*arr[in];
    }

    void removeMo(ll in)
    {
        res-=freq[arr[in]]*freq[arr[in]]*arr[in];
        freq[arr[in]]--;
        res+=freq[arr[in]]*freq[arr[in]]*arr[in];
    }

    vi mos()
    {
        ll i;
        vi ans(q);
        fo(i,q)
        {
            ll l=query[i].l;
            ll r=query[i].r;
            // debug(mp(l,r));
            //add
            while(MR<r)
                MR++,addMo(MR);

            while(ML>l)
                ML--,addMo(ML);

            // remove
            while(MR>r)
                removeMo(MR),MR--;

            while(ML<l)
                removeMo(ML),ML++;
            // debug(res);
            ans[query[i].in]=res;
        }
        return ans;
    }
};

void solve()
{
    ll n,q;
    cin>>n>>q;
    ll i;
    vi v(n);
    fo(i,n)
        cin>>v[i];
    
    vector<data> query(q);

    fo(i,q)
    {
        ll l,r;
        cin>>l>>r;
        l--,r--;
        // debug(mp(l,r));
        query[i]=data(l,r,i);
    }

    sort(all(query),compare);

    MosAlgo mosAlgo(q,query,v);
    // debug(v);
    vi ans=mosAlgo.mos();
    // debug(ans);
    fo(i,q)
        cout<<ans[i]<<endl;

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