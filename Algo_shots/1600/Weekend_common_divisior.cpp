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

void fact(set<ll> &s,ll n)
{
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            s.insert(i);
            while(n%i==0)
            {
                n=n/i;
            }
        }
    }
    if(n>1)
        s.insert(n);
}

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
        vector<pair<ll,ll>> vp;
        fo(i,n)
        {
            ll x,y;
            cin>>x>>y;
            if(x>y)
                swap(x,y);
            vp.pb({x,y});
        }
        sort(vp.begin(),vp.end());

        set<ll> f;
        fact(f,vp[0].first);
        fact(f,vp[0].second);

        for(i=1;i<n;i++)
        {
            ll val1=vp[i].first;
            ll val2=vp[i].second;

            set<ll> temp;

            for(auto it=f.begin();it!=f.end();it++)
            {
                if(val1%*it==0 || val2%*it==0)
                {
                    temp.insert(*it);
                }
            }
            f=temp;
        }

        if(f.size()==0)
            cout<<-1<<endl;
        else
        {
            ll val=*f.begin();
            cout<<val<<endl;
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