#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
#include <string>
#include <bitset>
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
#define deb(x) cout << #x << "=" << x << endl
const double mod = 1e9+7;

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll fxp(ll a,ll b,ll m) {
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp(a*a,b/2,m);
    return fxp(a,b-1,m)*a;
}
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

const ll n=100000; // a good approximation of root 1e9 is 1e5
vi primes;
bitset<100005> b;

void seg_sieve()
{
    b.set();
    b[0]=b[1]=0;
    for(ll i=2;i<=n;i++)
    {
        if(b[i])
        {
            primes.pb(i);
            for(ll j=i*i;j<=n;j+=i)
            {
                b[j]=0;
            }
        }
    }
}
// With the help of this method we can actually compute prime numbers 10^14

int main()
{
    seg_sieve();
    int t;
    cin>>t;
    while(t--)
    {
        ll p,q;
        cin>>p>>q;
        ll size=q-p+1;
        bool seg[size];
        // here we are creating a segmented array i.e aur original range is [p,q] but now after shifting this range by p 
        // our new range become [p-p,q-p] i.e [0,q-p] where i-p represents ith index b/w p and q
        for(ll i=p;i<=q;i++)
            seg[i-p]=0;
        for(auto x:primes)
        {
            // This is to stop the loop b/c prime vector is very large for it may be the case that q is less than some of the primes 
            // and to avoid unnecesarry iterations we just need to go upto root q
            if(x*x>q)
                break;
            // to start form first number which is a multiple of x and greator than or equal to p
            // if start is less than p then the very next multiple greator than start is the starting number i.e start+x
            ll start=(p/x)*x;
            //this is for the case when the p is less than x then start become 0 
            // to avoid this we will start from the next multiple of x like if we have p=5 q=100 and x=7 so we will directly start from 14
            if(x>=p && x<=q)
                start=2*x;
            // marking all the multiples of primes as 1
            for(ll j=start;j<=q;j+=x)
            {
                seg[j-p]=1;
            }
        }
        // now those number which are marked as 0 it means they are prime but number should not be equal to 1
        for(ll i=p;i<=q;i++)
        {
            if(seg[i-p]==0 && i!=1)
                cout<<i<<endl;
        }
        
    }
 return 0;
}
