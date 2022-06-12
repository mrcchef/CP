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
    ll n,i;
    cin>>n;
    vi v(n),arr(n);
    set<ll> st;
    fo(i,n)
    {
        cin>>v[i];
        st.insert(v[i]);
        // arr[i]=v[i];
    }
    sort(arr.begin(),arr.end());
    ll j=n-1;
    vi res;

    for(i=n-1;i>=0;i--)
    {
        ll mx=*st.rbegin();
        ll k=i;
        vi temp;
        // deb(mx);
        while(k>=0 && v[k]!=mx)
        {
            if(st.count(v[k]))
                st.erase(v[k]);
            temp.pb(v[k]);
            k--;
        }
        if(k>=0)
        {
            temp.pb(v[k]);
            st.erase(v[k]);
        }
        for(ll l=temp.size()-1;l>=0;l--)
            res.pb(temp[l]);
        // for(auto val:temp)
        //     res.pb(val);
        i=k;
    }
    ll ans=0;
    ll amt=1;
    for(auto val:res)
        cout<<val<<" ";
    // for(i=n-1;i>=0;i--)
    // {
    //     if(i==n-1)
    //     {
    //         ans+=amt*res[i];
    //     }
    //     else
    //     {
    //         amt*=n;
    //         ans+=amt*res[i];
    //     }
    // }
    // cout<<ans<<endl;
    cout<<endl;
    

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