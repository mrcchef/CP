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
const ll inf=1e9;
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


// GSS3 - Can you answer these queries III

// Commented area needs to be changed according to the need
// this segment tree is for range sum queries
struct SegTree{
    struct node{
        // variable
        ll sum ;
        ll prefSum;
        ll suffSum;
        ll ans;
        node(){ // constructor 
            sum=0;
            prefSum=suffSum=-inf;
            ans=-inf;
        }

        node(ll val)
        {
            sum=prefSum=suffSum=ans=val;
        }
        // + operator overloading
        friend node const operator + (const node &a,const node &b){
            node res;
            res.ans =max(a.ans , b.ans);
            res.ans=max(res.ans,a.suffSum+b.prefSum);
            res.sum=a.sum+b.sum;
            res.prefSum=max(a.prefSum,a.sum+b.prefSum);
            res.suffSum=max(b.suffSum,a.suffSum+b.sum);
            return res;
        }
    };
    int n;
    vector<node> v; 
    node dummy;
     // dummy node
    SegTree(int n){
        this->n = n;
        v.assign(4*n+10,dummy);
    }
    void update(int id,const int pos,const int val,int s,int e){
        if(s>e) return;
        if(s==e){ // base case
            v[id]=node(val);
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
        if(s>e || r<s || l>e)
        {
            return dummy;
        } 
        else if(l<=s && e<=r){
            return v[id];
        }   
        else
        {
            node res=query(2*id,l,r,s,(s+e)/2) + query(2*id+1,l,r,(s+e)/2+1,e);
            return res;
        } 
        // above else return is query dependent
    }
    node query(const int l,const int r){
        return query(1,l,r,1,n);
    }
    ll get(int l,int r){
        return query(l,r).ans;
    }

    void build(int id,int s,int e,vi &arr)
    {
        if(s>e)
            return ;

        if(s==e)
        {
            v[id]=node(arr[s]);
        //     debug(mp(s,e));
        // debug(v[id].ans);
            return;
        }

        int mid=(s+e)/2;
        build(2*id,s,mid,arr);
        build(2*id+1,mid+1,e,arr);

        v[id]=v[2*id]+v[2*id+1];
        // debug(mp(s,e));
        // debug(v[id].ans);
    }

    void build(vi &arr)
    {
        build(1,1,n,arr);
    }
};

void solve()
{
    ll n,i;
    cin>>n;
    vi v(n+1);
    fo(i,n)
        cin>>v[i+1];

    SegTree sg(n);

    sg.build(v);

    ll q;
    cin>>q;
    fo(i,q)
    {
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        ll ans=0;
        // splitting is really important 
        if(x2>y1)
        {
            ll contri1=x1<=y1?sg.query(x1,y1).suffSum:0;
            ll contri2=y1+1<=x2-1?sg.query(y1+1,x2-1).sum:0;
            ll contri3=x2<=y2?sg.query(x2,y2).prefSum:0;
            ans=contri1+contri2+contri3;
        }   
        else
        {
            // here we have done spillting such that both the suffSum and prefSum
            // must be added to get a possible ans
            // eg 3 3 -9
            // query 1 3 2 3
            // possibleAns1=suffSum(1,1)+prefSum(2,3)
            // possibleAns1=3+3=>6
            // we could also have written
            // possibleAns1=suffSum(x1,x2)+prefSum(x2+1,y2)
            // possibleAns1=6+(-9)
            // adding -9 does not gives us the maximum ans
            // and prefSum become optional reason begin x2 is already 
            // included in suffSum(x1,x2) with meets the condition 
            // x1<=i<=y1 and x2<=j<=y2 such that x2<=y1
            ll possibleAns1=sg.query(x1,x2-1).suffSum+sg.query(x2,y2).prefSum;
            ll possibleAns2=sg.query(x1,y1).suffSum+sg.query(y1+1,y2).prefSum;
            ll possibleAns3=sg.query(x2,y1).ans;
            ans=Max(possibleAns1,possibleAns2,possibleAns3);
        }

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