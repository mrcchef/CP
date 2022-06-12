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

ll tc=1;

// cout<<"Case #"<<tc<<;

void solve()
{
    ll n,m,i,j;
    cin>>n>>m;
    ll arr[n+1][m+1];
    set<pair<ll,pii>> st;
    fo(i,n)
    {
        fo(j,m)
        {
            cin>>arr[i+1][j+1];
            st.insert({-arr[i+1][j+1],{i+1,j+1}});
        }
    }


    ll cost=0;

    while(!st.empty())
    {
        pair<ll,pii> cur=*st.begin();
        st.erase(st.begin());
        ll ele=-cur.first;
        // deb(ele);
        pii pos=cur.second;

        for(i=0;i<4;i++)
        {
            ll x=dx[i]+pos.first;
            ll y=dy[i]+pos.second;

            if(x<1 || x>n || y<1 || y>m)
                continue;
            
            ll diff=abs(arr[x][y]-ele);
            if(diff>1)
            {
                ll wie=arr[x][y];
                st.erase({-wie,{x,y}});
                wie+=diff-1;
                cost+=diff-1;
                arr[x][y]=wie;
                st.insert({-wie,{x,y}});
            }
           
        }
    }

    // fo(i,n)
    // {
    //     fo(j,m)
    //         cout<<arr[i+1][j+1]<<" ";
    //     cout<<endl;
    // }

    cout<<"Case #"<<tc<<": "<<cost<<endl;

}

int main()
{
    fastio
    int t;
    cin>>t;
    while(tc<=t)
    {
        solve();
        tc++;   
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