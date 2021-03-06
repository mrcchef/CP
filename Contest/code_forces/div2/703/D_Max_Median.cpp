#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0) ; cout.tie(0);
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
#define popcount(x) __builtin_popcount(x)
#define all(x) x.begin(),x.end()
#define mem(a,v) memset(a,v,sizeof(a))

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

void solve()
{
    ll n,k,i;
    cin>>n>>k;
    vi v(n+1);
    fo(i,n+1)
        cin>>v[i+1];
    
    ll st=1,ed=n;
    ll ans;
    while(st<=ed)
    {
        ll mid=(st+ed)/2;
        vi pref(n+1,0);
        for(i=1;i<=n;i++)
        {
            if(v[i]>=mid)
                pref[i]=1;
            else
                pref[i]=-1;
            pref[i]+=pref[i-1];
        }

        ll curr_min=INT_MAX;
        ll flag=0;
        for(i=k;i<=n;i++)
        {
            curr_min=min(curr_min,pref[i-k]);
            // b/c of modifing definition of median other wise we can also have equals to sign according to even
            if(pref[i]>curr_min) 
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            ans=mid;
            st=mid+1;
        }
        else
            ed=mid-1;
    }
    cout<<ans<<endl;
}

int main()
{
    fastio
    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();   
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