#include <iostream>
#include <vector>
#include<math.h>
#include <string>
using namespace std;
#define ll long long int
#define mod 1e9+7

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
    
        ll n;
        cin>>n;
        vector<ll> v;
        ll digit=0;
        while(n>0)
        {
            digit++;
            v.insert(v.begin(),n%10);
            n=n/10;
        }        
        ll res=0;
        for(ll i=0;i<digit;i++)
        {
            if(v[i]==7)
            {
                res+=1<<(digit-1-i);
            }
        }
        for(ll i=1;i<digit;i++)
        {
            res+=1<<i;
        }
        res++;
        cout<<res<<endl;

 return 0;
}
