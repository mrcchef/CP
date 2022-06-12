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

const ll N=1e6+5;

vi prime;
bool check[N];

void cal()
{
    for(ll i=1;i<=N;i++)
        check[i]=true;
    check[0]=check[1]=false;
    for(ll i=2;i<=N;i++)
    {
        if(check[i]==1)
        {
            prime.pb(i);
            for(ll j=i*i;j<=N;j+=i)
                check[j]=0;
        }
    } 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cal();
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll ans=INT_MAX;
        for(ll i=0;i<prime.size();i++)
        {
            if(prime[i]-1>=n)
            {
                auto it=lower_bound(prime.begin(),prime.end(),prime[i]+n);
                if(it==prime.end())
                    continue;
                ll val=(*it)*prime[i];
                if(val-(*it)>=n)
                {
                    ans=min(ans,val);
                    break;
                }
            }
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