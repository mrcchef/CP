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
        ll n,m;
        cin>>n>>m;
        ll ans=0;
        if(m==1)
        {
            cout<<n*n<<endl;
            return 0;
        }
        for(ll i=1;i<=m;i++)
        {
            for(ll j=1;j<=m;j++)
            {
                if((i*i+j*j)%m==0)
                {
                    ans+=((n-i+m)/m)*((n-j+m)/m);  // here we get an index i and j which satisfy the condition 
                     // now we will find all the other pairs such that it is less than n and it's modulos 
                } // remains same. Let say x is the number of index other than i whose mod remains i 
                //--->   i+x*m<=n . Now (i+x*m)/m <= n/m i.e. i/m + x <=n/m ==> x <= (n-i)/m (these are the maximum number of  
            }   //  different values of first element of the pair such that modulos with m remains same i.e. i 
        }   // now if we add 1 then we will include i also and now total number will becomes ((n-i)/m)+1 or (n-i+m)/m 
        // similary we will do for the 2nd element of the pair
        // i.e. why we are adding count as (n-i+m)/m + (n-j+m)/m  
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