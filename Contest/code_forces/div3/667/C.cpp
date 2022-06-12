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
    int t;
    cin>>t;
    while(t--)
    {
        ll n,x,y;
        cin>>n>>x>>y;
        if(n<=2)
        {
            cout<<x<<" "<<y;
        }
        else
        {
            ll start,diff,mx=INT_MAX;
            ll flag=0;
            for(ll st=1;st<=x;st++)
            {
                for(ll dif=1;dif<=y-x;dif++)
                {
                    // deb(y-x);
                    ll check1=0,check2=0;
                    // deb(st);
                    // deb(dif);
                    // deb(st+(n-1)*dif);
                    if(st+(n-1)*dif<y)
                        continue;
                    for(ll j=0;j<n;j++)
                    {
                        if(st+j*dif==x)
                        {
                            check1=1;
                            break;
                        }
                    }
                    for(ll j=0;j<n;j++)
                    {
                        if(st+j*dif==y)
                        {
                            check2=1;
                            break;
                        }
                    }
                    // deb(check1);
                    // deb(check2);
                    if(!(check1 && check2))
                        continue;
                    if(st+(n-1)*dif<mx)
                    {
                        start=st;
                        diff=dif;
                        mx=st+(n-1)*dif;
                    }
                    
                }
            }
            
            for(ll j=0;j<n;j++)
            {
                cout<<start<<" ";
                start+=diff;
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