// https://www.geeksforgeeks.org/tiling-problem/

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

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a=1,b=2,val;
        if(n==1)
            cout<<a<<endl;
        else if(n==2)
            cout<<b<<endl;
        else       
        {
            for(ll i=3;i<=n;i++)
            {
                val=a+b;
                a=b;
                b=val;
            }
            cout<<val<<endl;
        }    
    }
 return 0;
}
