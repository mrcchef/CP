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

ll dp[205][500];

ll solve(ll idx,ll T,ll n,ll arr[])
{
    if(idx==n)
    {
        return 0;
    }
    if(T==2*n+1)
        return INT_MAX;
    
    if(dp[idx][T]!=-1)
        return dp[idx][T];

    ll ans=INT_MAX;
    ans=min(ans,abs(T-arr[idx])+solve(idx+1,T+1,n,arr));
    ans=min(ans,solve(idx,T+1,n,arr)); // Since, In this question we need to remove all the elements so we can not skip any one
    return dp[idx][T]=ans;  // instead of skipping that element we can skip picking that element at time T and we move to next 
}                            // time to pick 


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        ll n,i;
        cin>>n;
        ll arr[n];
        fo(i,n)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        cout<<solve(0,1,n,arr)<<endl;

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