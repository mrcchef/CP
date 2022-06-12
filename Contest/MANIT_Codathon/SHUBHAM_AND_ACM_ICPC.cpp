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

vi factor_cal(ll n)
{
    vi factor;
    // mii check;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {   
            factor.pb(i);
            if(n/i!=i)
                factor.pb(n/i);
        }
    }
    factor.pb(n);
    return factor;
}

int main()
{
    fastio
    int t=1;
    // cin>>ll t;
    while(t--)
    {
        ll n,i;
        cin>>n;
        vi v(n);
        fo(i,n)
            cin>>v[i];
        sort(v.begin(),v.end());
        ll sm[n][n];
        fo(i,n)
        {
            ll j;
            fo(j,n)
            {
                if(i==j)
                    sm[i][j]=0;
                else
                {
                    sm[i][j]=v[i]+v[j];
                }
            }
        }
        ll ans=1;
        fo(i,n)
        {
            if(i==0)
                continue;
            mii m;
            m[0]=1;
            m[i]=1;
            ll j,k;
            vi temp;
            temp.pb(v[0]+v[i]);
            // temp.pb(v[i]);
            ll cnt=2;
            Fo(j,1,n-1)
            {   
                fo(k,n)
                {
                    if(sm[j][k]==0)
                        continue;
                    if(m[j]==0 && m[k]==0)
                    {
                        m[j]=m[k]=1;
                        cnt+=2;
                        temp.pb(v[j]+v[k]);
                    }
                }   
            }
            if(cnt==n)
            {
                sort(temp.begin(),temp.end());
                ll mn=temp[0];
                vi factor=factor_cal(mn);
                
                for(auto val:factor)
                {
                    ll flag=0;
                    for(j=0;j<temp.size();j++)
                    {
                        // cout<<temp[j]<<" ";
                        if(temp[j]%val!=0)
                        {
                            flag=1;
                            break;
                        }
                    }
                    // cout<<endl;
                    if(flag==0)
                        ans=max(ans,val);
                }
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