#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0) ; cout.tie(0);
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
#define popcount(x) __builtin_popcount(x)
#define all(x) x.begin(),x.end()
#define mem(a,v) memset(a,v,sizeof(a))

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

struct node{
    string s;
    ll arr[26]={0};
};

ll find_root(ll i,vi &parent)
{
    if(parent[i]==-1)
        return i;
    return parent[i]=find_root(parent[i],parent);
}

void merge_set(ll i,ll j,vi &parent,vi &rank)
{
    ll r1=find_root(i,parent);
    ll r2=find_root(j,parent);
    
    if(r1!=r2)
    {
        if(rank[r1]<rank[r2])
        {
            parent[i]=j;
            rank[j]+=rank[i];
        }
        else
        {
            parent[j]=i;
            rank[i]+=rank[j];
        }  
      
    }
}

const ll N=2*1e5+50;

vector<vi> G(N);
ll visited[N];


void add_edge(ll i,ll j)
{
    G[i].pb(j);
    G[j].pb(i);
}

void dfs(ll i)
{
    visited[i]=1;
    for(auto node:G[i])
    {
        if(!visited[node])
            dfs(node);
    }
}


void solve()
{
    ll n,i;
    cin>>n;
    vector<vi> v(26);
    vector<string> vs(n);
    fo(i,n)
    {
        string s;
        cin>>s;
        ll j;
        fo(j,s.size())
        {
            ll ch=n+s[j]-'a';
            add_edge(i,ch);
        }
        vs[i]=s;
    }

    // vi parent(26);
    // vi rank(26);
    // fo(i,26)
    // {
    //     parent[i]=-1;
    //     rank[i]=1;
    //     // cout<<rank[i]<<" ";
    // }

    // fo(i,n)
    // {
    //     string s=vs[i];
    //     vi st;
    //     ll j;
    //     fo(j,s.size())
    //     {
    //         ll ch=s[j]-'a';
    //         st.pb(ch);
    //     }

    //     fo(j,st.size())
    //     {
    //         ll k;
    //         for(k=j+1;k<st.size();k++)
    //         {
    //             merge_set(j,k,parent,rank);
    //         }
    //     }
    // }

    // set<ll> st;
    // fo(i,26)
    // {
    //     st.insert(parent[i]);
    // }
    // cout<<st.size()<<endl;
    ll cnt=0;
    for(ll i=n;i<n+26;i++)
    {
        if(!visited[i] && G[i].size()>0)
        {
            dfs(i);
            cnt++;
        }
    }
    cout<<cnt<<endl;

}

int main()
{
    fastio
    int t=1;
    // cin>>t;
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