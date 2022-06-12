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
    ll n,i,k;
    cin>>n>>k;
    vi v(n);
    mii m;
    fo(i,n)
    {
        cin>>v[i];
        v[i]=v[i]%k;
        m[v[i]]++;
    }

    ll cnt=0;
    cnt=(m[0]>0)?1:0;
    // deb(cnt);
    ll limit=(k-1)/2;
    // deb(limit);
    for(i=1;i<=limit;i++)
    {
        ll mn=min(m[i],m[k-i]);
        // deb(i);
        // deb(mn);

        if(m[i]==0 && m[k-i]==0)
        {

        }
        else
        {
            if(m[i]==m[k-i])
            {
                cnt++;
            }
            else if(mn==m[i])
            {
                if(mn==0)
                {
                    cnt+=m[k-i];
                }
                else
                {
                    cnt++;
                    m[i]=0;
                    m[k-i]-=(mn+1);
                    cnt+=m[k-i];
                    m[k-i]=0;
                }
            }
            else
            {
                 if(mn==0)
                {
                    cnt+=m[i];
                }
                else
                {
                    cnt++;
                    m[k-i]=0;
                    m[i]-=(mn+1);
                    cnt+=m[i];
                    m[i]=0;
                }
            }
            // deb(cnt);
        }

    }
    if(k%2==0)
    {
        if(m[k/2]>0)
            cnt++;
    }
    cout<<cnt<<endl;
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