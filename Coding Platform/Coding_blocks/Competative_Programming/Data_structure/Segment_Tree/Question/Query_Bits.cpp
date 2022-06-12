// You are given an n-bit integer (initially 0). There are Q queries. Each query is of following type:

// 0 L R: Set all the bits from Lth bit to Rth bit to zero.
// 1 L R: Set all the bits from Lth bit to Rth bit to one.
// 2 L R: Find the integer formed by the bits in range [L, R]. Answer all the queries of type 2. Indexing is 0-based. 
// See the sample test case for clarity.
// Input Format
// First line contains two integers, nand q. Next Q lines contains Q queries.

// Constraints
// 1<=n,q<=200000 0<=L,R<n

// Output Format
// For each query of type 2, print the integer(in decimal) formed by it modulo 109+7.

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

const ll N=1e5+5;

ll pow2[N];

void update(ll *tree,ll *lazy,ll st,ll ed,ll qs,ll qe,ll index,ll state)
{
    if(lazy[index]!=-1)
    {
        tree[index]=lazy[index];
        if(st!=ed)
        {
            lazy[2*index]=lazy[index];
            lazy[2*index+1]=lazy[index];
        }
        lazy[index]=-1;
    }   

    if(ed<qs || qe<st)
    {
        return;
    }

    if(qs<=st && qe>=ed)
    {
        tree[index]=state;
        if(st!=ed)
        {        
            lazy[2*index]=state;
            lazy[2*index+1]=state;
        }
        return;
    }

    ll mid=(st+ed)/2;
    
    update(tree,lazy,st,mid,qs,qe,2*index,state);
    update(tree,lazy,mid+1,ed,qs,qe,2*index+1,state);
}

ll query(ll *tree,ll *lazy,ll st,ll ed,ll qs,ll qe,ll index)
{
    if(lazy[index]!=-1)
    {
        tree[index]=lazy[index];
        if(st!=ed)
        {
            lazy[2*index]=lazy[index];
            lazy[2*index+1]=lazy[index];
        }
        lazy[index]=-1;
    }   

    if(ed<qs || qe<st)
    {
        return 0;
    }

    if(qs<=st && qe>=ed)
    {
        ll range=qe-st+1;
        ll val=(pow2[range]-1)*pow2[qe-ed];
        return val%mod;
    }

    ll mid=(st+ed)/2;
    
    ll v1=query(tree,lazy,st,mid,qs,qe,2*index);
    ll v2=query(tree,lazy,mid+1,ed,qs,qe,2*index+1);

    return (v1+v2)%mod;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;

    pow2[0]=1;
    for(ll i=1;i<=N;i++)
    {
        pow2[i]=(pow2[i-1]*2)%mod;
        // pow2[i]%=mod;
    }
    // cin>>t;
    while(t--)
    {
        ll n,i,q;
        cin>>n>>q;
        
        ll *tree=new ll[4*n+1]{0};
        ll *lazy=new ll[4*n+1];
        
        memset(lazy,-1,sizeof(lazy));

        fo(i,q)
        {
            ll x,l,r;
            cin>>x>>l>>r;
            if(x==0)
            {
                update(tree,lazy,0,n-1,l,r,1,0);
            }
            else if(x==1)
            {
                update(tree,lazy,0,n-1,l,r,1,1);
            }
            else
            {
                cout<<query(tree,lazy,0,n-1,l,r,1)<<endl;
            }
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