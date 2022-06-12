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
// for 100% probabitlity such that 2 students will have birthday in the same day when there are 366 days (normal year)
// 
int main()
{
    float p=1;
    float tdays=365;
    float avail_days=365;
    ll i=0;
    while(p>0.5)
    {
        p=p*(avail_days/tdays);
        i++;
        cout<<p<<" "<<i<<endl;
        avail_days-=1;
    }
 return 0;
}
