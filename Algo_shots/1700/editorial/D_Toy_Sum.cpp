#include <bits/stdc++.h>
using namespace std;
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

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

        ll check[1000001]={0},s=1e6,paired[1000001]={0},val=1;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll n,i;
        cin>>n;
        vi v(n);
        fo(i,n)
        {
            cin>>v[i];
            check[v[i]]=1;
        }
        
        vi res;

        fo(i,n)
        {
            if(check[s-v[i]+1]==0)
            {
                res.pb(s-v[i]+1);
                check[s-v[i]+1]=1;
            }
            else
            {
                if(paired[v[i]])
                {
                    continue;
                }

                while(check[val] || check[s-val+1])
                    val++;
                
                res.pb(s-val+1);
                res.pb(val);

                check[val]=1;
                check[s-val+1];

                paired[v[i]]=1;
                paired[s-v[i]+1]=1;

            }
        }
        cout<<res.size()<<endl;
        for(auto x:res)
            cout<<x<<" ";

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