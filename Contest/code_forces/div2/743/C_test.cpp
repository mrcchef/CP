#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
const ll mod = 1e9 + 7,inf = 1e18;
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
    #define debug(x);
#endif

// debugging code
// ---------------------------------------------------------------------------------------------------------------------------------
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
// void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
// void _print(ull t) {cerr << t;}

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
//


void setIO()
{
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
int main()
{
    // setIO();
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        
        vvi adj(n + 1),radj(n + 1);
        vi in(n + 1);
        vb vis(n + 1);
        vi topo;
 
        for (int i = 1;i<=n;i++){
            int k;
            cin>>k;
            while (k--){
                int x;
                cin>>x;
                adj[x].pb(i);
                radj[i].pb(x);
                in[i]++;
            }
        }
 
        queue<int>q;
 
        for (int i = 1;i<=n;i++){
            if (in[i] == 0)
                q.push(i);
        }
 
        while (!q.empty()){
            int u = q.front();
            q.pop();
            topo.pb(u);
            vis[u] = 1;
            for (int v:adj[u]){
                if (--in[v] == 0)
                    q.push(v);
            }
        }
 
        bool is = true;
        for (int i = 1;i<=n;i++){
            if (!vis[i])is = false;
        }
 
        if (!is){cout<<-1<<'\n';continue;}
 
        vi dp(n + 1,1);
        int ans = 0;
        for (int u:topo){
            debug(u);
            for (int v:radj[u]){
                debug(v);
                if (v > u)dp[u] = max(dp[u],dp[v] + 1);
                else dp[u] = max(dp[u],dp[v]);
            }
            debug(dp);
            ans = max(ans,dp[u]);
        }
        cout<<ans<<endl;
    }
    return 0;
}