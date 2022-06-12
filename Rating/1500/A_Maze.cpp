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

void solve()
{
    ll n,m,k,i,j;
    cin>>n>>m>>k;
    vector<string> vs(n);
    fo(i,n)
        cin>>vs[i];
    
    queue<pii> q;

    ll visited[n][m];
    mem(visited,0);
    ll tt=0;
    fo(i,n)
    {
        fo(j,m)
        {
            if(vs[i][j]=='.')
            {
                tt++;
                if(tt==1)
                {
                    q.push({i,j});
                    visited[i][j]=1;
                }
            }
        }
    }

    ll cnt=0;
    while(cnt<tt-k)
    {
        pii p=q.front();
        vs[p.first][p.second]='X';
        q.pop();
        fo(i,4)
        {
            ll x=p.first+dx[i];
            ll y=p.second+dy[i];
            if(x<0||y<0||x>=n||y>=m)
                continue;
            if(!visited[x][y] && vs[x][y]=='.')
            {
                visited[x][y]=1;
                q.push({x,y});
            }
        }
        cnt++;
    }

    fo(i,n)
    {
        fo(j,m)
        {
            if(vs[i][j]=='X')
                cout<<'.';
            else if(vs[i][j]=='.')
                cout<<'X';
            else
                cout<<'#';
        }
        cout<<endl;

    }

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