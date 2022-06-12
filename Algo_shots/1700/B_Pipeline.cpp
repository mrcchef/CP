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

ll val(ll n,ll k)
{
    return (n*(2*k-n+1))/2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        if(n==1)
        {
            cout<<0;
            return 0;
        }       
        if(n<=k)
        {
            cout<<1;
            return 0;
        }
        ll mx=((k-1)*k)/2;
        mx=mx+1;
        if(mx<n)
        {
            cout<<-1;
            return 0;
        }
        // deb(mx);
        ll st,ed;
        st=1,ed=k-1;
        ll req=n-1,flag=0,cnt=0;
        while(st<=ed)
        {
            ll mid=(st+ed)/2;

            if(val(k-1-mid+1,k-1)<req)
            {
                ed=mid-1;
            }
            else if(val(k-1-mid+1,k-1)>req)
            {
                st=mid+1;
                cnt=k-1-mid+1;
            }
            else
            {
                flag=1;
                cnt=k-1-mid+1;
                break;
            }
            
        }
    
        cout<<cnt;

        
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