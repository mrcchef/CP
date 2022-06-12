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
    struct node{// variable
        mii arr; // freq of each element 
        mii odd,even; // freq of freq 
        ll oddFreq,evenFreq;
        node(){ // constructor 
            arr.clear();
            odd.clear();
            even.clear();
            oddFreq=evenFreq=0;
        }
        // + operator overloading
        friend node const operator + (const node &a,const node &b){
            // TC : x=number of distinct elements 
            // xlogx
            node res;
            res.arr=a.arr;
            for(auto &ele:b.arr)
                res.arr[ele.first]+=ele.second;
            
            for(auto &ele:res.arr)
            {
                if(ele.second&1)
                {
                    res.oddFreq++;
                    res.odd[ele.second]++;
                }
                else
                {
                    
                    res.evenFreq++; 
                    res.even[ele.second]++;
                }
            }

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
            v[id].oddFreq=1;
            v[id].arr[val]=1;
            v[id].odd[v[id].arr[val]]=1;
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
    ll get(int l,int r,int k){

        if(r-l+1<k)
            return -1;
        
        node res=query(l,r);
        if(res.oddFreq==k)
            return 0;
        
        ll req=abs(k-res.oddFreq);
        
        if(req&1)
            return -1;

        
        ll cnt=0;

        if(res.oddFreq<k)
        {
            for(auto it=res.even.begin();it!=res.even.end() && req>0 ;it++)
            {
                ll total=2*it->second;
                ll mn=min(req,total);
                req-=mn;
                cnt+=mn/2;
                res.odd[it->first-1]+=mn/2;
                res.odd[1]+=mn/2;
            }

            if(req==0)
                return cnt;
            
            for(auto it=res.odd.begin();it!=res.odd.end() && req>0 ;it++)
            {
                if(it->first<=1)
                    continue;
                
                ll mn=min(req,it->first*it->second);
                req-=mn;

                cnt+=mn;
            }    
        }
        else
        {
            for(auto it=res.odd.begin();it!=res.odd.end() && req>0 ;it++)
            {
                if(it->first<=1)
                    continue;
                
                ll total=((it->first/2)*it->second);
                ll mn=min(req,total);
                req-=mn;
                cnt+=2*mn;
            }
        }

        if(req==0)
            return cnt;
        else
            return -1;
    }
};

void solve()
{
    ll n,q;
    cin>>n>>q;
    ll i;
    vi v(n);
    SegTree sg(n);
    fo(i,n)
    {
        cin>>v[i];
        sg.update(i+1,v[i]);
    }


    fo(i,q)
    {
        ll l,r,k;
        cin>>l>>r>>k;

        ll ans=sg.get(l,r,k);
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