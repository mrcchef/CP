#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
#include <string>
using namespace std;
#define ll long long int
const double mod = 1e9+7;

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll fxp(ll a,ll b,ll m) {
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp(a*a,b/2,m);
    return fxp(a,b-1,m)*a;
}
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

void build_tree(ll *tree,ll *a,ll index,ll s,ll e)
{
    if(s>e)
        return;
    
    if(s==e)
    {
        tree[index]=a[s];
        return;
    }

    ll mid=(s+e)/2;
    build_tree(tree,a,2*index,s,mid);
    build_tree(tree,a,2*index+1,mid+1,e);
    
    ll left=tree[2*index];
    ll right=tree[2*index+1];

    tree[index]=min(left,right);
}

ll range_query(ll *tree,ll index,ll s,ll e,ll qs,ll qe)
{
    //1.no overlap
    if(s>qe||e<qs)
        return INT_MAX;
    //2. complete overlap
    if(s>=qs && e<=qe)
        return tree[index];
    //3.Partial Overlap

    ll mid=(s+e)/2;
    ll left=range_query(tree,2*index,s,mid,qs,qe);
    ll right=range_query(tree,2*index+1,mid+1,e,qs,qe);
    
    return min(left,right);
}

void single_update(ll *tree,ll index,ll s,ll e,ll i,ll val)
{
    if(s>i||e<i)
        return;
    if(s==e)
    {
        tree[index]=val;
        return;
    }

    ll mid=(s+e)/2;
    single_update(tree,2*index,s,mid,i,val);
    single_update(tree,2*index+1,mid+1,e,i,val);
    ll left=tree[2*index];
    ll right=tree[2*index+1];

    tree[index]=min(left,right);
}

void range_update(ll *tree,ll index,ll s,ll e,ll rs,ll re,ll val)
{
    if(s>re||e<rs)
        return;

    if(s==e)
    {
        tree[index]+=val;
        return;
    }

    ll mid=(s+e)/2;
    range_update(tree,2*index,s,mid,rs,re,val);
    range_update(tree,2*index+1,mid+1,e,rs,re,val);
    ll left=tree[2*index];
    ll right=tree[2*index+1];

    tree[index]=min(left,right);

}

int main()
{
    ll n;
    cin>>n;
    ll *a=new ll[n];
    ll *tree=new ll[4*n+1]; // 4*n+1 is the upper bound of the length of segment tree
    for(ll i=0;i<n;i++) cin>>a[i];
    build_tree(tree,a,1,0,n-1);
    ll i,val,rs,re;
    // cout<<"Enter index and value to be update:";
    // cin>>i>>val;
    cout<<"Enter range:";
    cin>>rs>>re;
    cout<<"enter val:";
    cin>>val;
    range_update(tree,1,0,n-1,rs,re,val);
    //single_update(tree,1,0,n-1,i,val);
    ll q;
    cin>>q;
    while(q--)
    {
        ll qs,qe;
        cin>>qs>>qe;
        cout<<range_query(tree,1,0,n-1,qs,qe)<<endl;
    }
    // cout<<"segment tree array:";
    // for(ll i=1;i<4*n;i++)
    //     cout<<tree[i]<<" ";
 return 0;
}
