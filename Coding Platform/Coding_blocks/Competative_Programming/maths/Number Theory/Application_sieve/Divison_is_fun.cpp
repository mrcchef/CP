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
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

vi primes;
bitset<1000005> b;

void solve()
{
    b.set();
    b[0]=b[1]=0;
    for(ll i=2;i<=1000000;i++)
    {
        if(b[i])
        {
            for(ll j=i*i;j<=1000000;j+=i)
            {
                b[j]=0;
            }
            primes.pb(i);
        }
    }
}

// based on the fact that the product of all the devisors of any number n is equal to n^d
// where d is x/2 and x is total no. of divisors of n
// for not perfect sq. number x would be even so d is even
// for perfect sq. number x would be odd so we will do x+1 and then d=(x+1)/2;
// eg:- 36=1*2*3*4*6*9*12*18*36 now and 36=(2^2)*(3^2) so x=(2+1)*(2+1)=9
// pairs 1*36 ->1
// 2*18 -> 2
// 3*12 -> 3
// 4*9 -> 4
// 6*6 -> 5 // this we will consider as a pair that why we do increase x by 1 to make x even


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,i;
    cin>>n;
    vi v;
    ll res=1;
    solve();
    fo(i,n)
    {
        ll x;
        cin>>x;
        v.pb(x);
    }
    ll val=1;
    for(i=0;i<n;i++)
    {
        if(v[i]!=0)
        {
            res=(res*(v[i]+1))%mod;
        }
    }
    if(res&1)
    {
        res++;
    }
    for(ll i=0;i<n;i++)
    {
        v[i]=(v[i]*(res/2))%mod;
        // deb(v[i]);
        val=(val*(v[i]+1))%mod;
    }
    cout<<val<<endl;
 return 0;
}

ll fxp(ll a,ll b,ll m) {
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp((a*a)%m,b/2,m);
    return (fxp(a,b-1,m)*a)%m;
}
