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

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}


// Time Complexity O(nlogn)
// dp[i] denotes the minimum ending value of the increading subsequence of length i;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll n,i;
        cin>>n;
        vi v;
        fo(i,n)
        {
            ll x;
            cin>>x;
            v.pb(x);
        }
        ll dp[n+1],res=0;
        // memset(dp,INT_MAX,sizeof(dp));
        for(i=1;i<=n;i++)
            dp[i]=INT_MAX;
        dp[0]=INT_MIN;
        for(i=0;i<n;i++)
        {
            ll len=upper_bound(dp,dp+n+1,v[i])-dp; // Insted of for loop we uses upper_bound funtion which will directly give us the index
            if(dp[len-1]<v[i] && v[i]<dp[len])  // which is upper bound to v[i] and then we will check weather this v[i] is greater than  
            {                                    // dp[len-1] b/c we always want to have a strictly increasing dp array 
                dp[len]=v[i];                    // such that there will not be any problem in using upper_bound funtion i.e binary search
            }
        }
        for(auto x:dp)
            cout<<x<<" ";
        cout<<endl;
        for(i=n;i>0;i--)
        {
            if(dp[i]!=INT_MAX)
            {
                cout<<i;
                break;
            }
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