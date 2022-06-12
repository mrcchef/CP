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
    ll n,m;
    cin>>n>>m;
    ll a[n],b[m],c[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(ll j=0;j<m;j++)
    {
        cin>>b[j];
    }
    ll ans;
    for(ans=0;ans<512;ans++)
    {
        ll flag=1;
        for(ll i=0;i<n;i++)
        {
            ll j;
            for( j=0;j<m;j++)
            {
                ll c=(a[i]&b[j])|ans; // why I do OR here with ans
                if(c<=ans) // ans is simple we know that OR is used to maximise the result and here in the question c1|c2|…|cn=ans
                {           // ans if we or of ans on both sides them c1|c2|…|cn|ans=ans|ans --> c1|c2|…|cn|ans=ans
                    break;  // so there would be no change and we can maximise c and if at most maximisation we get any c such that c>ans 
                }              // then than ans is not suitable so we will increment our ans and check for the new ans
            }               // and if there exist a ans for witch all the OR value of c is less than equal to ans then we break our loop and
            if(j==m)       // successfully found the answer.
            {
                flag=0;
                break;
            }
        }
        if(flag)
            break;

    }
    
    cout<<ans<<endl;
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
