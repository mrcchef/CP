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

void solve()
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll ta=a,tb=b,tc=c,td=d;
    vi two_three;
    if(d>c)
    {
        if(d==c+1)
        {
            if(a==0 && b==0)
            {
                while(d>0 && c>0)
                {
                    two_three.pb(3);
                    two_three.pb(2);
                    d--;
                    c--;
                }
                two_three.pb(3);
                    d--;
            }
            else
            {
                cout<<"NO";
                return;
            }
        }
        else
        {
            cout<<"NO";
            return;
        }
    }
    else
    {
        while(d>0 && c>0)
        {
            two_three.pb(2);
            two_three.pb(3);
            d--;
            c--;
        }
    }
    vi zero_one;
    if(b<a)
    {
        if(b+1==a)
        {
            if(tc==0 && td==0)
            {
                while(a>0 && b>0)
                {
                    zero_one.pb(0);
                    zero_one.pb(1);
                    a--;
                    b--;
                }
                zero_one.pb(0);
                    a--;
            }
            else
            {
                cout<<"NO";
                return;
            }
        }
        else
        {
            cout<<"NO";
            return;
        }
    }
    else
    {
        while(b>0 && a>0)
        {
            zero_one.pb(0);
            zero_one.pb(1);
            b--;
            a--;
        }
    }
    vi two_one;
    while(c>0 && b>0)
    {
        two_one.pb(2);
        two_one.pb(1);
        c--;
        b--;
    }
    if(c>0)
    {
        two_one.pb(2);
        c--;
    }
    bool prefix1=false;
    if(b>0)
    {
        prefix1=true;
    }
    // deb(ta+tb+tc+td);
    // ll val=zero_one.size()+two_three.size()+two_one.size()+((prefix1)?1:0);
    // deb(val);
    if(zero_one.size()+two_three.size()+two_one.size()+((prefix1)?1:0)!=ta+tb+tc+td)
    {
        cout<<"NO";
        return;
    }


    cout<<"YES"<<endl;
    if(prefix1)
        cout<<1<<" ";

    for(auto val:zero_one)
        cout<<val<<" ";
    for(auto val:two_three)
        cout<<val<<" ";
    for(auto val:two_one)
        cout<<val<<" ";

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