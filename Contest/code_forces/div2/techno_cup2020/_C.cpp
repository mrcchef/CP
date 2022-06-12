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

// Important Points 
// if we have more than k set bits then we can not divide it into k numbers all are of power of 2.
// eg:- 11001101 here k=5, then min parts in which we can divide our number is 5 parts(power of 2) b/c there are 5 set bits.
// if we have k or less  bits in a number then we can divide it into k numbers sll are power of 2.
// if we have k bits then it is understoodable that we can divide our number but if bits are less than k then also we can divide 
// b/c we can divide any number into smaller number such all the numbers are of power of 2;
// eg:- 12= 1100 now if we need to divide it into 3 parts i.e k=3 but number of bits here is 2
// so 12 = 1000 + 10 + 10 (8+2+2) now we have divided our number into 3 parts and all of are power of 2. 

// As per the question we actually need to divide to divide our number as a sum ok k binary numbers
// n=sum(2^x+p) for k values of x(could be same)
// n-k*p=sum(2^x)
// now we the numimum value of x is 0 so minimum value of sum(2^x)=k
// and we can not divide val=n-k*p in to k numbers if there are more than k bits in val
// Since, we need to find miminum k so we looped from k=1 to k=32(upper limit of power of 2);

bool check(ll val,ll k)
{
    if(val>=k && __builtin_popcount(val)<=k) 
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,k=1,p,ans=-1;
    cin>>n>>p;
    for(k;k<32;k++)
    {
        if(check(n-k*p,k))  
        {
            ans=k;
            break;
        }
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