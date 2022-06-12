#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0) ; cout.tie(0);
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<=n;i++)
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
const ll mod = 1e9+7;
#define popcount(x) __builtin_popcount(x)
#define all(x) x.begin(),x.end()
#define mem(a,v) memset(a,v,sizeof(a))

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

ll n,m;
vector<string> vs(55);
ll visited[55][55];

bool dfs(ll i,ll j,ll len,ll pi,ll pj)
{
    if(i<0 || i>=n || j<0 || j>=m)
        return false;

    visited[i][j]=1;   
    // cout<<i<<" "<<j<<endl; 

    bool check=false;

    for(ll x=0;x<4;x++)
    {
            ll ni,nj;
            ni=i+dx[x];
            nj=j+dy[x];
            if(ni<0 || ni>=n || nj<0 || nj>=m || vs[i][j]!=vs[ni][nj])
                continue;
            
            if(ni==pi && nj==pj)
                continue;

            if(visited[ni][nj] && len>=4)
            {
                // cout<<"root "<<i<<" "<<j<<endl;
                // cout<<"spe "<<ni<<" "<<nj<<endl;
                // cout<<"spep "<<pi<<" "<<pj<<endl;
                return true;

            }
            
            if(visited[ni][nj])
                continue;
            

            check|=dfs(ni,nj,len+1,i,j);
    }

    return check;

}

void solve()
{
    ll i,j;
    cin>>n>>m;
    fo(i,n)
    {
        cin>>vs[i];
    }


    bool ans=false;
    // ll flag=0;
    fo(i,n)
    {
        fo(j,m)
        {
            mem(visited,0);
            ans|=dfs(i,j,1,-1,-1);
            // if(ans==true && flag==0)
            // {
            //     cout<<vs[i][j]<<" "<<i<<" "<<j<<endl;
            //     flag=1;
            // }
        }
    }

    if(ans)
        cout<<"Yes";
    else
        cout<<"No";
    cout<<endl;

}

int main()
{
    fastio
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
        return fxp(m_m(a,a,m),b/2,m);
    return m_m(fxp(a,b-1,m),a,m);
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