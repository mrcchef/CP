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

// https://www.youtube.com/watch?v=-MhI4Qtk4KQ&list=PLFyEphuOwoKaLr664pT3SHxvuzZazyW-b&index=96&pbjreload=10
// Explanation Video

ll pivot(ll a[],ll n)
{
    ll low=0,high=n-1,mid;
    ll pvt=-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(mid>low && a[mid-1]>a[mid])
        {
            pvt=mid-1;
            return pvt;
        }
        else if(mid<high && a[mid]>a[mid+1])
        {
            pvt=mid;
            return pvt;
        }
        else if(a[low]>a[mid])
            high=mid-1;
        else if(a[high]<a[mid])
            low=mid+1;
    }
    return pvt;
}

int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
        cin>>a[i];
    ll res=pivot(a,n);
    cout<<res;
 return 0;
}
