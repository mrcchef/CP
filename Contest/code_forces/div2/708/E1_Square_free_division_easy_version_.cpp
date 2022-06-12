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

const ll N=1e7+1;

ll mask[N];

void cal()
{
    for(ll i=1;i<N;i++)
    {
        mask[i]=i;
    }

    for(ll i=2;i<N;i++)
    {
        if(mask[i]==i)
        {
            for(ll j=2;i*j<N;j++)
            {
                if(mask[j*i]==j*i)  
                    mask[j*i]=i;
            }
        }
    }
}

void solve()
{

    ll n,k,i;
    cin>>n>>k;
    vi v(n);
    fo(i,n)
        cin>>v[i];
    
    mii hm;
    ll cnt=0;
    fo(i,n)
    {
        ll ele=v[i];
        ll val=1;
        while(ele>1)
        { 
            ll ld=mask[ele];
            // deb(ld);
            // deb(ele);
            ll tcnt=0;
            while(ele%ld==0)
            {
                ele/=ld;
                tcnt++;
            }

            tcnt%=2;
            // deb(tcnt);
            if(tcnt==1)
                val*=ld;
            // deb(val);
        }
        // deb(val);
        if(hm[val]==1)
        {
            cnt++;
            hm.clear();
            hm[val]=1;
        }
        else
            hm[val]=1;
    }
    
    cout<<cnt+1<<endl;
}

int main()
{
    fastio
    cal();
    int t;
    cin>>t;
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