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
        vi v(n);
        ll sm=0,mx=INT_MIN;
        fo(i,n)
        {
            cin>>v[i];
            sm+=v[i];
            mx=max(mx,v[i]);
        }

        vi fact;
        fact.pb(1);
        fact.pb(sm);
        for(i=2;i*i<=sm;i++)
        {
            if(sm%i==0)
            {
                fact.pb(i);
                if(sm/i!=i)
                    fact.pb(sm/i);
            }
        }
        ll res=INT_MAX;

        sort(fact.begin(),fact.end(),greater<ll>());

        // for(auto x:fact)
        //     cout<<x<<" ";
        // cout<<endl;

        for(i=0;i<fact.size();i++)
        {
            vi temp=v;
            ll val=sm/fact[i];
            if(mx>val)
                continue;
            
            ll flag=1;
            ll cnt=0;
            for(ll j=0;j<n;j++)
            {
                
                if(val==temp[j])
                {
                    continue;
                }

                if(j+1<n)
                {
                    if(temp[j+1]+temp[j]>val)
                    {
                        flag=0;
                        break;
                    }
                    cnt++;
                    temp[j+1]+=temp[j];
                }

                if(j+1==n && temp[j]!=val)
                {
                    flag=0;
                }
            }
            // deb(val);
            // deb(cnt);
            if(flag==1)
            {
                res=min(res,cnt);

                // deb(fact[i]);
            }
        }

        if(res==INT_MAX)
            res=n-1;

        cout<<res<<endl;


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