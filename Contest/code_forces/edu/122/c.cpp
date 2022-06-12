#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<=n;i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
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
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef unsigned long long ull;
typedef long double lld;
const ll mod = 1e9+7;

// debugging code
// ---------------------------------------------------------------------------------------------------------------------------------
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
    #define debug(x);
#endif
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

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}
void sieve(ll n) { bool prime[n + 1]; memset(prime, true, sizeof(prime)); for(ll i=2;i*i<=n;i++) { if(prime[i]==true) { for(ll j=i*i;j<=n;j+=i) prime[j] = false; } } }

//use this when n>10^7 and mask array can't be made in sieve
//This gives us a vector which has all the prime factors of upto root of 10^9
vector<ll> sieve_vector(int n){ll arr[n+1]; vector<ll> vect; for(int i = 2; i<= n; i++) if (arr[i] == 0){ vect.push_back(i); for (int j = i * i; j <= n; j += i) arr[j] = 1; } return vect;}
//vector<ll> v1 = sieve(31623); //coz root of 10^9 is near to this value
    map<pair<int,int>,pair<int,int>> par; 

void bfs(vector<vector<char>> &a,int n, int m, int r, int c,vector<vector<int>>& vis){
    vector<pair<int,int>> dir {{0,-1}, {1,0}, {-1,0}, {0,1}};
    queue<pair<int,int>> q;
    q.push({r,c});
    vis[r][c]=1;
    vector<char> ds;
    while(!q.empty()){
        auto cur=q.front();
        // debug(cur)
        q.pop();
        for(auto it:dir){
            int xx=it.first+cur.first;
            int yy=it.second+cur.second;
            if(xx>=0 && yy>=0 && xx<n && yy<m && !vis[xx][yy] && (a[xx][yy]=='.' || a[xx][yy]=='B')){
                vis[xx][yy]=1;
                par[{xx,yy}]={cur.first,cur.second};
                if(a[xx][yy]=='B'){
                    return;
                }
                q.push({xx,yy});
            }
        }
    }
}

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<char>> a(n,vector<char> (m));
    int sr=-1,sc=-1,dr,dc;
    fo(i,n) {
        fo(j,m){
            cin>>a[i][j];
            if(a[i][j]=='A'){
                sr=i;
                sc=j;
            }
            if(a[i][j]=='B'){
                dr=i;
                dc=j;
            }
        }
    }
    
   
    vector<char> ds;
    vector<vector<int>> vis (n,vector<int> (m,0));
    par[{sr,sc}]={-1,-1};
    bfs(a,n,m,sr,sc,vis);
    ll x,y;
    x=dr,y=dc;
    if(!vis[dr][dc]){
        cout<<"NO"<<endl;
        return;
    }

    while(x!=-1){
        char c;
        auto it=par[{x,y}];
        // debug(it);
        if(it.first>x) c='U';
        else if(it.first<x) c='D';
        else if(it.second>y) c='L';
        else c='R';
        ds.pb(c);
        x=it.first;
        y=it.second;
    }
    ds.pop_back();
    reverse(ds.begin(),ds.end());

    
    cout<<"YES"<<endl;
    cout<<ds.size()<<endl;
    for(auto x:ds) cout<<x;
    cout<<endl;
}
        
int main()
{
    fastio
    #ifdef ONLINE_JUDGE
         freopen("Error.txt", "w", stderr);
    #endif
    {
       solve();
    }
}