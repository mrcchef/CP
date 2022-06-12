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
        ll n,m,i,sm=0,mx1=0,mx2=0;
        cin>>n;
        vi v1(n+1);
        ll sm1[n+1]={0};
        fo(i,n)
        {
            cin>>v1[i+1];
            sm1[i+1]=sm1[i]+v1[i+1];
            mx1=max(mx1,sm1[i+1]);
            // sm+=v1[i];
        }
        cin>>m;
        vi v2(m+1);
        ll sm2[m+1]={0};
        fo(i,m)
        {
            cin>>v2[i+1];
            sm2[i+1]=sm2[i]+v2[i+1];
            mx2=max(mx2,sm2[i+1]);
            // sm+=v2[i];
        }
        i=0;
        ll j=0;
        ll ans=0;




        // while(true)
        // {
        //     if(i<n && v1[i]>=0)
        //     {
        //         sm+=v1[i++];
        //     }
        //     else if(j<m && v2[j]>=0)
        //     {
        //         sm+=v2[j++];
        //     }
        //     else
        //     {
        //         if(i<n && j<m)
        //         {
        //             if(v1[i]<v2[j])
        //                 sm+=v2[j++];
        //             else
        //             {
        //                 sm+=v1[i++];
        //             }
        //         }
        //         else if(i<n)
        //         {
        //             sm+=v1[i++];
        //         }
        //         else if(j<m)
        //         {
        //             sm+=v2[j++];
        //         }
        //         else
        //         {
        //             break;
        //         }
                
        //     }
        //     ans=max(ans,sm);
        // }
        cout<<mx1+mx2<<endl;
        // cout<<max(0LL,ans)<<endl;
        

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