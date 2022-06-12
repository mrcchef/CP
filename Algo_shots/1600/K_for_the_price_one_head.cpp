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

struct xyz{
    ll coin;
    ll cnt;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,p,k,i;
        cin>>n>>p>>k;
        ll arr[n+1];
        Fo(i,1,n)
            cin>>arr[i];
        sort(arr+1,arr+n+1);
        xyz dp[n+1];
        dp[0].coin=p;
        dp[0].cnt=0;
        for(i=1;i<=n;i++)
        {
            ll val1=0,val2=0,cost1=-1,cost2=-1;
            if(dp[i-1].coin>=arr[i])
            {
                cost1=dp[i-1].coin-arr[i];
                val1=dp[i-1].cnt+1;
            }
            if(i-k>=0 && dp[i-k].coin>=arr[i])
            {
                cost2=dp[i-k].coin-arr[i];
                val2=dp[i-k].cnt+k;    
            }

            if(cost1==-1 && cost2==-1)
            {
                dp[i].coin=dp[i-1].coin;
                dp[i].cnt=dp[i-1].cnt;
            }
            else if(cost1<=cost2)
            {
                dp[i].coin=cost2;
                dp[i].cnt=val2;
            }
            else
            {
                dp[i].coin=cost1;
                dp[i].cnt=val1;
            }
        }
        // for(auto val:dp)
        //     cout<<val.cnt<<" "<<val.coin<<endl;
        cout<<dp[n].cnt<<endl;
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