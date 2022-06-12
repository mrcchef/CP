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
#define ll int
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
        ll type;
        cin>>type;
        ll x,y;
        cin>>x>>y;

        if(type==1)
        {
            ll ans=sg.get(x,y);
            // debug(ans);
            cout<<ans<<endl;
        }
        else
        {
            sg.update(x,y);
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