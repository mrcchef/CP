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

const ll N=2005;

vector<ll> row[N][10],col[N][10];

ll mnrow[10];
ll mxrow[10];
ll mncol[10];
ll mxcol[10];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,i,j;
        fo(i,N)
        {
            fo(j,10)
            {
                row[i][j].clear();
                col[i][j].clear();
            }
        }
    
        memset(mnrow,-1,sizeof(mnrow));
        memset(mxrow,-1,sizeof(mxrow));
        memset(mncol,-1,sizeof(mncol));
        memset(mxcol,-1,sizeof(mxcol));

        cin>>n;
        vector<string> vs(n);
        fo(i,n)
            cin>>vs[i];

        fo(i,n)
        {
            string s=vs[i];
            fo(j,n)
            {
                ll val=s[j]-'0';
                row[i][val].pb(j);
                col[j][val].pb(i);
            }
        }

        fo(i,n)
        {
            ll d;
            fo(d,10)
            {
                if(!row[i][d].empty())
                {
                    if(mnrow[d]==-1)
                        mnrow[d]=i;
                    mxrow[d]=i;
                }
                if(!col[i][d].empty())
                {
                    if(mncol[d]==-1)
                        mncol[d]=i;
                    mxcol[d]=i;
                }
            }
        }

        ll ans[10]={0};

        fo(i,n)
        {
            ll d;
            fo(d,10)
            {
                if(!row[i][d].empty())
                {
                    ll x,y;
                    x=row[i][d].front();
                    y=row[i][d].back();

                    // ans[d]=max(ans[d],(x-y)*max(i,n-1-i));

                    ll h=max(i-mnrow[d],mxrow[d]-i);
                    ans[d]=max(ans[d],h*max(n-1-x,y));
                }

                if(!col[i][d].empty())
                {
                    ll x,y;
                    x=col[i][d].front();
                    y=col[i][d].back();

                    // ans[d]=max(ans[d],(x-y)*max(i,n-1-i));

                    ll h=max(i-mncol[d],mxcol[d]-i);
                    ans[d]=max(ans[d],h*max(n-1-x,y));
                }
            }
        }

        fo(i,10)
            cout<<ans[i]<<" ";
        cout<<endl;


        
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