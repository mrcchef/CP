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

ll sumv(vi v)
{
    ll i;
    for(i;i<v.size();i++)
    {
        if(v[i]==0)
        {
            
        }
        else
        
    }
}

bool check(ll n,ll cntA[],ll cntB[],ll cntC[],ll selectBit[])
{
    ll i;
    vi open;
    vi close;
    fo(i,3)
    {
        if(selectBit[i]==0)
            close.pb(i);
        else
            open.pb(i);
    }

    fo(i,n)
    {
        
    }
}

void solve()
{
    ll i,n;
    string s;
    cin>>s;
    n=s.size();
    ll cnt[3]={0};
    ll cntA[n]={0},cntB[n]={0},cntC[n]={0};
    ll firstc=s[0]-'A';
    fo(i,n)
    {
        ll val=s[i]-'A';
        cnt[val]++;
        if(i>0)
        {
            cntA[i]=cntA[i-1];
            cntB[i]=cntB[i-1];
            cntB[i]=cntB[i-1];
        }
        if(val==0)
        {
            cntA[i]++;
        }
        else if(val==1)
        {
            cntB[i]++;
        }
        else 
        {
            cntC[i]++;
        }
    }

    ll brace[2]={1,0};

    for(i;i<8;i++)
    {
        ll chA,chB,cbC,j;
        ll selecBit[3];
        fo(j,3)
        {
            selecBit[j]=i&(1<<j);
            check(n,cntA,cntB,cntC,selecBit);
        }

    }



}

int main()
{
    fastio
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