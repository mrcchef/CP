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

bool compare(ll a,ll b)
{
    return a<=b;
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
        ll n,m,i;
        cin>>n>>m;
        vi v;
        fo(i,n)
        {
            ll x;
            cin>>x;
            v.pb(x);
        }
        vector<vi> vv(m),vs(m),vr(m);
        
            for(ll j=0;j<n;j++)
            {
                for(i=0;i<m;i++)
                {
                    ll x;
                    cin>>x;
                    v[j]+=x;
                    vv[i].pb(v[j]);
                } 
            }
        vector<pair<ll,ll>> mxs(n,{0,0});
            for(i=0;i<n;i++)
            {
                for(ll j=0;j<m;j++)
                {
                    if(mxs[i].first<vv[j][i])
                    {
                        mxs[i].first=vv[j][i];
                        mxs[i].second=j+1;
                    }
                }  
            }
        vector<pii> vp(n,{INT_MAX,INT_MAX});
        for(i=0;i<m;i++)
        {
            vs[i]=vv[i];
            sort(vs[i].begin(),vs[i].end(),greater<ll>());
            // for(auto x:vs[i])
            //     cout<<x<<" ";
            // cout<<endl;
            vi rank(n,0);
            for(ll j=0;j<n;j++)
            {
                // deb(vv[i][j]);
                ll r=lower_bound(vs[i].begin(),vs[i].end(),vv[i][j],greater<ll>())-vs[i].begin()+1;
                rank[j]=r;
                // deb(r);
            } 
            // for(auto x:rank)
            //     cout<<x<<" ";
            // cout<<endl;
            for(ll j=0;j<n;j++)
            {
                if(rank[j]<vp[j].first)
                {
                    vp[j].first=rank[j];
                    vp[j].second=i+1;
                }
            }
        }
        // for(auto x:vp)
        //     cout<<x.first<<" "<<x.second<<endl;
        // for(auto x:mxs)
        // {
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        ll cnt=0;
        for(i=0;i<n;i++)
        {
            if(vp[i].second!=mxs[i].second)
                cnt++;
        }
        cout<<cnt<<endl;

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