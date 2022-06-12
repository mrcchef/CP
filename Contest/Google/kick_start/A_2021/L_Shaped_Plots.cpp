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

ll tc=1;

const ll N=1002;
const ll M=1002;

ll vers[N][M];
ll versd[N][M];
ll hors[N][M];
ll n,m;

ll cal(ll i,ll j,ll offset=0)
{
    ll tcnt=0,val=0;
    if(hors[i][j]>1)
    {
        ll mx=max(hors[i][j],vers[i][j]);
        ll mn=min(hors[i][j],vers[i][j]);

        val+=min(mx/2,mn)-1;
        val+=min(mn/2,mx)-1;
        // if(hors[i][j]>vers[i][j])
        // {
        //     val=min(2*vers[i][j],hors[i][j]);
        //     val=(val-2)/2;
        // }
        // else if(hors[i][j]<vers[i][j])
        // {
        //     val=min(2*hors[i][j],vers[i][j]);
        //     val=(val-2)/2;
        // }
        // else
        // {
        //     val=(hors[i][j]-2)/2+1;
        // }
    }
    tcnt+=val;
    ll k=j;
    for(k;k<=m;k++)
    {
        if(hors[i][k]==0)
            break;
    }
    k--;
    val=0;
    ll rtv=hors[i][k]-hors[i][j]+1;
    if(rtv>1)
    {
        ll mx=max(rtv,vers[i][j]);
        ll mn=min(rtv,vers[i][j]);

        val+=min(mx/2,mn)-1;
        val+=min(mn/2,mx)-1;
    }
    tcnt+=val;
    return tcnt;
}

ll cal2(ll i,ll j)
{
    ll tcnt=0,val=0;
    if(hors[i][j]>1)
    {
        ll mx=max(hors[i][j],versd[i][j]);
        ll mn=min(hors[i][j],versd[i][j]);

        val+=min(mx/2,mn)-1;
        val+=min(mn/2,mx)-1;
    }
    tcnt+=val;
    ll k=j;
    for(k;k<=m;k++)
    {
        if(hors[i][k]==0)
            break;
    }
    k--;
  
    val=0;
    ll rtv=hors[i][k]-hors[i][j]+1;
  
    if(rtv>1)
    {
        
        ll mx=max(rtv,versd[i][j]);
        ll mn=min(rtv,versd[i][j]);

        val+=min(mx/2,mn)-1;
        val+=min(mn/2,mx)-1;
    }
    tcnt+=val;
    return tcnt;
}

void solve()
{
    ll i,j;
    cin>>n>>m;
    ll arr[n+1][m+1];
    
    fo(i,n)
        fo(j,m)
            cin>>arr[i+1][j+1];
    
    mem(vers,0);
    mem(hors,0);

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            if(arr[i][j]==0)
                hors[i][j]=0;
            else
                hors[i][j]=hors[i][j-1]+1;
    }

    for(j=1;j<=m;j++)
    {
        for(i=1;i<=n;i++)
            if(arr[i][j]==0)
                vers[i][j]=0;
            else
                vers[i][j]=vers[i-1][j]+1;
    }

    for(j=1;j<=m;j++)
    {
        for(i=n;i>=1;i--)
            if(arr[i][j]==0)
                versd[i][j]=0;
            else
            {
                if(i==n)
                    versd[i][j]=1;
                else
                    versd[i][j]=versd[i+1][j]+1;
            }
    }

    ll cnt=0;
    for(j=1;j<=m;j++)
    {
        for(i=1;i<=n;i++)
        {
            if(vers[i][j]<=1)
                continue;
            ll val1=cal(i,j);
            cnt+=val1;
        }
    }

    for(j=1;j<=m;j++)
    {
        for(i=n;i>=1;i--)
        {
            if(versd[i][j]<=1)
                continue;
            ll val2=cal2(i,j);
            cnt+=val2;
        }
    }

    cout<<"Case #"<<tc<<": "<<cnt<<endl;
}

int main()
{
    fastio
    int t;
    cin>>t;
    while(tc<=t)
    {
        solve();
        tc++;   
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