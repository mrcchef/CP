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
const ll mod = 998244353;

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
        ll n,m,i;
        cin>>n>>m;
        string s1,s2;
        cin>>s1>>s2;
        ll sz1,sz2;
        sz1=s1.size();
        sz2=s2.size();
        string temp;
        fo(i,abs(sz1-sz2))
            temp+='0';
        // cout<<temp<<endl;
        if(s1<s2)
        {
            s1=temp+s1;
        }
        else if(s1>s2)
        {
            s2=temp+s2;
        }
        // cout<<s1<<" "<<s2<<endl;

        ll ans=0;
        ll cnt[s1.size()]={0};
        fo(i,s1.size())
        {
            if(i!=0)
                cnt[i]=cnt[i-1];
            
            if(s2[i]=='1')
                cnt[i]+=1;
        }
        ll pow2=1;
        for(i=s1.size()-1;i>=0;i--)
        {
            // cout<<cnt[i]<<" ";
            if(s1[i]=='1')
            {
                ans+=((cnt[i]%mod)*(pow2%mod))%mod;
            }
            ans%=mod;
            pow2=(pow2*2)%mod;
            pow2%=mod;
        }
        cout<<ans<<endl;

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