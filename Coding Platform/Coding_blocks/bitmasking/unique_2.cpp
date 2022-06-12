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
    int n;
    cin>>n;
    ll a[n],Xor=0;
    vector<ll> v1,v2;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        Xor=Xor^a[i];
    }
    ll set_bit_no = Xor & ~(Xor-1);
   
    for(ll i=0;i<n;i++)
    {
        if(a[i]&(1<<set_bit_no-1))
            v1.push_back(a[i]);
        else
        {
            v2.push_back(a[i]);
        }
    }
    ll frst=0,snd=0;
    for(ll i=0;i<v1.size();i++)
    {
        frst=frst^v1[i];
    }
    for(ll i=0;i<v2.size();i++)
    {
        snd=snd^v2[i];
    }
    cout<<frst<<" "<<snd;
 return 0;
}
