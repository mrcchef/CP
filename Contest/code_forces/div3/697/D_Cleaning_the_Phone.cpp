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

bool compare(pii &p1,pii &p2)
{
    if(p1.first==p2.first)
        return p1.second>p2.second;

    return p1.first<p2.first;

}

int main()
{
    fastio
    int t;
    cin>>t;
    while(t--)
    {
        ll n,i,m;
        cin>>n>>m;
        vi a(n),b(n);
        vector<pii> vp;
        fo(i,n)
            cin>>a[i];
        vi one,two;
        mii ma;
        fo(i,n)
        {
            cin>>b[i];
            if(b[i]==1)
                one.pb(a[i]);
            else
            {
                two.pb(a[i]);
            }
            vp.pb({b[i],a[i]});
        }
        sort(one.begin(),one.end(),greater<ll>());
        sort(two.begin(),two.end(),greater<ll>());

        // sort(vp.begin(),vp.end(),compare);
        
        vi osm,tsm;
        osm.pb(0);
        tsm.pb(0);
        fo(i,one.size())
            osm.pb(osm[i]+one[i]);
        
        // for(auto val:osm)
        //     cout<<val<<" ";
        // cout<<endl;

        fo(i,two.size())
            tsm.pb(tsm[i]+two[i]);

        ll ans=INT_MAX;
        for(i=0;i<=two.size();i++)
        {
            ll val=tsm[i];
            ll rem=m-val;
            // deb(rem);
            if(rem<=0)
                ans=min(ans,2*(i)*1LL);
            else
            {
                auto it=lower_bound(osm.begin(),osm.end(),rem)-osm.begin();
                // cout<<*it<<endl;
                // deb(osm[it]);
                // deb(it);
                // deb(osm.size());
                if(it!=osm.size())
                    ans=min(ans,2*(i)+it);
            }
        }
        // auto it=lower_bound(vsm.begin(),vsm.end(),m);
        if(ans==INT_MAX)
            ans=-1;
    
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