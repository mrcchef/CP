#include <iostream>
#include <vector>
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
#define deb(x) cout << #x << "=" << x << endl
const long long mod = 1e9+7;

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll fxp(ll a,ll b,ll m) {
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp(a*a,b/2,m);
    return fxp(a,b-1,m)*a;
}
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

vector<vector<ll>> multiply(vector<vector<ll>> a,vector<vector<ll>> b)
{
    vector<vector<ll>> sol(2,vector<ll>(2));
    for(ll i=0;i<2;i++)
    {
        for(ll j=0;j<2;j++)
        {
            for(ll x=0;x<2;x++)
            {
                sol[i][j]+=(a[i][x]*b[x][j])%mod;
            }
        }
    }
    return sol;
}

vector<vector<ll>> pow(vector<vector<ll>> v,ll n)
{
    vector<vector<ll>> iden={{1,0},{0,1}};
    if(n==0)
        return iden;
    if(n&1)
        return multiply(v,pow(v,n-1));
    return multiply(pow(v,n/2),pow(v,n/2));
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<vector<ll>> v={{0,1},{1,1}};
        vector<ll> b={0,1};
        v=pow(v,n);
        ll res=0;
        for(ll i=0;i<2;i++)
        {
            res+=(v[0][i]*b[i])%mod;
        }
        cout<<res<<endl;
    }
 return 0;
}
