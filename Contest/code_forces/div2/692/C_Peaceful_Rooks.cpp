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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m,i;
        cin>>n>>m;
        ll row[n+1]={0},col[n+1]={0};
        vector<pii> vp;
        fo(i,m)
        {
            ll x,y;
            cin>>x>>y;
            vp.pb({x,y});
            row[x]=1;
            col[y]=1;
        }   

        ll cnt=0;
        ll check2=0;
        // for(ll i=1;i<=n;i++)
        // {

        // }
        ll check[m]={0};

        for(i=0;i<m;i++)
        {
            if(vp[i].first==vp[i].second)
            {
                check[i]=1; 
                continue;
            }
        
            if(col[vp[i].first]==0)
            {
                col[vp[i].second]=0;
                col[vp[i].first]=1;
                cnt++;
                check[i]=1;
            }
            else if(row[vp[i].second]==0)
            {
                row[vp[i].first]=0;
                row[vp[i].second]=1;
                cnt++;
                check[i]=1;
            }
            
            
        }

        for(i=0;i<m;i++)
        {
            if(check[i]==1)
                continue;
            
            if(check2==0 && row[vp[i].second]==1 && col[vp[i].first]==1)
            {
                cnt+=2;
                check2=1;
            }
            else
            {
                cnt++;
            }
        }
        cout<<cnt<<endl;

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