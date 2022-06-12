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

const int N=5000;
#define PRIME mod

ll fact[N],invfact[N];
void init(){
    ll p=PRIME;
    fact[0]=1;
    ll i;
    for(i=1;i<N;i++){
        fact[i]=i*fact[i-1]%p;
    }
    i--;
    invfact[i]=fxp(fact[i],p-2,p);
    for(i--;i>=0;i--){
        invfact[i]=invfact[i+1]*(i+1)%p;
    }
}

ll ncr(ll n,ll r)
{
    if(n<0 || r<0 || n<r) 
        return 0;
    return fact[n]*invfact[n-r]%PRIME*invfact[r]%PRIME;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    init();
    // cin>>t;
    while(t--)
    {
        ll n,x,pos;
        cin>>n>>x>>pos;
        ll left=0,right=n;
        ll lcnt=0,rcnt=0,ans;
        while(left<right)
        {
            ll mid=(left+right)/2;
            if(mid<pos)
                lcnt++;
            else if(mid>pos)
            {
                rcnt++;
            }
            if(mid<=pos)
            {
                left=mid+1;
            }
            else
            {
                right=mid;
            }
        }
        // deb(ncr(x-1,lcnt));
        // deb(ncr(n-x,rcnt));
        // deb(fact[n-lcnt-rcnt-1]);
        // deb(fact[lcnt]);
        // deb(fact[rcnt]);
        ans=ncr(x-1,lcnt)%mod*ncr(n-x,rcnt)%mod*fact[n-lcnt-rcnt-1]%mod*fact[lcnt]%mod*fact[rcnt]%mod;
        // for(ll i=1;i<n-cnt;i++)
        // {
        //     ans=(ans*i)%mod;
        // }
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