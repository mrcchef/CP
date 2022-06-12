#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
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
        ll n,i;
        cin>>n;
        vi a,b,c;
        fo(i,n)
        {
            ll x;
            cin>>x;
            a.pb(x);
        }
        fo(i,n)
        {
            ll x;
            cin>>x;
            b.pb(x);
        }
        fo(i,n)
        {
            ll x;
            cin>>x;
            c.pb(x);
        }
        ll dp[n+1][101],curr[n+1][101];
        memset(curr,0,sizeof(curr));
        for(i=0;i<=n;i++)
        {
            for(ll j=0;j<=100;j++)
                dp[i][j]=INT_MAX;
        }
        ll pass=1;
        for(i=0;i<n;i++)
        {
            if(i==0)
            {
                curr[i][0]=a[i];
                curr[i][c[i]]=b[i];
                dp[i][0]=0;
                dp[i][c[i]]=min(dp[i][c[i]],c[i]);
            }
            else
            {
                ll flag=1;
                ll temp[101];
                memset(temp,INT_MAX,sizeof(temp));

                for(ll j=0;j<=100;j++)
                {
                    if(curr[i-1][j]==0)
                        continue;
                    ll ele=curr[i-1][j];
                    if(a[i]>=ele)
                    {
                        ll val=dp[i-1][j];
                        if(dp[i][0]>val)
                        {
                            curr[i][0]=a[i];
                            dp[i][0]=val;
                        }
                        else if(dp[i][0]==val)
                        {
                            if(curr[i][0]>a[i])
                            {
                                curr[i][0]=a[i];
                            }
                        }
                        // dp[i][0]=min(dp[i][0],dp[i-1][j]);
                        // curr[i][0]=a[i];
                        flag=0;
                    }
                    if(b[i]>=ele)
                    {
                        ll val=dp[i-1][j]+c[i];
                        // dp[i][c[i]]=min(dp[i][c[i]],dp[i-1][j]+c[i]);
                        if(dp[i][c[i]]>val)
                        {
                            curr[i][c[i]]=b[i];
                            dp[i][c[i]]=val;
                        }
                        else if(dp[i][c[i]]==val)
                        {
                            if(curr[i][c[i]]>b[i])
                            {
                                curr[i][c[i]]=b[i];
                            }
                        }
                                       
                        flag=0;
                    }
                }
                if(flag==1)
                {
                    pass=0;
                }
            }
            
        }
        for(i=0;i<n;i++)
        {
            for(ll j=0;j<=16;j++)
                cout<<curr[i][j]<<" ";
            cout<<endl;
        }
        cout<<"Dp:"<<endl;
        for(i=0;i<n;i++)
        {
            for(ll j=0;j<=16;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        if(pass==0)
        {
            cout<<-1;
        }
        else
        {
            ll res=INT_MAX;
            for(i=0;i<=100;i++)
            {
                if(curr[n-1][i]==0)
                    continue;
                res=min(dp[n-1][i],res);
            }
            cout<<res;
        }
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