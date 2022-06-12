#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define pb push_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define endl "\n"
#define deb(x) cout << #x << "=" << x << endl
const ll mod = 1e9+7;

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

void segtree(ll *a,ll st,ll ed,ll *tree,ll index)
{
    if(st==ed)
    {
        tree[index]=a[st];
        return;
    }
    ll mid=(st+ed)/2;
    segtree(a,st,mid,tree,2*index);
    segtree(a,mid+1,ed,tree,2*index+1);
    tree[index]=min(tree[2*index],tree[2*index+1]);
}

ll query(ll *tree,ll ss,ll se,ll qs,ll qe,ll index)
{
    if(ss>=qs && se<=qe)
    {
        return tree[index];
    }

    if(ss>qe || se<qs)
        return INT_MAX;
    ll mid=(ss+se)/2;

    return min(query(tree,ss,mid,qs,qe,2*index),query(tree,mid+1,se,qs,qe,2*index+1));

}

void update_node(ll *tree,ll st,ll ed,ll ind,ll val,ll index)
{
    if(ind>ed || ind<st)
        return;
    // if(ed<ind || ind<st)
    //     return ;
    if(ed==st)
    {
        tree[index]+=val;
        return ;
    }
    ll mid=(st+ed)/2;
    update_node(tree,st,mid,ind,val,2*index);
    update_node(tree,mid+1,ed,ind,val,2*index+1);
    
    tree[index]=min(tree[2*index],tree[2*index+1]);

}

void update(ll *tree,ll ss,ll se,ll qs,ll qe,ll val,ll index)
{
    if(qe<ss || qs>se)
        return ;

    if(ss==se)
    {
        tree[index]+=val;
        return ;
    }    

    ll mid=(ss+se)/2;
    update(tree,ss,mid,qs,qe,val,2*index);
    update(tree,mid+1,se,qs,qe,val,2*index+1);

    tree[index]=min(tree[2*index],tree[2*index+1]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,i;
    cin>>n;
    ll a[n];
    fo(i,n)
        cin>>a[i];
    ll tree[4*n+2];
    segtree(a,0,n-1,tree,1);
    for(i=1;i<4*n+2;i++)
    {
        cout<<tree[i]<<" ";
    }
    cout<<endl;
    // update for a single node
    // ll val,ind;   
    // cin>>ind>>val;
    // update_node(tree,0,n-1,ind,val,1);
    // for(i=1;i<4*n+2;i++)
    // {
    //     cout<<tree[i]<<" ";
    // }
    // cout<<endl;

    // update for range of elelments
    ll L,R,val;
    cin>>val>>L>>R;
    update(tree,0,n-1,L,R,val,1);
     for(i=1;i<4*n+2;i++)
    {
        cout<<tree[i]<<" ";
    }
    cout<<endl;

    ll q;
    cin>>q;
    while(q--)
    {
        ll l,r;
        cin>>l>>r;
        cout<<query(tree,0,n-1,l,r,1)<<endl;
    }
 return 0;
}
ll fxp(ll a,ll b,ll m) {
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp(m_m(a,a,m),b/2,m);
    return m_m(fxp(a,b-1,m),a,m);
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