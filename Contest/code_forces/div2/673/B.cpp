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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k,i;
        cin>>n>>k;
        vi v;
        mii b,w,eb,ew;
        // unordered_map<ll,list<ll>> um;
        mii m;
        fo(i,n)
        {
            ll x;
            cin>>x;
            m[x]++;
            v.pb(x);
        }
        // ll f[n];
        // memset(f,-1,sizeof(f));
        for(i=0;i<n;i++)
        {
            ll val=k-v[i];
            if(val==v[i] && m[val]>1)
            {
                eb[val]=m[val]/2;
                ew[val]=m[val]-eb[val];
            }
            else
            {
                if(m[val]>0)
                {
                    b[val]=1;
                    w[v[i]]=1;
                    m[val]=m[v[i]]=0;
                }
                else
                {
                    w[v[i]]=1;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            if(eb[v[i]]>0)
            {
                cout<<1<<" ";
                eb[v[i]]--;
            }
            else if(ew[v[i]]>0)
            {
                cout<<0<<" ";
                ew[v[i]]--;
            }
            else if(b[v[i]]==1)
            {
                cout<<1<<" ";
            }
            else if(w[v[i]]==1)
            {
                cout<<0<<" ";
            }        
        } 
        cout<<endl;

        
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