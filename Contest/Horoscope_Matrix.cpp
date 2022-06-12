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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m,i,j;
        cin>>n>>m;
        ll arr[n][m];
        ll shift=m-1;

        map<ll,ll> s[n+m-1];
        fo(i,n)
            fo(j,m)
                cin>>arr[i][j];
        
        ll q;
        cin>>q;
        ll k;
            ll diff=m-1;
                for(i=0;i<n;i++)
                {
                    for(j=0;j<m;j++)
                    {
                        s[i-j+diff][arr[i][j]]++;
                    }
                }
        
        fo(k,q)
        {
            ll x,y,v;
            cin>>x>>y>>v;
            s[x-y+diff][arr[x-1][y-1]]--;
            if(s[x-y+diff][arr[x-1][y-1]]==0)
                s[x-y+diff].erase(arr[x-1][y-1]);
            s[x-y+diff][v]++;
            arr[x-1][y-1]=v;
            ll flag=1;
            for(ll val=-diff;val<=n-1;val++)
            {
                if(s[val+diff].size()!=1)
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1)
            {
                cout<<"Yes";
            }
            else
            {
                cout<<"No";
            }
            cout<<endl;
            
        }


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