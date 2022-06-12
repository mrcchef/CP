
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
 
#define ll long long
#define ld  long double
#define pb push_back
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define endl "\n"
#define printclock   cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";

const ll inf=1e18;

const ll N=1e3+5;

vector<vector<pii>> g(N);
vi dist;
vi fuel;

void init()
{
    ll i;
    for(i=0;i<N;i++)
        g[i].clear();
    
    dist.assign(N,inf);
    fuel.resize(N);
}

// Time complexity C*(N + ElogN*C)

void dijkstra(ll src,ll n,ll c,vi &isPetrolStation)
{
    priority_queue<vi,vector<vi>,greater<vi>> pq;
    vector<vi> visited(n+1,vi(c+1,0));

    pq.push({0,src,c}); // distanceTravelled, node, fuel left
    dist[src]=0;
    
    while(!pq.empty())
    {
        vi node=pq.top();
        pq.pop();

        ll u=node[1];
        ll distanceTravelled=node[0];
        ll fuelRemaining=node[2];
        
        if(visited[u][fuelRemaining])
            continue;
        
        visited[u][fuelRemaining]=true;

        for(auto nbr:g[u])
        {
            ll v=nbr.first;
            ll w=nbr.second;

            if(dist[v]>distanceTravelled+w && fuelRemaining>=w)
            {
                dist[v]=distanceTravelled+w;
                fuel[v]=fuelRemaining-w;
                if(isPetrolStation[v])
                    fuel[v]=c;
                pq.push({dist[v],v,fuel[v]});
            }
            else if(dist[v]==distanceTravelled+w && fuel[v]<fuelRemaining-w)
            {
                fuel[v]=fuelRemaining-w;
                pq.push({dist[v],v,fuel[v]});
            }
            else if(dist[v]<distanceTravelled+w && fuelRemaining>=w)
                pq.push({distanceTravelled+w,v,fuelRemaining-w});
        }
    }
}

void solve()
{
    // freopen("@iin.txt","r",stdin);
    // freopen("@output.txt","w",stdout);
    ll n,m,i,k,c,p;
    cin>>n>>m>>k>>c>>p;

    vi participants(k);
    vi isPetrolStation(n+1,0);

    for(i=0;i<m;i++)
    {
        ll x,y,w;
        cin>>x>>y>>w;
        g[x].pb({y,w});
        g[y].pb({x,w});
    }

    for(i=0;i<k;i++)
        cin>>participants[i];
    
    for(i=0;i<p;i++)
    {
        ll x;
        cin>>x;
        isPetrolStation[x]=1;
    }

    dijkstra(n,n,c,isPetrolStation);

    ll minDistanceNode=-1;
    ll minDistance=inf;

    for(i=0;i<k;i++)
    {
        if(minDistance>dist[participants[i]])
        {
            minDistance=dist[participants[i]];
            minDistanceNode=participants[i];
        }
    }

    cout<<minDistanceNode<<endl;
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
        init();
        solve();   
    }
    printclock
 return 0;
}