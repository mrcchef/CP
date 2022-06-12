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
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<" : "<<f<<endl
const ll mod = 1e9+7;
#define popcount(x) __builtin_popcount(x)
#define all(x) x.begin(),x.end()
#define mem(a,v) memset(a,v,sizeof(a))
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))

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
    ll n,k,i;
    cin>>n>>k;
    string s;
    cin>>s;

    ll cnt=0;
    ll li;

    fo(i,n)
    {
        if(s[i]=='*')  
            cnt++;
    }

    for(i=n-1;i>=0;i--)
        if(s[i]=='*')
        {
            li=i;
            break;
        }

    ll tcnt=0;

    ll ans1=0,ans2=0;
    ll dis=0;
    ll prev=0;

    fo(i,n)
    {
        if(s[i]=='*')
        {
            tcnt++;
            if(tcnt==1)
            {
                ans1++;
                dis=0;
            }
            else if(dis+1==k) 
            {
                dis=0;
                ans1++;
            }
            else if(tcnt==cnt)
            {
                dis=0;
                ans1++;
            }
            else
                dis++;
            prev=i;
        }
        else
        {
            if(tcnt==0) 
                continue;
            if(tcnt==cnt)
                break;
            if(dis+1==k)
            {
                ll diff=i-prev;
                dis=diff;
                ans1++;
            }
            else
                dis++;
        }
    }

    // tcnt=0;
    // for(i=n-1;i>=0;i--)
    // {
    //     if(s[i]=='*')
    //     {
    //         tcnt++;
    //         if(tcnt==1)
    //         {
    //             ans2++;
    //             dis=0;
    //         }
    //         else if(dis+1==k)
    //         {
    //             dis=0;
    //             ans2++;
    //         }
    //         else if(tcnt==cnt)
    //         {
    //             dis=0;
    //             ans2++;
    //         }
    //         else
    //         {
    //             if(dis+1==k)
    //             {
    //                 ll diff=i-prev;
    //                 dis=diff;
    //                 ans2++;
    //             }
    //             else
    //                 dis++;
    //             // trace1(dis);
    //         }
    //     }
    //     else
    //         dis++;
    // }
    // trace2(ans1,ans2);
    // ll ans=min(ans1,ans2);
    cout<<ans1<<endl;
}

int main()
{
    fastio
    int t;
    cin>>t;
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