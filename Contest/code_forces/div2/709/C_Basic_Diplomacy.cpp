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


struct data{
    ll in;
    vi v;
};

bool compare(data &v1,data &v2)
{
    return v1.v.size()<v2.v.size();
}



void solve()
{
    ll n,m,i,j;
    cin>>n>>m;
    vector<data> arr(m);
    fo(i,m)
    {
        ll sz;
        cin>>sz;
        arr[i].in=i+1;
        fo(j,sz)
        {
            ll x;
            cin>>x;
            arr[i].v.pb(x);
        }
    }

    sort(arr.begin(),arr.end(),compare);

    mii ma;
    
    ll res[m+1]={0};
    ll limit=(m+1)/2;
    // deb(limit);
    ll flag=0;

    fo(i,m)
    {
        // deb(arr[i].in);

        if(arr[i].v.size()==1)
        {
            if(ma[arr[i].v[0]]>=limit)
            {
                flag=1;
                // break;
            }
            ma[arr[i].v[0]]++;
            res[arr[i].in]=arr[i].v[0];
        }
        else
        {
            ll tct=INT_MAX;
            ll ele;
            fo(j,arr[i].v.size())
            {
                if(tct>ma[arr[i].v[j]])
                {
                    tct=ma[arr[i].v[j]];
                    ele=arr[i].v[j];
                }
            }
            // deb(ele);
            // deb(tct);
            
            if(ma[ele]>=limit)
            {
                flag=1;
                break;
            }
            ma[ele]++;
            res[arr[i].in]=ele;
        }
    }
    if(flag)
    {
        cout<<"NO";
    }
    else
    {
        cout<<"YES"<<endl;
        for(i=1;i<=m;i++)
        {
            cout<<res[i]<<" ";
        }
    }
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