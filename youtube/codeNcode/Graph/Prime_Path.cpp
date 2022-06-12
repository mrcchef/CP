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

const ll N=1e4+5;
// vi prime;
bool check[N];
ll found[N];

ll dist[N];

void cal()
{
    for(ll i=1;i<=N;i++)
        check[i]=true;
    check[0]=check[1]=false;
    for(ll i=2;i<=N;i++)
    {
        if(check[i]==1)
        {
            // prime.pb(i);
            for(ll j=i*i;j<=N;j+=i)
                check[j]=0;
        }
    } 
}

void solve()
{
    ll st,ed;
    cin>>st>>ed;

    queue<ll> q;
    q.push(st);
    found[st]=1;
    dist[st]=0;
    while(!q.empty())
    {
        ll num=q.front();
        q.pop();
        ll d=dist[num];
        ll base=1;
        // deb(num);
        for(int i=1;i<=4;i++)
        {
            if(i==1)
            {
                base=1;
            }
            else
                base*=10;
        
            ll digit=0;
            if(i==4)
                digit=1;
            ll curDigit;

            ll rem=num%(base*10);
            curDigit=rem/base;
            // deb(curDigit);

            for(digit;digit<=9;digit++)
            {
                ll diff=(digit-curDigit)*base;
                // deb(diff);
                ll newNum=num+diff;
                if(check[newNum] && found[newNum]==0)
                {
                    dist[newNum]=min(dist[num]+1,dist[newNum]);
                    q.push(newNum);
                    found[newNum]=1;
                    // deb(newNum);
                }
            }
        }
    }
    // deb(found[ed]);
    // 1033
    // 1733     
    // 3733     
    // 3739     
    // 3779
    // 8779
    // 8179
    // cout<<check[3733]<<endl;
    // cout<<found[1033]<<" "<<found[1733]<<" "<<found[3733]<<" "<<found[3739]<<" "<<found[3779]<<" "<<found[8779]<<" "<<endl;
    if(dist[ed]==INT_MAX)
    {   
        cout<<"Impossible";
    }
    else
        cout<<dist[ed];
    cout<<endl;
}

int main()
{
    fastio
    int t;
    cin>>t;
    cal();
    while(t--)
    {
        for(int i=0;i<N;i++)
        {
            dist[i]=INT_MAX;
            found[i]=0;
        }
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