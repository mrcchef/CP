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

vi graph[200005];
ll N;


void multi_source_bfs(vi v,ll n,vi sources,ll m,vi &ans)
{
    queue<ll> Q;
    ll i;
    vi dis(N,-1);
    bool visited[N+1];
    for(auto val:v)
        visited[val]=false;
    
    fo(i,m)
    {
        dis[sources[i]]=0;
        Q.push(sources[i]);
        visited[sources[i]]=true;
    }

    while(!Q.empty())
    {
        ll node=Q.front();
        Q.pop();
        for(auto val:graph[node])
        {
            if(!visited[val])
            {
                Q.push(val);
                visited[val]=true;
                dis[val]=dis[node]+1;
            }
        }
    }

    fo(i,N)
    {
        if(dis[i]!=-1 && dis[i]!=0)
            ans[i]=dis[i];
    }
        
}

void solve()
{
    ll i;
    cin>>N;
    vi v(N);
    fo(i,N)
        cin>>v[i];

    vi odd,even;
    vi ans(N,-1);
    fo(i,N)
    {
        if(i+v[i]<N)
            graph[i+v[i]].pb(i);
        if(i-v[i]>=0)
            graph[i-v[i]].pb(i);

        if(v[i]&1)
        {
            odd.pb(i);
        }
        else
        {
            even.pb(i);
        }
    }

    multi_source_bfs(even,even.size(),odd,odd.size(),ans);
    multi_source_bfs(odd,odd.size(),even,even.size(),ans);

    fo(i,N)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;




    

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