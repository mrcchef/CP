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
#define yy cout<<"YES"<<endl
#define nn cout<<"NO"<<endl
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef unsigned long long ull;
typedef long double lld;
const ll mod = 1e9+7;

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



bool rec(int i,int j,map<pair<int,int>,int> &m1,map<pair<int,int>,pair<int,int>> &m2,vector<vector<int>> &visited,ll n,ll m){
    
    if(visited[i][j]==1)
        return false;
    
    visited[i][j]=1;
    
    if(i==n && m==j)
        return true;

    pair<int,int> p=m2[{i,j}];

    ll ni,nj;

    if(p.first!=0 && p.second!=0)
    {
        ni=p.first;
        nj=p.second;
        return rec(ni,nj,m1,m2,visited,n,m);
    }

    ni=i;
    nj=j+1;

    if(ni>=1 && nj>=1 && ni<=n && nj<=m && m1[{ni,nj}]==0)
    {
        return rec(ni,nj,m1,m2,visited,n,m);
    }

    ni=i+1;
    nj=j;

    if(ni>=1 && nj>=1 && ni<=n && nj<=m && m1[{ni,nj}]==0)
    {
        return rec(ni,nj,m1,m2,visited,n,m);
    }

    return false;
}

bool labyrinthEscape3(int n,int m,vector<vector<int>> obstacles,vector<vector<int>> teleport)
{
    map<pair<int,int>,int> m1;
    map<pair<int,int>,pair<int,int>> m2;
    int x=obstacles.size();
    int y=teleport.size();
    for(int i=0;i<x;i++){
        pair<int,int> temp = {obstacles[i][0]+1,obstacles[i][1]+1};
        m1[temp]=1;
    }
    for(int i=0;i<y;i++){
        pair<int,int> temp1 = {teleport[i][0]+1,teleport[i][1]+1},temp2 = {teleport[i][2]+1,teleport[i][3]+1};
        m2[temp1]=temp2;
    }

    vector<vector<int>> visited(n+1,vector<int>(m+1,0));

    return rec(1,1,m1,m2,visited,n,m);
}
        
int main()
{
    fastio
    #ifdef ONLINE_JUDGE
         freopen("Error.txt", "w", stderr);
    #endif
    {
        int n,m;
        cin>>n>>m;
        int x,y;
        cin>>x>>y;
        vector<vector<int>> obstacles;
        vector<vector<int>> teleport;
        ll i;
        fo(i,x){
            vector<int> v(2);
            fo(j,2){
                cin>>v[j];
            }
            obstacles.push_back(v);
        }
        fo(i,y){
            vector<int> v(4);
            fo(j,4){
                cin>>v[j];
            }
            teleport.push_back(v);
        }
        cout<<labyrinthEscape3(n,m,obstacles,teleport);
    }
}