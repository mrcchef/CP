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

struct SegTree{
    struct node{
        // variable
        ll sum,len,lazy;
        node(){ // constructor 
            sum=lazy=len=0;
        }
        friend node const operator + (const node &a,const node &b){ // merge
            node res;
            res.sum=a.sum+b.sum;
            res.len=a.len+b.len;
            res.lazy=0;
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
    void update(int id,const int pos,const long long val,int s,int e){
        if(s>e) return;
        
        push(id);
        
        if(s==e){ // base case
            v[id].sum += val;
            v[id].len = 1;
            v[id].lazy = 0;
            return;
        }
        int mid = (s+e)/2;
        if(pos<=mid) update(2*id,pos,val,s,mid);
        else update(2*id+1,pos,val,mid+1,e);
        v[id] = v[2*id] + v[2*id+1];
        return;
    }
    void change(const int id,const long long val){ // change function
        // This check is for when s==e then their aren't any other child nodes left
        // and if we are accessing the id that doesn't exsit, It will give us Runtime error
        // b/c of out of bound 
        if(id<4*n+10) 
            v[id].lazy += val;
    }
    void push(const int id){
        v[id].sum+=v[id].len*v[id].lazy;
        change(2*id,v[id].lazy);
        change(2*id+1,v[id].lazy);
        v[id].lazy=0;
    }

    void update_range(int id,const long long val,const int l,const int r,const int s,const int e){
        
        push(id);

        if(e<l || r<s) return;

        if(l<=s && e<=r){
            v[id].lazy=val;
            push(id);
            return;
        }

        int mid = (s+e)/2;
        update_range(2*id,val,l,r,s,mid);
        update_range(2*id+1,val,l,r,mid+1,e);
        v[id] = v[2*id] + v[2*id+1];
    }
    void update_range(const int l,const int r,const long long val){
        update_range(1,val,l,r,1,n);
    }
    void update(const int pos,const long long val){
        update(1,pos,val,1,n);
    }
    node query(int id,const int l,const int r,const int s,const int e){
        if(s>e || r<s || l>e) return dummy;

        push(id);

        if(l<=s && e<=r) return v[id];
        return query(2*id,l,r,s,(s+e)/2) + query(2*id+1,l,r,(s+e)/2+1,e);
    }
    node query(const int l,const int r){
        return query(1,l,r,1,n);
    }
    ll get(int l,int r){
        return query(l,r).sum;
    }
};

void solve()
{
    ll n,q,i;
    cin>>n>>q;
    vi v(n);

    fo(i,n)
        cin>>v[i];

    SegTree sg(n);

    fo(i,q)
    {
        ll t;
        cin>>t;
        if(t==1)
        {
            ll l,r,val;
            cin>>l>>r>>val;

            sg.update_range(l,r,val);
        }
        else
        {
            ll pos;
            cin>>pos;

            ll ans=sg.get(pos,pos);
            ans+=v[pos-1];
            cout<<ans<<endl;
        }
    }
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