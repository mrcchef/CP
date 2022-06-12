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

vi fact(ll n)
{
    vi v;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            v.pb(i);
            if(i*i!=n)
                v.pb(n/i);
        }
    }
    return v;
}

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
        vi v;
        fo(i,n)
        {
            ll x;
            cin>>x;
            v.pb(x);
        }
        sort(v.begin(),v.end());
        if(n==1)
        {
            ll flag=1;
            for(i=2;i*i<=v[0];i++)
            {
                if(v[0]%i==0)
                {
                    flag=0;
                    break;
                }
            }
            if(flag==0)
            {
                cout<<-1;
            }
            else
            {
                cout<<v[0]*v[0];
            }
            cout<<endl;
            continue;
            
        }
        ll flag=1;
        ll val=v[0]*v[n-1];
        for(i=1;i<=n/2;i++)
        {
            ll tmp=v[i]*v[n-i-1];
            if(tmp!=val)
            {
                flag=0;
                break;
            }
        }
        // deb(flag);
        if(flag==0)
        {
            cout<<-1<<endl;
            continue;
        }
        vi temp=fact(val);
        sort(temp.begin(),temp.end());
        // for(auto x:temp)
        //     cout<<x<<" ";
        if(temp==v)
        {
            cout<<val<<endl;
        }
        else
        {
            cout<<-1<<endl;
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