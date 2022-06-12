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

vector<ll> v[200010];

void dfs(ll node,bool visited[],vi &ans,ll dis[])
{
    visited[node]=true;

    for(auto nbr:v[node])
    {
        if(!visited[nbr])
        {
            if(dis[nbr]>dis[node])
                dfs(nbr,visited,ans,dis);    
        }
        if(dis[nbr]>dis[node])
            ans[node]=min(ans[node],ans[nbr]);
        else
            ans[node]=min(ans[node],dis[nbr]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m,i;
        cin>>n>>m;
        for(i=0;i<=n;i++)
        {
            v[i].clear();
        }
        bool vis[n+1]={false};
        fo(i,m)
        {
            ll x,y;
            cin>>x>>y;
            v[x].pb(y);
        }
        ll dis[n+1]={0};
        
        queue<ll> Q;
        Q.push(1);
        vis[1]=true;
        while(!Q.empty())
        {
            ll node=Q.front();
            Q.pop();

            for(auto nbr:v[node])
            {
                if(!vis[nbr])
                {
                    vis[nbr]=true;
                    dis[nbr]=1+dis[node];
                    Q.push(nbr);
                }
            }
        }
        vi ans(n+1);

        for(i=1;i<=n;i++)
        {
            vis[i]=false;
            ans[i]=dis[i];
            // for(auto nbr:v[i])
            //     ans[i]=min(ans[i],ans[nbr]);
        }

        dfs(1,vis,ans,dis);

        for(i=1;i<=n;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        



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