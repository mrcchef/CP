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
        ll len ;
        ll open;
        ll close;
        ll match;
        node(){ // constructor 
            len=open=close=match=0;
        }

        node(ll _open,ll _close)
        {
            len=1;
            open=_open;
            close=_close;
            match=0;
        }

        // + operator overloading
        friend node const operator + (const node &a,const node &b){
            node res;
            res.len = a.len + b.len;
            ll mn=min(a.open,b.close);
            res.match=a.match+b.match+mn;
            res.open=a.open-mn+b.open;
            res.close=a.close+b.close-mn;
            return res;
        }
    };
    int n;
    vector<node> v; 
    node dummy;
    string str; // dummy node
    SegTree(int n,string& str){
        this->n = n;
        v.assign(4*n+10,dummy);
        this->str=str;
    }
    void update(int id,const int pos,int s,int e){
        if(s>e) return;
        if(s==e){ // base case
            if(str[s]=='(')
                str[s]=')';
            else
                str[s]='(';
            
            v[id]=node(str[s]=='(',str[s]==')');
            return;
        }
        int mid = (s+e)/2;
        if(pos<=mid) update(2*id,pos,s,mid);
        else update(2*id+1,pos,mid+1,e);
        // operation after updation of child nodes
        v[id] = v[2*id] + v[2*id+1];
        return;
    }
    void update(const int pos){
        update(1,pos,1,n);
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
        return query(l,r).len;
    }

    void build(int id,int s,int e)
    {
        if(s>e)
            return;
        
        if(s==e)
        {
            v[id]=node(str[s]=='(',str[s]==')');
            return;
        }

        int mid=(s+e)/2;
        build(2*id,s,mid);
        build(2*id+1,mid+1,e);

        v[id]=v[2*id]+v[2*id+1];
    }

    bool isGood(ll l,ll r)
    {
        node res=query(l,r);
        return (res.close==0 && res.open==0);
    }

    void build()
    {
        build(1,1,n);
    }
};

void solve(ll t)
{
    ll n,i;
    cin>>n;
    string s;
    cin>>s;
    s="#"+s;
    ll q;
    cin>>q;

    SegTree sg(n,s);
    sg.build();

    cout<<"Test "<<t<<":"<<endl;
    fo(i,q)
    {
        ll pos;
        cin>>pos;
        if(pos==0)
        {
            if(sg.isGood(1,n))
                cout<<"YES";
            else
                cout<<"NO";
            cout<<endl;
        }
        else
            sg.update(pos);
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
    while(t<=10)
    {
        solve(t);   
        t++;
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