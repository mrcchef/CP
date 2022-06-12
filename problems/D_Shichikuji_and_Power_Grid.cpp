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

void solve()
{
    ll n,i;
    cin>>n;

    vi xPos(n),yPos(n);
    fo(i,n)
        cin>>xPos[i]>>yPos[i];
    
    vi costToBuildPowerPlant(n);
    vi wireCityCost(n);
    fo(i,n)
        cin>>costToBuildPowerPlant[i];

    fo(i,n)
        cin>>wireCityCost[i];
    
    vi done(n,0);
    vi parent(n,-1);

    vi powerPlant;
    vector<pii> connections;

    ll totalCost=0;

    // idea is simple
    // it is always optimal to have power plant in a city that require min. cost
    // once, we have find out the optimal power plant then we will explore other
    // cities such that building power plant in those cities are expensive than 
    // connecting them with the optimal city
    // this process we will follow until we provide electricity in all the cities 
    while(true)
    {   
        ll cost=inf;
        ll pos=-1;

        fo(i,n)
        {
            if(done[i])
                continue;
            
            if(cost>costToBuildPowerPlant[i])
            {
                cost=costToBuildPowerPlant[i];
                pos=i;
            }
        }

        if(pos==-1) // all cities are powered with electricity
            break;
        
        //pos is the city with optimal cost

        totalCost+=cost;
        done[pos]=1;

        // if it is not connected by anyother power plant then it is a power plant
        if(parent[pos]==-1)
            powerPlant.pb(pos);
        else // if it is connected by some power plant then it is a connection 
            connections.pb({parent[pos],pos}); 

        fo(i,n)
        {
            if(done[i])
                continue;
            
            ll wireCost=wireCityCost[i]+wireCityCost[pos];
            ll dist=abs(xPos[pos]-xPos[i])+abs(yPos[pos]-yPos[i]);

            ll tcost=wireCost*dist;
            // minimising the cost if possible
            if(tcost<costToBuildPowerPlant[i])
            {
                costToBuildPowerPlant[i]=tcost;
                parent[i]=pos;
            }
        }

        
    }

    cout<<totalCost<<endl;
    cout<<powerPlant.size()<<endl;
    for(auto &val:powerPlant)
        cout<<val+1<<" ";
    cout<<endl;
    cout<<connections.size()<<endl;

    for(auto &edge:connections)
    {
        cout<<edge.first+1<<" "<<edge.second+1<<endl;
    }

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