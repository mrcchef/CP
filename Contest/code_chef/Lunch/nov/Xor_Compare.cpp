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

void solve(vi &v,ll n)
{
    while(n)
    {
        if(n&1)
        {
            v.pb(1);
        }
        else
        {
            v.pb(0);
        }
        n=n>>1;
    }
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
        ll x,y,n,i;
        cin>>x>>y>>n;
        ll cnt=0;
        vi vx,vy,vn;
        solve(vx,x);
        solve(vy,y);
        solve(vn,n);

        if(vx.size()<vy.size())
        {
            ll diff=vy.size()-vx.size();
            fo(i,diff)
            {
                vx.pb(0);
            }
        }
        else if(vy.size()<vx.size())
        {
            ll diff=vx.size()-vy.size();
            fo(i,diff)
            {
                vy.pb(0);
            }
        }
        if(vx.size()<vn.size())
        {
            ll diff=vn.size()-vx.size();
            fo(i,diff)
            {
                vy.pb(0);
                vx.pb(0);
            }
        }
        
        reverse(vx.begin(),vx.end());
        reverse(vy.begin(),vy.end());
        reverse(vn.begin(),vn.end());

        ll sz=vn.size();

        ll one,zero,fi=INT_MAX;
        one=zero=1;
        ll val=0;
        fo(i,sz)
        {
            if(vx[i]!=vy[i])
            {
                fi=i;
                if(vx[i]==1)
                {
                    val+=pow(2,sz-i-1);
                }
                break;
            }

            if(vn[i]==1)
                val+=pow(2,sz-i-1);
            
            if(i==0)
            {
                zero*=1;
            }
            else
            {
                zero*=2;
            }

            if(vn[i]==1 && i!=0)
            {
                one*=2;
            }
        }

        if(fi==INT_MAX)
        {
            cout<<0<<endl;
            continue;
        }

        if(fi!=1 && fi>1)
        {
            zero/=2;
        }
        ll tm=pow(2,sz-fi-1);
        ll ans=(one+zero)*tm;
        fo(i,sz-fi-1)
        {
            val+=pow(2,i);
        }
        if(val-n>=0)
        {
            ans=ans-val+n;
        }

        for(ll i=0;i<=n;i++)
        {
            ll v1=x^i,v2=y^i;
            if(v1<v2)
            {
                cnt++;
                deb(i);
            }
        }
        cout<<cnt<<endl;
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