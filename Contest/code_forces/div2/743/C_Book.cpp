// //LinkedIn:https://www.linkedin.com/in/abhijeettamrakar/
// //GitHub:https://github.com/mrcchef/
// #include <bits/stdc++.h>
// using namespace std;
// #define fastio ios_base::sync_with_stdio(false); cin.tie(0) ; cout.tie(0);

// #ifndef ONLINE_JUDGE
//     #define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
// #else
//     #define debug(x);
// #endif
 
// #define fo(i,n) for(i=0;i<n;i++)
// #define Fo(i,k,n) for(i=k;i<=n;i++)
// #define ll long long
// #define ull unsigned long long
// #define lld long double
// #define ff first
// #define ss second
// #define pb push_back
// #define mp make_pair
// #define mii map<ll,ll>
// #define pii pair<ll,ll>
// #define vi vector<ll>
// #define endl "\n"
// const ll MOD = 1e9+7;
// const ll MOD1= 998244353;
// const ll inf=1e18;
// #define popcount(x) __builtin_popcount(x)
// #define all(x) x.begin(),x.end()
// #define mem(a,v) memset(a,v,sizeof(a))
// #define Max(x,y,z) max(x,max(y,z))
// #define Min(x,y,z) min(x,min(y,z))

// // debugging code
// // ---------------------------------------------------------------------------------------------------------------------------------
// void _print(ll t) {cerr << t;}
// void _print(int t) {cerr << t;}
// void _print(string t) {cerr << t;}
// void _print(char t) {cerr << t;}
// void _print(lld t) {cerr << t;}
// void _print(double t) {cerr << t;}
// void _print(ull t) {cerr << t;}

// template <class T, class V> void _print(pair <T, V> p);
// template <class T> void _print(vector <T> v);
// template <class T> void _print(set <T> v);
// template <class T, class V> void _print(map <T, V> v);
// template <class T> void _print(multiset <T> v);
// template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
// template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// // ---------------------------------------------------------------------------------------------------------------------------------

// ll dx[]={-1,0,1,0};
// ll dy[]={0,-1,0,1};

// void swap(ll &a,ll &b);
// ll m_m(ll a,ll b,ll m);
// ll fxp(ll a,ll b,ll m);
// ll msum(ll a,ll b,ll m);
// ll msub(ll a,ll b,ll m);
// ll mpro(ll a,ll b,ll m);


// ll dfs(ll node,ll par,mii &hm,vector<vi> &g,vi &vis)
// {
//     ll sm=0;
//     vis[node]=1;
//     debug(node);
//     for(auto nbr:g[node])
//     {
//         if(hm.find(nbr)!=hm.end())
//             continue;

//         if(vis[nbr]==1)
//         {
//             return -inf;
//         }
        
//         if(nbr>node)
//             sm++;
        
//         sm+=dfs(nbr,node,hm,g,vis);
//     }

//     hm[node]=1;

//     return sm;
// }


// void solve()
// {
//     ll n,i;
//     cin>>n;

//     vector<vi> g(n+1);

//     mii hm;
//     ll flag=0;
//     fo(i,n)
//     {
//         ll sz;
//         cin>>sz;
//         ll req=sz;
//         ll j;
//         if(sz>0)
//             flag=1;
//         fo(j,sz)
//         {
//             ll x;
//             cin>>x;
//             g[i+1].pb(x);
//             debug(x);
//             debug(hm);
//             if(hm.find(x)!=hm.end())
//                 req--;
//         }

//         if(req==0)
//         {
//             hm[i+1]=1;
//         }
//     }   
//     ll ans=1;

//     debug(g);
//     debug(hm);

//     while(hm.size()<n)
//     {
//         ans++;
//         Fo(i,1,n)
//         {
//             if(hm.find(i)==hm.end())
//             {
//                 vi vis(n+1,0);
//                 ll tans=dfs(i,0,hm,g,vis);
//                 debug(mp(i,tans));
//                 if(tans<0)
//                 {
//                     cout<<-1<<endl;
//                     return;
//                 }
//                 ans+=tans;
//             }
//         }
//     }

//     cout<<ans<<endl;
// }

// int main()
// {
//     fastio
//     #ifdef ONLINE_JUDGE
//          freopen("Error.txt", "w", stderr);
//     #endif
//     int t=1;
//     cin>>t;
//     while(t--)
//     {
//         solve();   
//     }
//  return 0;
// }

// ll fxp(ll a,ll b,ll m) {
//     if(b==0)
//         return 1;
//     if(b%2==0)
//         return fxp((a*a)%m,b/2,m);
//     return (fxp(a,b-1,m)*a)%m;
// }
// ll m_m(ll a,ll b,ll m) 
// {
//     ll res=0;
//     a=a%m;
//     while(b)
//     {
//         if(b&1)
//         {
//             res+=a; 
//             res=res%m;
//         }
//         a=(a*2)%m;
//         b=b/2;
//     }
//     return res;
// }
// void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}
// ll msum(ll a,ll b,ll m) { return ((a%m+b%m)+m)%m; }
// ll msub(ll a,ll b,ll m) { return ((a%m-b%m)+m)%m; }
// ll mpro(ll a,ll b,ll m) { return (((a%m)*(b%m)+m))%m; }


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
#define vvi vector<vi>
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

void dfs(ll node,vi& vis,vi &in,vi &topo,vvi &g)
{
    vis[node]=1;
    
    for(auto nbr:g[node])
    {
        if(in[nbr]==0)
           continue;

        in[nbr]--;

        dfs(nbr,vis,in,topo,g);        
    }

    for(auto nbr:g[node])
    {
        if(in[nbr]==0)
            topo.pb(nbr);
    }
}

void solve()
{
    ll n,i;
    cin>>n;

    vvi g(n+1),rg(n+1);
    vi in(n+1,0);

    fo(i,n)
    {
        ll sz;
        cin>>sz;
        ll j;
        fo(j,sz)
        {
            ll x;
            cin>>x;
            rg[i+1].pb(x);
            g[x].pb(i+1);
            in[i+1]++;
        }
    }
    debug(rg);
    debug(g);
    
    vi vis(n+1,0);
    queue<ll>  q;
    vi topoSort;
    
    debug(in);
    Fo(i,1,n)
    {
        if(in[i]==0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        ll ele=q.front();
        q.pop();
        vis[ele]=1;
        topoSort.pb(ele);

        for(auto child:g[ele])
        {
            if(in[child]==0)
                continue;
            
            in[child]--;
            if(in[child]==0)
            {
                q.push(child);
            }
        }
    }

    Fo(i,1,n)
    {
        if(!vis[i])
        {
            cout<<-1<<endl;
            return;
        }
    }   

    debug(topoSort);

    vi dp(n+1,1);
    ll ans=0;
    for(auto u:topoSort)
    {
        for(auto v:rg[u])
        {
            if(v>u) 
                dp[u]=max(dp[u],dp[v]+1);
            else    
                dp[u]=max(dp[u],dp[v]);
        }

        ans=max(ans,dp[u]);
    }

    cout<<ans<<endl;
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