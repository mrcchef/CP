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
// #define double float

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

bool check(vector<double> v,double val,double d)
{
    double cur=v[0];
    ll i=0;
    Fo(i,0,v.size())
    {
        if(cur>v[i]+d)
            return false;
        if(cur>=v[i])
            cur+=val;
        else
        {
            cur=v[i]+val; 
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        double n,i,d;
        cin>>n>>d;
        vector<double> v;
        fo(i,n)
        {
            ll x;
            cin>>x;
            v.pb(x);
        }
        sort(v.begin(),v.end());
        double st=0,ed=v[n-1]+d;
        while((ed-st)>0.000001)
        {
            double mid=(st+ed)/2;
            if(check(v,mid,d))
            {
                st=mid;
            }
            else
                ed=mid;
        }
        cout<<fixed<<setprecision(7)<<st<<endl;
        st=0;
        ed=v[n-1]+d;
        double ans=0;
        while(st<=ed)
        {
            double mid=(st+ed)/2;
            // deb(mid);
            if(check(v,mid,d))
            {
                ans=max(ans,mid);
                st=mid+0.000001;
            }
            else
            {
                ed=mid-0.000001;
            }
        }
        cout<<fixed<<setprecision(7)<<ans<<endl;
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