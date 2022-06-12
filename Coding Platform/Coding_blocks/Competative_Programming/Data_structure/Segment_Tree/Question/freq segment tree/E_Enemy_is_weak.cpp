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

class segtree{
    public:
    vector<long long> tree;
    long long node;
    segtree(long long n)
    {
        node=n;
        long long len=4*n+1;
        tree.assign(len+1,0);
    }

    void task(long long in)
    {
        tree[in]=tree[2*in]+tree[2*in+1];
    }

    void build(vector<long long> &arr, long long st,long long ed,long long in)
    {
        if(st>ed)
            return;
        
        if(st==ed)
        {
            tree[in]=arr[st];
            return;
        }

        long long mid=(st+ed)/2;
        build(arr,st,mid,2*in);
        build(arr,mid+1,ed,2*in+1);

        task(in);
    }
    
    long long rsum(ll st,ll ed,ll qst,ll qed,ll in)
    {
        if(ed<qst || st>qed)
            return 0;
        
        if(qst<=st && qed>=ed)
            return tree[in];
        
        long long mid=(st+ed)/2;

        ll mn=rsum(st,mid,qst,qed,2*in)+rsum(mid+1,ed,qst,qed,2*in+1);

        return mn;
    }

    void update(ll st,ll ed,ll in,ll pos,ll val)
    {
        if(st>ed)
            return;
        
        if(st==ed)
        {
            tree[in]+=val;
            return;
        }

        ll mid=(st+ed)/2;

        if(pos<=mid)
            update(st,mid,2*in,pos,val);
        else
            update(mid+1,ed,2*in+1,pos,val);

        task(in);
    }
};

void solve()
{
    ll n,i;
    cin>>n;
    
    vi v(n);

    fo(i,n)
        cin>>v[i];

    // Here we are transforming our element range from 1<=x<=1e9 to 1<=x<=1e6
    // as the length of array is atmost 1e6    
    vi arr(all(v));

    sort(all(arr));

    for(auto &val:v)
        val=lower_bound(all(arr),val)-arr.begin()+1;
    
    ll ans=0;

    // debug(v);

    segtree seg1(n),seg2(n);

    for(auto val:v)
    {
        // seg1 stores the number of values greater that the element x
        // seg2 stores the freqency of values
        // so selecting a triplet, the minimum value element in the triplet is the current element val
        // now we need to select 2 elements 
        // for the 2nd elements we can choose elements greater than val one by one
        // and after selecting the 2nd max element, we can add the number of elemets greater then 2nd max

        // the same thing is done through below line, we are adding the range sum from 
        // val+1 to n(the maximum possible number)  

        ans+=seg1.rsum(1,n,val+1,n,1);
        
        // after than we need add the number of elements which are greater than val i.e val+1 to n
        
        seg1.update(1,n,1,val,seg2.rsum(1,n,val+1,n,1));
        
        // increasing the frequency of the element by one
        
        seg2.update(1,n,1,val,1);

        // i<j<k is automatically handeled as at each index i we are considering the greater element 
        // for the index less than i
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
};