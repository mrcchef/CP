//LinkedIn:https://www.linkedin.com/in/abhijeettamrakar/
//GitHub:https://github.com/mrcchef/
#include <bits/stdc++.h>

// policy based data structure 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 
// find_by_order : finding ith element, order_of_key : number of element smaller than key

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

bool checkBound(int i,int j,int n,int m)
    {
        return (i>=0 && i<n && j>=0 && j<m);
    }
    
    int dfs(int i,int j,int x,int y,int n,vector<vector<int>> &grid,vector<vector<vector<vector<int>>>> &dp)
    {    
        int ch=0;
         // cout<<"i:"<<i<<" j:"<<j<<" x:"<<x<<" y:"<<y<<endl;
        // printGrid(grid);
        if(i==x && j==y)
            ch+=grid[i][j];
        else
            ch+=grid[i][j]+grid[x][y];
        
        
        // cout<<"cherries:"<<ch<<endl;
        if(i==n-1 && j==n-1)
        {
            return dp[i][j][x][y]=ch;
        }
        
        // if(dp[i][j][x][y]!=-1)
        //     return dp[i][j][x][y];
        
        int prev1=grid[i][j];
        int prev2=grid[x][y];
        
        grid[i][j]=grid[x][y]=0;
        
        vector<int> mx1={1,0};
        vector<int> my1={0,1};
        
        vector<int> mx2={-1,0};
        vector<int> my2={0,-1};
        
        int cnt=-1e8;
        
        for(int p=0;p<2;p++)
        {
            int ni,nj;
            ni=i+mx1[p];
            nj=j+my1[p];
            
            if(!checkBound(ni,nj,n,n) || grid[ni][nj]==-1)            
                continue;
                
            for(int q=0;q<2;q++)
            {
                int nx,ny;
                nx=x+mx2[q];
                ny=y+my2[q];
                
                if(!checkBound(nx,ny,n,n) || grid[nx][ny]==-1)
                    continue;
                
                dfs(ni,nj,nx,ny,n,grid,dp);
                
                cnt=max(cnt,dp[ni][nj][nx][ny]);
            }
        }
        
        dp[i][j][x][y]=ch+cnt;
        
        grid[i][j]=prev1;
        grid[x][y]=prev2;
    
        return dp[i][j][x][y];
    }
    
    void printGrid(vector<vector<int>>& grid)
    {
        int n=grid.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<grid[i][j]<<" ";
            cout<<endl;
        }
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        
        vector<vector<vector<vector<int>>>> dp(n,vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,-1))));
    
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //         cout<<grid[i][j]<<" ";
        //     cout<<endl;
        // }
        
        int val=dfs(0,0,n-1,n-1,n,grid,dp);
    
        cout<<val<<endl;
        
        if(dp[n-1][n-1][0][0]==-1)
            return 0;
        
        return dp[0][0][n-1][n-1];
        
    }

void solve()
{
    vector<vector<int>> grid={{1,1,1,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,0,0,1},{1,0,0,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,1,1,1}};
    debug(cherryPickup(grid));

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