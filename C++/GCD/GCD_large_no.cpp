#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
#include <string>
#include <bits/stdc++.h>
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
// constraints a<=10^500 and b<=50000
// we will store a in string and as we khow gcd(a,b)=gcd(b,a%b) 
// now 0<=a%b<=b-1 we can easliy use eculid algorithm 
int main()
{
    string a;
    ll b;
    cin>>a>>b;
    ll r=0;
    for(ll i=0;i<a.size();i++)
    {
        r=(r*10+a[i]-'0')%b;
    }
    ll t;
    while(r>0)
    {
        t=b%r;
        b=r;
        r=t;
    }
    cout<<b<<endl;
    // or use 
    // cout<<__gcd(b,r);
 return 0;
}
