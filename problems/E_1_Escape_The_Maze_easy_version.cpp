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
#define ll int
#define vi vector<ll>
#define endl "\n"
#define pb push_back
const ll inf=1e9;

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

const ll N=2e5+5;
vector<vi> g(N);

void init()
{
    for(int i=0;i<N;i++)
        g[i].clear();   
}

void solve()
{
    ll n,k,i;
    cin>>n>>k;

    queue<int> q;

    bool isPossible=false;

    vi arr(k);
    vi color(n+1,-1);
    fo(i,k)
        cin>>arr[i];

    fo(i,k)
    {
        q.push(arr[i]);
        color[arr[i]]=0;
    }

    q.push(1);
    color[1]=1;

    fo(i,n-1)
    {
        ll x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }

    while(!q.empty())
    {
        int ele=q.front();
        q.pop();

        for(auto &nbr:g[ele])
        {
            if(color[nbr]==-1)
            {
                color[nbr]=color[ele];
                q.push(nbr);
            }
        }
    }

    for(i=2;i<=n;i++)
    {
        if(g[i].size()==1 && color[i]==1)
        {
            cout<<"YES"<<endl;
            return;
        }

    }

    cout<<"NO"<<endl;

}

int main()
{
    fastio
    #ifdef ONLINE_JUDGE
        // freopen("input.txt", "r", stdin); 
        // freopen("output.txt", "w", stdout);
        freopen("error.txt","w",stderr);
    #endif
    int t=1;
    cin>>t;
    while(t--)
    {
        init();
        solve();   
    }
 return 0;
}
