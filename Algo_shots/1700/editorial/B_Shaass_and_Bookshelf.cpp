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
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll n,i;
        cin>>n;
        vi one,two;
        fo(i,n)
        {
            ll x,y;
            cin>>x>>y;
            if(x==1)
            {
                one.pb(y);
            }
            else
            {
                two.pb(y);
            }
        }
        sort(one.begin(),one.end(),greater<ll>());
        sort(two.begin(),two.end(),greater<ll>());

        ll subone[one.size()+1]={0};
        ll subtwo[two.size()+1]={0};

        for(i=1;i<=one.size();i++) 
                subone[i]=subone[i-1]+one[i-1];
        for(i=1;i<=two.size();i++) 
                subtwo[i]=subtwo[i-1]+two[i-1];

        // for(auto x:one)
        //     cout<<x<<" ";
        // cout<<endl;
        // for(auto x:two)
        //     cout<<x<<" ";
        // cout<<endl;

        ll ans=INT_MAX;
        for(i=0;i<=one.size();i++)
        {
            ll ch1=subone[one.size()]-subone[i];
            ll ch2=i;
            // deb(ch1);
            // deb(ch2);
            for(ll j=0;j<=two.size();j++)
            {
                ll ch4=2*(j);
                ll ch3=subtwo[two.size()]-subtwo[j];
                // ch4*=2;
                // cout<<ch3<<" "<<ch4<<endl;
                if(ch4+ch2>=ch3+ch1)
                {
                    ans=min(ans,ch4+ch2);
                }
            }

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