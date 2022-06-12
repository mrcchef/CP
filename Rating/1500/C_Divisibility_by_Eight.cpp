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

string s;
mii me;
mii mo;

ll digit(char ch)
{
    return ch-'0';
}

ll check(ll i,ll num)
{
    ll o;
    if(me[num]==1)
        o=0;
    else if(mo[num]==1)
        o=1;
    else
        return 0;
    for(ll j=0;j<i;j++)
    {
        if(o)
        {
            if(digit(s[j])&1)
                return digit(s[j]);
        }
        else
        {
            if(!(digit(s[j])&1))
                return digit(s[j]);
        }
    }

    return 0;
}


void solve()
{
    cin>>s;
    ll n=s.size();

    for(ll i=8;i<100;i+=8)
    {
        me[i]=1;
        mo[i-4]=1;
    }
    ll ans;
    ll flag=0;
    for(ll i=1;i<n-1;i++)
    {
        for(ll j=i+1;j<n;j++)
        {
            ll tn=digit(s[i]);
            ll on=digit(s[j]);
            ll num=tn*10+on;
            // ll val=0;
            ll val=check(i,num);
            if(val>0)
            {
                ans=val*100+num;
                flag=1;
                break;
            }
            
        }
    }

    if(!flag)
    {
        for(ll i=0;i<n-1;i++)
        {
            ll tn=digit(s[i]);
            for(ll j=i+1;j<n;j++)
            {

                ll on=digit(s[j]);
                ll num=tn*10+on;
                if(me[num])
                {
                    ans=num;
                    flag=1;
                    break;
                }
            }
        }
    }

    if(!flag)
    {
        for(ll i=0;i<n;i++)
        {
            ll dg=digit(s[i]);
            if(dg==8 || dg==0)
            {
                ans=dg;
                flag=1;
                break;
            }
        }
    }

    if(flag)
    {
        cout<<"YES"<<endl;
        cout<<ans<<endl;
    }
    else
        cout<<"NO"<<endl;




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