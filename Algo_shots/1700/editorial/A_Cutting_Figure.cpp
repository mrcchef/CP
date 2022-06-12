#include <bits/stdc++.h>
using namespace std;
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

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}



ll n,m,i,j;
ll vis[60][60];
vector<string> vs;
ll check=0;

void dfs(ll i,ll j)
{
    vis[i][j]=1;
    // cout<<i<<" "<<j<<endl;
    check++;

                    if(i+1<n && vs[i+1][j]=='#' && vis[i+1][j]==0)
                    {
                        dfs(i+1,j);
                    }
                    if(j+1<m && vs[i][j+1]=='#' && vis[i][j+1]==0)
                    {
                        dfs(i,j+1);
                    }
                    if(i-1>=0 && vs[i-1][j]=='#' && vis[i-1][j]==0)
                    {
                        dfs(i-1,j);
                    }
                    if(j-1>=0 && vs[i][j-1]=='#' && vis[i][j-1]==0)
                    {
                        dfs(i,j-1);
                    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        cin>>n>>m;
        fo(i,n)
        {
            string s;
            cin>>s;
            vs.pb(s);
        }
            // cin>>vs[i];
        // memset(vis,0,sizeof(vis));

        ll ans=2;
        ll cnt=0;
        fo(i,n)
        {
            fo(j,m)
            {
                if(vs[i][j]=='#')
                    cnt++;
            }
        }

        if(cnt<=2)
        {
            cout<<-1<<endl;
            return 0;
        }

        // cout<<cnt<<endl;

        fo(i,n)
        {
            fo(j,m)
            {
                if(vs[i][j]=='#')
                {
                    vs[i][j]='.';
                    check=0;
                    memset(vis,0,sizeof(vis));
                    if(i+1<n && vs[i+1][j]=='#')
                    {
                        dfs(i+1,j);
                    }
                    else if(j+1<m && vs[i][j+1]=='#')
                    {
                        dfs(i,j+1);
                    }
                    else if(i-1>=0 && vs[i-1][j]=='#')
                    {
                        dfs(i-1,j);
                    }
                    else if(j-1>=0 && vs[i][j-1]=='#')
                    {
                        dfs(i,j-1);
                    }
                    // for(ll k=0;k<n;k++)
                    // {
                    //     for(ll l=0;l<m;l++)
                    //         cout<<vis[k][l]<<" ";
                    //     cout<<endl;
                    // }
                    // cout<<check<<endl;
                    if(cnt-1!=check)
                    {
                        ans=1;
                        break;
                    }
                    vs[i][j]='#';
                }
                
            }
            if(ans==1)
                break;
        }

        cout<<ans<<endl;


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