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
const ll mod = 1e9;

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

struct data{
    ll t,l,r,val;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll n,m,i;
        cin>>n>>m;
        vector<data> v(m);
        fo(i,m)
        {
            cin>>v[i].t>>v[i].l>>v[i].r>>v[i].val;
            v[i].l-=1;
            v[i].r-=1;
        }

        vi diff(n,0),ans(n,mod);
        fo(i,m)
        {
            if(v[i].t==1)
            {
                for(ll j=v[i].l;j<=v[i].r;j++)
                    diff[j]+=v[i].val;
            }
            else
            {
                for(ll j=v[i].l;j<=v[i].r;j++)
                    ans[j]=min(v[i].val-diff[j],ans[j]);
        //         for(auto val:ans)
        //     cout<<val<<" ";
        // cout<<endl;
            }
        }

        fo(i,n)
        {
            if(ans[i]>mod || ans[i]<-mod)
            {
                cout<<"NO";
                return 0;
            }
        }

        vi newArr(n);
        // for(auto val:ans)
        //     cout<<val<<" ";
        // cout<<endl;
        newArr=ans;
        fo(i,m)
        {
            if(v[i].t==1)
            {
                for(ll j=v[i].l;j<=v[i].r;j++)
                    newArr[j]+=v[i].val;
            }
            else
            {
                ll mx=INT_MIN;
                for(ll j=v[i].l;j<=v[i].r;j++)
                {
                    mx=max(mx,newArr[j]);
                }
                // deb(mx);
                if(mx!=v[i].val)
                {
                    cout<<"NO";
                    return 0;
                }
            }
        }

        cout<<"YES"<<endl;
        for(auto val:ans)
            cout<<val<<" ";
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