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
        ll n,i;
        cin>>n;
        vi v;
        fo(i,n)
        {
            ll x;
            cin>>x;
            v.pb(x); 
        }
        fo(i,n)
        {
            v.pb(v[i]);
        }
        set<ll> fact;
        for(i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                if(i>2)
                    fact.insert(i);
                if((n/i)>2)
                    fact.insert(n/i);
            }
        }
        ll check=0,sz=fact.size();
        for(auto val:fact)
        {   
            // deb(val);
            ll inc=n/val,pass=0;
            for(ll k=0;k<inc;k++)
            {
                ll flag=1,cnt=0;
                for(ll j=k;cnt<=val;j+=inc)
                {
                    if(v[j]==0)
                    {
                        flag=0;
                        break;
                    }
                    cnt++;
                }   
                if(flag==1)
                {
                    pass=1;
                    break;
                }
            }
            if(pass==1)
            {
                check=1;
                break;
            }
        }
        if(check==0)
            cout<<"NO";
        else
            cout<<"YES";
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