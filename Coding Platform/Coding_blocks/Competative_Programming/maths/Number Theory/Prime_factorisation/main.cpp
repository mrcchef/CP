// n upto 10^9 

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <math.h>

using namespace std;
#define ll long long int
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

vector<ll> primes;

void prime(ll n)
{
    ll x=sqrt(n);
    bool p[x+1]={false};
    p[0]=p[1]=false;
    p[2]=true;
    primes.push_back(2);
    for(ll i=3;i*i<=n;i+=2)
        p[i]=true;
    for(ll i=3;i*i<=n;i+=2)
    {
        if(p[i])
        {
            primes.push_back(i);
            for(ll j=i;j*j<=n;j+=i)
                p[j]=false;
        }
    }   
}

vector<ll> trial_division4(ll n) {
    vector<ll> factorization;
    for (ll d : primes) {
        if (d * d > n)
            break;
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

int main()
{
    int t;
    cin>>t;
    prime(t);
    vector<ll> v=trial_division4(t);
    map<ll,ll> m;
    for(ll i=0;i<v.size();i++)
    {
        m[v[i]]++;
    }
    for(ll i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
    for(auto it=m.begin();it!=m.end();it++)
    {
        cout<<it->first<<" "<<it->second<<" "<<endl;
    }
 return 0;
}
