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
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll n,q,i;
        cin>>n>>q;
        vi v;
        ll arr[31]={0};
        fo(i,n)
        {
            ll x;
            cin>>x;
            ll msb=log2(x);
            arr[msb]++;
            v.pb(x);
        }
        // cin>>q;
        fo(i,q)
        {
            ll num,cnt=0;
            ll temp[31]={0};
            cin>>num;
            ll sz=log2(num);
            for(ll j=0;j<=sz;j++)
            {
                if(num&(1<<j))
                {
                    ll req=1,bit=1,flag=1;
                    for(ll k=j;k>=0;k--)
                    {
                        if(arr[k]-temp[k]>0)
                        {
                            if(arr[k]-temp[k]>=req)
                            {
                                cnt+=req;
                                temp[k]+=req;
                                req=0;
                                break;
                            }
                            else
                            {
                                cnt+=arr[k]-temp[k];
                                req-=arr[k]-temp[k];
                                temp[k]+=arr[k]-temp[k];
                            }
                        }
                        req=req<<bit;
                    }
                    if(req!=0)
                    {
                        cnt=-1;
                        break;
                    }
                }
            }

            cout<<cnt<<endl;

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