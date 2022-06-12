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
        ll i;
        string s;
        cin>>s;
        ll n=s.size();
        map<char,ll> m;
        fo(i,n)
        {
            m[s[i]]++;
        }
        vector<char> one,mul,two;
        
        // vector<pair<ll,char>> sp;
        for(auto it:m)
        {
            if(it.second==1)
            {
                one.pb(it.first);
            }
            else if(it.second==2)
            {
                two.pb(it.first);
            }
            else
            {
                mul.pb(it.first);
            }
        }

        ll cnt=0;
        // ll temp=cnt;
        ll j;
        for(auto val:one)
        {
            m.erase(val);
        }
        for(auto val:two)
        {
            m.erase(val);
        }
        for(auto val:mul)
        {
            ll no=m[val]/3;
            m[val]=m[val]%3;
            if(m[val]==1)
                one.pb(val);
            else if(m[val]==2)
                two.pb(val);
            cnt+=no;
        }
        cnt+=min(one.size(),two.size());
        cout<<cnt<<endl;

        

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