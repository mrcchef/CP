
//LinkedIn:https://www.linkedin.com/in/abhijeettamrakar/
//GitHub:https://github.com/mrcchef/

#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0) ; cout.tie(0);
 
#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define vi vector<ll>
#define endl "\n"

const ll inf=1e18;

const ll N=1e3+5;

vector<vector<pii>> g(N);
vi dist(N,inf);
vi fuel(N,0);

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

            ll newFuelRemaing=fuelRemaining-w;

            if(dist[v]>distanceTravelled+w && newFuelRemaing>=0)
            {
                dist[v]=distanceTravelled+w;
                fuel[v]=newFuelRemaing;
                if(isPetrolStation[v])
                    fuel[v]=c;
                pq.push({dist[v],v,fuel[v]});
            }
            else if(dist[v]==distanceTravelled+w && fuel[v]<newFuelRemaing)
            {
                fuel[v]=newFuelRemaing;
                pq.push({dist[v],v,fuel[v]});
            }
            else if(dist[v]<distanceTravelled+w && fuel[v]<newFuelRemaing)
                pq.push({distanceTravelled+w,v,newFuelRemaing});
        }
    }
}

void solve()
{
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
    solve();
 return 0;
}