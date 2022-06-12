
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
#define printclock   cerr<<"Time : "<<1000*(cold)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";

long long readInt(long long l,long long r,char endd){
	long long x=0;
	int cnt=0;
	int fi=-1;
	bool is_neg=false;
	while(true){
		char g=getchar();
        // cout<<"g:"<<g<<endl;
		if(g=='-'){
			assert(fi==-1);
			is_neg=true;
			continue;
		}
		if('0'<=g && g<='9'){
			x*=10;
			x+=g-'0';
			if(cnt==0){
				fi=g-'0';
			}
			cnt++;
			assert(fi!=0 || cnt==1);
			assert(fi!=0 || is_neg==false);
			
			assert(!(cnt>19 || ( cnt==19 && fi>1) ));
		} else if(g==endd){
			if(is_neg){
				x= -x;
			}
          //  cout<<x<<endl;
			assert(l<=x && x<=r);
           
			return x;
		} else {
			assert(false);
		}
	}
}
string readString(int l,int r,char endd){
	string ret="";
	int cnt=0;
	while(true){
		char g=getchar();
		assert(g!=-1);
		if(g==endd){
			break;
		}
		cnt++;
		ret+=g;
	}
	assert(l<=cnt && cnt<=r);
	return ret;
}
long long readIntSp(long long l,long long r){
	return readInt(l,r,' ');
}
long long readIntLn(long long l,long long r){
	return readInt(l,r,'\n');
}
string readStringLn(int l,int r){
	return readString(l,r,'\n');
}
string readStringSp(int l,int r){
	return readString(l,r,' ');
}

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
            else if(dist[v]<distanceTravelled+w && fuel[v]<fuelRemaining-w)
                pq.push({distanceTravelled+w,v,fuelRemaining-w});
        }
    }
}

void solve()
{

    // freopen("TC.txt","r",stdin);
    // freopen("OP.txt","w",stdout);
    ll n,m,i,k,c,p;
    // cin>>n>>m>>k>>c>>p;
    n = readIntSp(1 , 1e3);
    m = readIntSp(1 , 1e4);
    k = readIntSp(1 , n);
    c = readIntSp(1 , 1e3);
    p = readIntLn(0 , n);
    vi participants(k);
    vi isPetrolStation(n+1,0);

    for(i=0;i<m;i++)
    {
        ll x,y,w;
        // cin>>x>>y>>w;
         x = readIntSp(1 , n);
        y = readIntSp(1 , n);
        assert(x!=y);
        w = readIntLn(1 , 1e5);
        g[x].pb({y,w});
        g[y].pb({x,w});
    }

    for(i=0;i<k;i++)
    {
        ll x;
		if(i==k-1)
			x=readIntLn(1,n);
		else
        	x = readIntSp(1 , n);
        participants[i]=x;
    }
    
    for(i=0;i<p;i++)
    {
        ll x;
		if(i==p-1)
			x=readIntLn(1,n);
		else
        	x = readIntSp(1 , n);
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
    while(t--)
    {
        solve();   
    }
    // printclock;
 return 0;
}