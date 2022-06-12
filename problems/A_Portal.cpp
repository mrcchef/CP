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
#define ll int
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
const ll inf=1e9;
#define popcount(x) __builtin_popcount(x)
#define all(x) x.begin(),x.end()
#define mem(a,v) memset(a,v,sizeof(a))
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))

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

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

void swap(ll &a,ll &b);
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
ll msum(ll a,ll b,ll m);
ll msub(ll a,ll b,ll m);
ll mpro(ll a,ll b,ll m);

ll oper0(ll x1,ll y1,ll x2,ll y2,vector<vi> &dp)
{
    return dp[x2][y2]-dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1];
}

ll oper1(ll x1,ll y1,ll x2,ll y2,vector<vi> &dp)
{
    ll total=(x2-x1+1)*(y2-y1+1);
    return total-oper0(x1,y1,x2,y2,dp);
}


void solve()
{
    ll n,m;
    cin>>n>>m;
    ll i,j;

    vector<string> vs(n);

    fo(i,n)
        cin>>vs[i];

    vector<vi> dp(n+1,vi(m+1,0));

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            ll zi=i-1,zj=j-1;
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+(vs[zi][zj]=='1');
        }
    }

    ll ans=inf;
    // can also refer: https://www.youtube.com/watch?v=OVmqovSLW1s 

    // optimization from O(n^2m^2) to O(n*m^2)
    // so, we will first take two variable 'l' and 'r' which simply defines the 
    // boundary of my current submatrix
    // now we have a free end i.e. row 
    // ans: will store the minimum operation required to create a passage
    // given a width 'l' and 'r'
    // we can have two variables 
    // prevMin : for the optimal passage, the minimum number of operations required to 
    // such that it does not have the bottom row of blocked blocks  
    // till the prev row, for the optimal strucutre of grid looks like:
    // eg: 0101 
    //     1111
    //     1001
    //     1001
    //     1001
    //     0111 
    // so for the next row, this will store the minimum number of operations required for the 
    // below structure
    // eg: 0101 
    //     1111
    //     1001
    //     1001
    //     1001
    //     1001 

    // such that we can use that score for the current row by converting the current row into 
    // all 1's i.e. creating the current row as the bottom limit

    // all the submatrix will be covered such that the current row is the bottom limit
    // except the submatrix which starts from (curRow-4,l) to (curRow,r) as in the prev interation
    // it would be not satisfy the minimum constraints of a valid submatrix

    // so we have two cases
    // one simply add the lastRowCost to prevMin and 
    // second find out the cost for the smallest valid possible matrix
    // and take the minimium out of it!! 

    // and then again we need to make prevMin back in the form such that we can utilize 
    // it for the further rows

    for(ll l=1;l<=m;l++)
    {
        for(ll r=l+3;r<=m;r++)
        {
            ll curMin,prevMin;
            curMin=prevMin=inf;
        
            for(ll row=5;row<=n;row++)
            {
                ll lastRow=oper1(row,l+1,row,r-1,dp);
                
                ll leftCol=oper1(row-3,l,row-1,l,dp);
                ll rightCol=oper1(row-3,r,row-1,r,dp);
                ll topRow=oper1(row-4,l+1,row-4,r-1,dp);
                ll centre=oper0(row-3,l+1,row-1,r-1,dp);
                
                ll last4Cost=leftCol+lastRow+rightCol+topRow+centre;

                curMin=min(prevMin+lastRow,last4Cost);
                
                ans=min(ans,curMin);

                prevMin=curMin;
                prevMin-=lastRow;
                ll leftBottomCorner=oper1(row,l,row,l,dp);
                ll rightBottomCorner=oper1(row,r,row,r,dp);
                ll operReqToChangeOnesToZero=oper0(row,l+1,row,r-1,dp);
                prevMin+=leftBottomCorner+rightBottomCorner+operReqToChangeOnesToZero;
            }
        }
    }

    cout<<ans<<endl;


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