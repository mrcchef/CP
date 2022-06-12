#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
#include <string>
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

float square_root(ll n,ll p)
{
    ll low=0,high=n,mid;
    float ans=0;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(mid*mid<n)
        {
            ans=mid;
            low=mid+1;
        }
        else if(mid*mid>n)
        {
            high=mid-1;
        }
        else
        {
            ans=mid;
            break;
        }
    }
    // Fraction part

    float inc=0.1;
    while(p--)
    {
        while(ans*ans<=n)
        {
            ans+=inc;
        }
        // val*val >n
        ans-=inc;
        inc/=10;
    }

    return ans;

}

int main()
{

    ll n,p;
    cin>>n>>p;
    float res=square_root(n,p);
    cout<<res<<endl;
 return 0;
}
