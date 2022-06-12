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

ll res[11][11]={0};

ll aa[8]={2,2,1,1,-1,-1,-2,-2};
ll ab[8]={1,-1,2,-2,2,-2,1,-1};

void solve(ll a[11][11],ll i,ll j,ll n)
{
    if(i>=n || j>=n || i<0 || j<0)
        return ;
    if(a[i][j]==0)
        return ;
    if(res[i][j]==1)
        return ;
    res[i][j]=1;
    for(ll k=0;k<8;k++)
    {
        solve(a,i+aa[k],j+ab[k],n);
    }   
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,i,j;
    cin>>n;
    ll a[11][11];
    fo(i,n)
    {
        fo(j,n)
            cin>>a[i][j];
    }
    ll cnt=0;
    solve(a,0,0,n);
    // res[0][0]=1;
    fo(i,n)
    {
        fo(j,n)
        {
            cout<<res[i][j]<<" ";
            if(res[i][j]==0 && a[i][j]==1)
            {
                cnt++;
            }
        }
        cout<<endl;
    }
    cout<<cnt<<endl;

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
