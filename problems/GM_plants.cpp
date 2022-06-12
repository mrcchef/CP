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
        ll odd,len,turns;
        node(){ // constructor 
            odd=0;
            len=1;
            turns=0;
        }
        friend node const operator + (const node &a,const node &b){
            node res;
            res.odd=a.odd+b.odd;
            res.len=a.len+b.len;
            res.turns=0;
            return res;
        }
    };
    int n;
    vector<node> v , lazy; 
    node dummy; // dummy node
    SegTree(int n){
        this->n = n;
        v.assign(4*n+10,dummy);
        lazy.assign(4*n+10 , dummy);
    }
    void update(int id,const int pos,const long long val,int s,int e){
        if(s>e) return;
        if(s==e){ // base case
            v[id].odd = val;
            v[id].len = 1;
            return;
        }
        int mid = (s+e)/2;
        if(pos<=mid) update(2*id,pos,val,s,mid);
        else update(2*id+1,pos,val,mid+1,e);
        v[id] = v[2*id] + v[2*id+1];
        return;
    }
    void change(const int id,const long long val){ // change function
        // if(val&1)
        // {
        // }
        v[id].odd = v[id].len-v[id].odd;
        lazy[id].turns=val; 
    }
    void push(const int id){
        change(2*id,lazy[id].turns);
        change(2*id+1,lazy[id].turns);
        lazy[id].turns=0;
    }
    void update_range(int id,const long long val,const int l,const int r,const int s,const int e){
        // vi v={id,val,l,r,s,e};
        // debug(v);
        if(e<l || r<s) return;
        if(l<=s && e<=r){
            // v[id].
            change(id,0);
            return;
        }
        push(id);
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
        if(l<=s && e<=r) return v[id];
        push(id);
        return query(2*id,l,r,s,(s+e)/2) + query(2*id+1,l,r,(s+e)/2+1,e);
    }
    node query(const int l,const int r){
        return query(1,l,r,1,n);
    }
    ll get(int l,int r){
        
        return query(l,r).odd;
    }
};

void solve()
{
    ll x,y,z,q;
    cin>>x>>y>>z>>q;

    SegTree sg1(x+1),sg2(y+1),sg3(z+1);
    
    // sg[0]=SegTree(x);
    // sg[1]=SegTree(y);
    // sg[2]=SegTree(z);
    ll i;
    fo(i,q)
    {
        ll type;
        cin>>type;
        // debug(type);
        if(type==3)
        {
            ll x1,y1,z1,x2,y2,z2;
            cin>>x1>>y1>>z1>>x2>>y2>>z2;
            ll oddx,evenx;
            oddx=sg1.get(x1+1,x2+1);
            evenx=x2-x1+1-oddx;

            ll oddy,eveny;
            oddy=sg2.get(y1+1,y2+1);
            eveny=y2-y1+1-oddy;

            ll oddXY=oddx*(eveny)+evenx*oddy;
            ll evenXY=(x2-x1+1)*(y2-y1+1)-oddXY;

            ll oddz,evenz;
            
            oddz=sg3.get(z1+1,z2+1);
            evenz=z2-z1+1-oddz;

            // debug(mp(oddx,evenx));
            // debug(mp(oddy,eveny));
            // debug(mp(oddz,evenz));

            ll ans=evenXY*oddz+oddXY*evenz;
            cout<<ans<<endl;
        }   
        else
        {
            ll l,r;
            cin>>l>>r;
            if(type==0)
            {
                // debug("in");
                sg1.update_range(l+1,r+1,1);
            }
            else if(type==1)
                sg2.update_range(l+1,r+1,1);
            else if(type==2)
                sg3.update_range(l+1,r+1,1);
            // sg[type].update_range(l,r,1);
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