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

const ll N=105,mx=1e6;
mii m[N];
ll cnt=0;

ll query(ll k,ll x)
{
    if(m[k].find(x)!=m[k].end())
        return m[k][x];
    assert(cnt+1<=2222);
    cout<<"? "<<k<<" "<<x<<endl;
    cin>>m[k][x];
    cnt++;
    return m[k][x];
}

void clear_map()
{
    for(ll i=0;i<N;i++)
        m[i].clear();
    cnt=0;
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        clear_map();
        ll n;
        cin>>n;
        vi ans(n+1,0);
        ll tot_inv=query(1,1);
        ll prev=tot_inv;

        while(true)
        {
            ll l=1,r=mx,ele=mx,inv=0,mid;
            while(l<=r)
            {
                mid=(l+r)/2;
                ll res=query(1,mid);
                if(res>prev)
                {
                    ele=mid; // mid
                    r=mid-1;
                    inv=res;
                }
                else
                {
                    l=mid+1;
                }
            }

            if(ele==mx)
            {
                for(ll i=1;i<=n;i++)
                    if(ans[i]==0) ans[i]=mx;
                break;    
            }
            else
            {
                ll freq=inv-prev;
                while(freq--)
                {
                    ll l=1,r=n,mid,pos;
                    while(l<=r)
                    {
                        mid=(l+r)/2;
                        ll res=query(mid,ele);
                        ll left0=0,rightSmall=0;
                        for(ll i=1;i<mid;i++)
                        {
                            if(ans[i]==0)
                                left0++;
                        }

                        for(ll i=mid;i<=n;i++)
                        {
                            if(ans[i]!=0 && ans[i]<ele)
                                rightSmall++;
                        }

                        if(res==tot_inv+left0+rightSmall)
                        {
                            pos=mid;
                            l=mid+1;
                            // break;
                        }
                        else
                        {
                            r=mid-1;
                        }
                        ans[pos]=ele;
                    }
                }
            }
            prev=inv;            
        }
        cout<<"! ";
        for(ll i=1;i<=n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
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