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

ll fact[1000005];

void solve()
{
    fact[0]=0;
    fact[1]=1;
    for(ll i=2;i<=100000;i++)
    {
        if(fact[i]==0)
        {
            fact[i]=i;
            for(ll j=i*i;j<=1000000;j+=i)
            {
                fact[j]=fact[i];
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll cnt=0,res=1,prev=1;
        while(n>1)
        {
            if(prev!=fact[n])
            {
                res=res*cnt*(prev-1)
                cnt=0;
            }
            res*=fact[n];
            n=n/fact[n];
        }
    }
 return 0;
}
ll fxp(ll a,ll b,ll m) {
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp(a*a,b/2,m);
    return fxp(a,b-1,m)*a;
}
