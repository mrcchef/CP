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

queue<ll> Q[100005];

void solve()
{
    ll n,i;
    cin>>n;
    vi v(n);
    mii m;
    fo(i,n)
    {
        cin>>v[i];
    }
    ll val,cnt=0;
    vector<pii> vp;
    fo(i,n)
    {
        if(i==0)
        {
            val=v[i];
            cnt=1;
        }
        else
        {
            if(val==v[i])
                cnt++;
            else
            {
                vp.pb({val,cnt});
                val=v[i];
                cnt=1;
            }
        }
    }
    vp.pb({val,cnt});

    for(i=0;i<vp.size();i++)
    {
        // cout<<vp[i].first<<" ";
        Q[vp[i].first].push(i);
    }

    // for(i=0;i<100005;i++)
    // {
    //     Q[i].push(INT_MAX);
    // }

    ll cnt1=0,cnt2=0;
    ll prev1=0,prev2=0;

    fo(i,vp.size())
    {
        if(vp[i].second==1)
        {
            if(prev1!=vp[i].first && prev2!=vp[i].first)
            {
                if(prev1==0)
                {
                    prev1=vp[i].first;
                    cnt1++;
                }
                else if(prev2==0)
                {
                    prev2=vp[i].first;
                    cnt2++;
                }
                else
                {
                ll in1=Q[prev1].front();
                ll in2=Q[prev2].front();
                if(in1<in2)
                {
                    prev1=vp[i].first;
                    cnt1++;
                }
                else
                {
                    prev2=vp[i].first;
                    cnt2++;
                }

                }
            }
            else if(prev1==vp[i].first && prev2==vp[i].first)
            {

            }
            else if(prev1==vp[i].first)
            {
                prev2=vp[i].first;
                cnt2++;
            }
            else
            {
                prev1=vp[i].first;
                cnt1++;
            }

        }
        else
        {
            if(prev1!=vp[i].first && prev2!=vp[i].first)
            {
                prev1=prev2=vp[i].first;
                cnt1++;
                cnt2++;
            }
            else if(prev1==vp[i].first && prev2==vp[i].first)
            {

            }
            else if(prev1==vp[i].first)
            {
                prev2=vp[i].first;
                cnt2++;
            }
            else
            {
                prev1=vp[i].first;
                cnt1++;
            }
        }
        Q[vp[i].first].pop();
    }
    cout<<cnt1+cnt2<<endl;
}

int main()
{
    fastio
    int t=1;
    // cin>>t;
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