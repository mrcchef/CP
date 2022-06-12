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
 
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<=n;i++)
#define ll long long
#define ull unsigned long long
#define lld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define endl "\n"
const ll MOD = 1e9+7;
const ll MOD1= 998244353;
const ll inf=1e18;
#define popcount(x) __builtin_popcount(x)
#define all(x) x.begin(),x.end()
#define mem(a,v) memset(a,v,sizeof(a))
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))

// debugging code
// ---------------------------------------------------------------------------------------------------------------------------------
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// ---------------------------------------------------------------------------------------------------------------------------------

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

void swap(ll &a,ll &b);
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
ll msum(ll a,ll b,ll m);
ll msub(ll a,ll b,ll m);
ll mpro(ll a,ll b,ll m);

const ll N=1e5+5;

vector<vector<pii>> incg(N),decg(N);

vi incp(N),decp(N);
vi dist;

void init()
{
    ll i;
    fo(i,N)
    {
        incg[i].clear();
        decg[i].clear();
        incp[i]=decp[i]=0;
    }

    dist.assign(N,inf);
}

void solve()
{
    init();
    ll n,m,i;
    cin>>n>>m;

    fo(i,m)
    {
        ll x,y,w;
        cin>>x>>y>>w;
        incg[x].pb({w,y});
        incg[y].pb({w,x});

        decg[x].pb({w,y});
        decg[y].pb({w,x});
    }  

    ll src,des;
    cin>>src>>des;  

    Fo(i,1,n)
    {
        sort(all(incg[i]));
        sort(all(decg[i]),greater<pii>());
    }

    priority_queue<vi,vector<vi>,greater<vi>> pq;
    pq.push({0,src,0,0});
    // wie,node,edge,mode

    // mode=0 inc , mode=1 dec

    dist[src]=0;

    while(!pq.empty())
    {
        vi p=pq.top();
        pq.pop();

        ll wie=p[0];
        ll u=p[1];
        ll pastEdgeWie=p[2];
        ll mode=p[3];
        
        // b/c what we want is if the pastedge is increasing
        // then the next edge that we should take should be descreaing and vice-versa.
        // Let's say we reach a node u with the optimal distance to read u with pastedge increasing
        // but to continue we need to be pick decreasing nbr edge but we don't have that
        // but we also reach u but not with optimal distance but with decreasing pastedge 
        // then we can use this not optimal path to continue to reach destination 
        // that why we allow node with not optimal distace 

        // if(dist[u]<wie) 
        //     continue;
        
        // Time complecity is O(2*mlogn) 
        // This time complecity is achived by not using once used edge again in a particular mode
        // which means each edge is can be visited at most twice (consedering both mode)
        // and to achive that we have incp[] and decp[] which stores the position of 
        // nbrs in the edge list of node from which they have to start visiting

        if(mode==1)
        {
            int j;
            for(j=incp[u];j<incg[u].size();j++)
            {
                ll w=incg[u][j].first;
                ll v=incg[u][j].second;
            
                if(pastEdgeWie>w)
                {
                    if(dist[v]>wie+w)
                    {
                        dist[v]=wie+w;
                    }
                    pq.push({wie+w,v,w,0});
                }
                else
                    break;
            }

            incp[u]=j;
        }
        else
        {
            int j;
            for(j=decp[u];j<decg[u].size();j++)
            {
                ll w=decg[u][j].first;
                ll v=decg[u][j].second;
                if(pastEdgeWie<w)
                {
                    if(dist[v]>wie+w)
                    {
                        dist[v]=wie+w;
                    }
                    pq.push({wie+w,v,w,1});
                }
                else
                    break;
            }

            decp[u]=j;
        }
    }
    ll ans=dist[des];
    if(ans==inf)
        cout<<"No Solution";
    else
        cout<<ans;
    cout<<endl;


}

int main()
{
    fastio
    #ifdef ONLINE_JUDGE
         freopen("Error.txt", "w", stderr);
    #endif
    int t=1;
    cin>>t;
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
        return fxp((a*a)%m,b/2,m);
    return (fxp(a,b-1,m)*a)%m;
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
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}
ll msum(ll a,ll b,ll m) { return ((a%m+b%m)+m)%m; }
ll msub(ll a,ll b,ll m) { return ((a%m-b%m)+m)%m; }
ll mpro(ll a,ll b,ll m) { return (((a%m)*(b%m)+m))%m; }