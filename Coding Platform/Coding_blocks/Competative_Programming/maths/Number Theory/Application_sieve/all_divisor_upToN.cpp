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
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

ll n,di[100]={0};
void solve()
{
    di[0]=di[1]=1;
    for(ll i=2;i<=n;i++)
    {
        if(di[i]==0)
        {
            di[i]=i;
            for(ll j=i*i;j<=n;j+=i)
            {
                if(di[j]==0)
                    di[j]=i;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // fill(di.begin(),di.end(),0);
    cin>>n;
    solve();
    ll i=n;
    while(i>1)
    {
        cout<<di[i]<<" ";
        i=i/di[i];
    }
    cout<<endl;
    for(i=0;i<=n;i++)
        cout<<di[i]<<" ";
 return 0;
}
ll fxp(ll a,ll b,ll m) {
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp(a*a,b/2,m);
    return fxp(a,b-1,m)*a;
}
