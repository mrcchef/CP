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
#define pb push_back
#define vi vector<ll>
#define endl "\n"
const ll inf=1e18;


// Commented area needs to be changed according to the need
// this segment tree is for range sum queries
struct SegTree{
    struct node{
        // variable
        ll sum,prefSum,suffSum,ans ;
        node(){ // constructor 
            sum=prefSum=suffSum=-inf;
            ans=-inf;
        }

        node(ll val)
        {
            sum=val;
            prefSum=suffSum=ans=max(0LL,val);
        }
        // + operator overloading
        friend node const operator + (const node &a,const node &b){
            node res;
            res.sum=a.sum+b.sum;
            res.prefSum=max(a.prefSum,a.sum+b.prefSum);
            res.suffSum=max(b.suffSum,b.sum+a.suffSum);
            res.ans=max(max(a.ans,b.ans),a.suffSum+b.prefSum);
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
            // cout<<s<<" "<<e<<endl;
            v[id].sum=v[id].prefSum=v[id].suffSum=v[id].ans=val;
            // v[id]=node(val);
            // cout<<v[id].ans<<endl;
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
        else
        {
            node lf=query(2*id,l,r,s,(s+e)/2);
            node rt=query(2*id+1,l,r,(s+e)/2+1,e);
            return lf+rt;
        } 
            
        // above else return is query dependent
    }
    node query(const int l,const int r){
        return query(1,l,r,1,n);
    }
    ll get(int l,int r){
        return query(l,r).ans;
    }
};

void solve()
{
    ll n,i;
    cin>>n;
    vi v(n);
    
    SegTree sg(n);

    fo(i,n)
    {
        cin>>v[i];
        sg.update(i+1,v[i]);
    }

    ll q;
    cin>>q;
    fo(i,q)
    {
        ll type;
        cin>>type;
        if(type==1)
        {
            ll x,y;
            cin>>x>>y;
            ll res=sg.get(x,y);
            cout<<res<<endl;
        }
        else
        {
            ll in,val;
            cin>>in>>val;
            sg.update(in,val);
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
