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
        ll n,i;
        cin>>n;
        vi v(2*n);
        multiset<ll> mst;
        fo(i,2*n)
        {
            ll x;
            cin>>x;
            v[i]=x;
        }
        sort(v.begin(),v.end());
        ll mx=v[2*n-1];

        fo(i,2*n-1)
        {
            mst.insert(v[i]);
        }
        vector<pii> vp;
        ll ans=-1;

        for(i=0;i<2*n-1;i++)
        {
            multiset<ll> temp=mst;
            vector<pii> tvp;
            ll ele=v[i];
            auto itt=temp.find(ele);
            temp.erase(itt);
            ll tmx=mx;
            tvp.pb({tmx,ele});
            ll flag=0;

            while(!temp.empty())
            {
                ll val=*temp.rbegin();
                auto it=temp.find(val);
                ll val2=tmx-val;
                temp.erase(it);
                if(temp.count(val2)==0)
                {
                    flag=1;
                    break;
                }
                tmx=val;
                tvp.pb({val,val2});
                it=temp.find(val2);
                temp.erase(it);

            }

            if(temp.empty() && flag==0)
            {
                vp=tvp;
                ans=mx+ele;
                break;
            }
        }
        if(ans==-1)
        {
            cout<<"NO";
            cout<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
            cout<<ans<<endl;
            for(auto pa:vp)
            {
                cout<<pa.first<<" "<<pa.second<<endl;
            }
        }
        // cout<<endl;
        
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