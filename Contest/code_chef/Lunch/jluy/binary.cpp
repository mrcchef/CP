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

string intTobin(ll n)
{
    string s;
    while(n>0)
    {
        if(n&1)
        {
            s+='1';
        }
        else
        {
            s+='0';
        }
        n=n>>1;
    }
    reverse(s.begin(),s.end());
}

ll binToint(string s)
{
    ll res=0,val=1,j=0;
    for(ll i=s.size()-1;i>=0;i--)
    {
        val*=fxp(2,j,mod);
        if(s[i]=='1')
        {
            res+=val;
        }
        j++;
    }
    return res;
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
        ll n,mx=INT_MIN;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n,greater<ll>());
        for(ll i=0;i<=n/2;i++)
        {
            for(ll j=n-1;j>=n/2;j--)
            {
                string binx,biny;
                binx=intTobin(a[i]);
                biny=intTobin(a[j]);
                string t1,t2;
                t1=binx+biny;
                t2=biny+binx;
                ll x,y;
                x=binToint(t1);
                y=binToint(t2);
                mx=max(x-y,mx);
            }            
        }
        cout<<mx<<endl;
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