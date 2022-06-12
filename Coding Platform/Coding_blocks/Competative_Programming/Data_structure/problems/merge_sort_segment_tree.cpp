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

// KQUERY - K-query

// in merged sort segment tree we build the segment tree 
// and it is used when the vectors are needed to be stored in a node

struct SegTree{
    struct node{
        // variable
        vi elements;
        node(){ // constructor 
            elements.clear();
        }
        // + operator overloading
        friend node const operator + (const node &a,const node &b){
            // node res;
            // res.val = a.val + b.val;
            // return res;
        }
    };
    int n;
    vector<node> v; 
    node dummy; // dummy node
    SegTree(int n){
        this->n = n;
        v.assign(4*n+10,dummy);
    }
    
    // TC : logn*logn
    ll query(int id,const int l,const int r,const int s,const int e,const int k){
        if(s>e || r<s || l>e) return 0;
        else if(l<=s && e<=r){
            ll in=upper_bound(all(v[id].elements),k)-v[id].elements.begin();
            return v[id].elements.size()-in;
        } 
        else return query(2*id,l,r,s,(s+e)/2,k) + query(2*id+1,l,r,(s+e)/2+1,e,k);
    }
    ll query(const int l,const int r,const int k){
        return query(1,l,r,1,n,k);
    }

    void mergeNodes(int id)
    {
        vi mergedEle;
        vi leftEle=v[2*id].elements;
        vi rightEle=v[2*id+1].elements;
        ll leftSz=leftEle.size();
        ll rightSz=rightEle.size();
        int i=0,j=0;
        while(i<leftSz && j<rightSz)
        {
            if(leftEle[i]<rightEle[j])
            {
                mergedEle.pb(leftEle[i++]);
            }
            else
                mergedEle.pb(rightEle[j++]);
        }

        while(i<leftSz)
            mergedEle.pb(leftEle[i++]);
        
        while(j<rightSz)
            mergedEle.pb(rightEle[j++]);

        v[id].elements=mergedEle;
    }

    // TC : nlogn 
    void build(int id,vi &arr,int s,int e)
    {
        if(s>e)
            return;
        
        if(s==e)
        {
            v[id].elements.clear();
            v[id].elements.pb(arr[s]);
            return;
        }

        ll mid=(s+e)/2;
        build(2*id,arr,s,mid);
        build(2*id+1,arr,mid+1,e);
        
        mergeNodes(id);
    }

    void build(vi &arr)
    {
        build(1,arr,1,n);
    }
};

void solve()
{
    ll n,i;
    cin>>n;

    vi v(n+1);
    fo(i,n)
        cin>>v[i+1];
    
    ll q;
    cin>>q;

    SegTree sg(n);
    sg.build(v);

    fo(i,q)
    {
        ll x,y,k;
        cin>>x>>y>>k;
        ll ans=sg.query(x,y,k);
        cout<<ans<<endl;
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