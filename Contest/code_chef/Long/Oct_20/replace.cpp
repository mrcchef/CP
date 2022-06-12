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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,x,p,k,i;
        cin>>n>>x>>p>>k;
        vi v,v1;
        mii m;
        fo(i,n)
        {
            ll x;
            cin>>x;
            v.pb(x);
            v1.pb(x);
            m[x]++;
        }
        ll ans=0;
        sort(v.begin(),v.end());
        k--;
        p--;
        if(m[x]==0)
        {
            v[k]=x;
            m[x]=1;
            ans=1;
        }
        sort(v.begin(),v.end());
        ll inx_l,inx_u;
        inx_u=upper_bound(v.begin(),v.end(),x)-v.begin()-1;
        inx_l=lower_bound(v.begin(),v.end(),x)-v.begin();

        if(p==k)
        {
            if(v[p]!=x)
            {
                if(inx_u<k)
                {
                    ans+=k-inx_u;
                }
                else
                {
                    ans+=inx_l-k;
                }
                
            }
        }
        else if(p<k)
        {
            if(inx_l>p)
            {
                ans=-1;
            }
            else
            {
                if(v[p]==x)
                {

                }
                else
                {
                    ans+=p-inx_u;
                }                
            }
        }
        else if(p>k)
        {
            if(inx_u<p)
                ans=-1;
            else
            {
                if(v[p]==x)
                {

                }
                else
                    ans+=inx_l-p;
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