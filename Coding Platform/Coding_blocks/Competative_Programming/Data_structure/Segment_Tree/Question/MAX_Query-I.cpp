// You are given an array A of N elements and Q queries. Each query consists of 3 integers L R K. For each query, 
// you have to find the number of elements Ax1, Ax2,….,Axj>=K, where L<=x1, x2,…xj<=R.

// Input Format
// First line contains an integer N, denoting the number of elements in the array A. Next line contains N integers 
// denoting the elements of the array. Next line contains a single integer Q, denoting the number of queries.
//  Next Q lines contains Q queries, consisting of 3 integers each, L R K.

// Constraints
// 1<=N,Q<=10^5
// |Ai|, |K|<=10^9
// 1<=L, R<=N

// Output Format
// Print Q lines, where ith line contains the answer to the ith query.

#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<=n;i++)
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define endl "\n"
#define deb(x) cout << #x << "=" << x << endl
const ll mod = 1e9+7;

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

void buildSeg(vi *tree,ll st,ll ed,ll index,vi &v)
{
    if(st==ed)
    {
        // vi temp;
        // tree.pb(temp);
        tree[index].pb(v[st]);
        return;
    }

    ll mid=(st+ed)/2;
    // deb(mid);
    buildSeg(tree,st,mid,2*index,v);
    buildSeg(tree,mid+1,ed,2*index+1,v);

    ll i=0,j=0,k=0;

    while(i<tree[2*index].size() && j<tree[2*index+1].size())
    {
        if(tree[2*index][i]<tree[2*index+1][j])
            tree[index].pb(tree[2*index][i++]);
        else
            tree[index].pb(tree[2*index+1][j++]);
    }

    while(i<tree[2*index].size())
    {
        tree[index].pb(tree[2*index][i++]);
    }

    while(j<tree[2*index+1].size())
    {
        tree[index].pb(tree[2*index+1][j++]);
    }
    return;
}

ll query(vi *tree,ll st,ll ed,ll qs,ll qe,ll index,ll k,ll n)
{
    if(st>=qs && ed<=qe)
    {
        auto it=lower_bound(tree[index].begin(),tree[index].end(),k);
        ll val=0;

        val+=it-tree[index].begin();
        return tree[index].size()-val;
    }

    if(ed<qs || qe<st)
        return 0;
    
    ll mid=(st+ed)/2;

    return query(tree,st,mid,qs,qe,2*index,k,n)+query(tree,mid+1,ed,qs,qe,2*index+1,k,n);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll n,i;
        cin>>n;
        vi v(n);
        fo(i,n)
            cin>>v[i];
        
        vector<ll> *tree=new vi[4*n+1];

        buildSeg(tree,0,n-1,1,v);

        ll q;
        cin>>q;
        while(q--)
        {
            ll x,y,k;
            cin>>x>>y>>k;
            cout<<query(tree,0,n-1,x-1,y-1,1,k,n)<<endl;
        }

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