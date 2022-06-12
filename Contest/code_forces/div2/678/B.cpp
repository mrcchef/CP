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

vi cal(ll prime[])
{
    vi vec;
    prime[0]=prime[1]=0;
    for(ll i=2;i<=1e5;i++)
    {
        if(prime[i]==1)
        {
            vec.pb(i);
            for(ll j=i*i;j<=1e5;j+=i)
            {
                prime[j]=0;
            }
        }
    }
    return vec;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll prime[100005];
    vi vec;
    for(ll i=0;i<=100005;i++)
        prime[i]=1;
    // memset(prime,1,sizeof(prime));
    // cout<<prime[2];
    vec=cal(prime);
    int t;
    cin>>t;
    while(t--)
    {
        // for(ll i=0;i<5;i++)
        //     cout<<vec[i]<<" ";
        ll n;
        cin>>n;
        ll ans[n][n];
        ans[0][0]=ans[0][1]=ans[1][0]=ans[1][1]=1;
        for(ll i=0;i<n-1;i++)
        {
            for(ll j=0;j<n-1;j++)
            {
                if(i==j)
                    ans[i][j]=1;
                else
                {
                    ans[i][j]=0;
                }
            }
            // cout<<endl;
        }
        for(ll i=0;i<n;i++)
        {
            ans[i][n-1]=ans[n-1][i]=1;
        }
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n;j++)
            {
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
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