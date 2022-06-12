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

// Commented area needs to be changed according to the need
// this segment tree is for range sum queries
struct SegTree{
    struct node{
        // variable
        ll sum ;
        node(){ // constructor 
            sum = 0;
        }
        // + operator overloading
        friend node const operator + (const node &a,const node &b){
            node res;
            res.sum = a.sum + b.sum;
            return res;
        }
    };
    int n;
    vector<node> v; 
    node dummy; // dummy node
    SegTree(int n){
        this->n = n;
        v.assign(4*n+10,dummy);
    }
    void update(int id,const int pos,const int val,int s,int e){
        if(s>e) return;
        if(s==e){ // base case
            v[id].sum += val;
            return;
        }
        int mid = (s+e)/2;
        if(pos<=mid) update(2*id,pos,val,s,mid);
        else update(2*id+1,pos,val,mid+1,e);
        // operation after updation of child nodes
        v[id] = v[2*id] + v[2*id+1];
        return;
    }
    void update(const int pos,const int val){
        update(1,pos,val,1,n);
    }
    node query(int id,const int l,const int r,const int s,const int e){
    
        if(s>e || r<s || l>e) return dummy;
        else if(l<=s && e<=r) return v[id];
        else return query(2*id,l,r,s,(s+e)/2) + query(2*id+1,l,r,(s+e)/2+1,e);
        // above else return is query dependent
    }
    node query(const int l,const int r){
        return query(1,l,r,1,n);
    }
    ll get(int l,int r){
        return query(l,r).sum;
    }

    void build(int id,int st,int ed)
    {
        if(st>ed)
            return;
        if(st==ed)
        {
            // debug(mp(st,ed));
            v[id].sum=1;
            return;
        }

        int mid=st+(ed-st)/2;

        build(2*id,st,mid);
        build(2*id+1,mid+1,ed);

        v[id]=v[2*id]+v[2*id+1];
    }
};

struct node{
    ll in;
    ll l,r;
    ll k;

    node()
    {

    }

    node(ll _in,ll _l,ll _r,ll _k)
    {
        in=_in;
        l=_l;
        r=_r;
        k=_k;
    };
};

static bool compare(node &n1,node &n2)
{
    return n1.k<n2.k;
}

void solve()
{
    ll n,i;
    cin>>n;

    vector<pii> vp(n);
    
    fo(i,n)
    {
        cin>>vp[i].first;
        vp[i].second=i+1;
    }

    ll q;
    cin>>q;

    vector<node> quries(q);

    fo(i,q)
    {
        ll l,r,k;
        cin>>l>>r>>k;
        pair<ll,pii> p;
        
        quries[i]=node(i,l,r,k);
    }

    sort(all(quries),compare);
    sort(all(vp));
    SegTree sg(n);
    sg.build(1,1,n);
    ll j;

    i=0;

    vi ans(q);

    fo(j,q)
    {
        while(i<n && vp[i].first<=quries[j].k)
        {
            sg.update(vp[i].second,-1);
            i++;
        }
        ll tans=sg.get(quries[j].l,quries[j].r);
        ans[quries[j].in]=tans;
    }

    for(auto val:ans)
        cout<<val<<endl;
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