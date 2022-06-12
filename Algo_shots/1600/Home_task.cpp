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
        ll n,i,flag=1;
        cin>>n;
        vi v,rem1,rem2;
        ll sm=0,cntz=0;
        mii m;
        fo(i,n)
        {
            ll x;
            cin>>x;
            if(x==0)
                cntz=1;
            sm+=x;
            v.pb(x);
            if(x%3==1)
                rem1.pb(x);
            else if(x%3==2)
                rem2.pb(x);
            m[x]++;
        }
        if(cntz==0)
        {
            cout<<-1;
            return 0;
        }
        ll rem=sm%3;
        sort(v.begin(),v.end(),greater<ll>());
        sort(rem1.begin(),rem1.end());
        sort(rem2.begin(),rem2.end());
        vi rmv;
        if(rem==1)
        {
            if(rem1.size()>=1)
            {
                rmv.pb(rem1[0]);
            }
            else if(rem2.size()>=2)
            {
                rmv.pb(rem2[0]);
                rmv.pb(rem2[1]);
            }
            else
            {
                flag=0;
            }
        }
        else if(rem==2)
        {
            if(rem2.size()>=1)
            {
                rmv.pb(rem2[0]);
            }
            else if(rem1.size()>=2)
            {
                rmv.pb(rem1[0]);
                rmv.pb(rem1[1]);
            }
            else
            {
                flag=0;
            }
        }
        // for(auto x:rem1)
        //     cout<<x<<" ";
        // cout<<endl;
        // for(auto x:rem2)
        // {
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // for(auto x:rmv)
        //     cout<<x<<" ";
        // cout<<endl;
        if(flag==0)
            cout<<-1;
        else
        {
            vi res;
            ll k=0;
            sort(rmv.begin(),rmv.end(),greater<ll>());
            for(auto x:v)
            {
                if(k<rmv.size() && rmv[k]==x)
                {
                    k++;
                    continue;
                }
                res.pb(x);
            }
            if(res.size()>1 && res[0]==0)
            {
                cout<<0;
            }
            else
            {
                for(auto x:res)
                    cout<<x;
            }
        }
        
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