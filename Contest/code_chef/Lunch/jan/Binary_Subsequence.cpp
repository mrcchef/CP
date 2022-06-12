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

int main()
{
    fastio
    int t;
    cin>>t;
    while(t--)
    {
        ll n,i;
        cin>>n;
        string s;
        cin>>s;
        ll c0[n+1]={0},c1[n+1]={0};
        vi v;
        fo(i,n)
        {
            c0[i+1]=c0[i];
            c1[i+1]=c1[i];
            if(s[i]=='0')
            {
                c0[i+1]++;
            }
            else
            {
                c1[i+1]++;
            }
        }
        ll t0=c0[n];
        ll t1=c1[n];
        // fo(i,n+1) 
        //     cout<<c0[i]<<" ";
        // cout<<endl;
        // fo(i,n+1)
        //     cout<<c1[i]<<" ";
        // cout<<endl;
        i=0;
        ll ans=INT_MAX;
        while(i<n)
        {
            ll j;
            if(s[i]=='0')
            {
                j=i;
                while(s[j++]=='0' && j<n){}
                ll cnt=c1[i]+t0-c0[j];
                // deb(c0[j]);
                // deb(cnt);
                ans=min(ans,cnt);
            }
            else
            {
                
                j=i;
                while(s[j++]=='1' && j<n){}
                ll cnt=c1[i]+t0-c0[i];
                // deb(cnt);
                ans=min(ans,cnt);
 
            }
            i=j;
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