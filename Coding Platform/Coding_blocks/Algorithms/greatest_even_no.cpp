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
    string s;
    cin>>s;
    vector<ll> v;
    ll digit=0;
    ll flag=0;
    for(ll i=0;i<s.size();i++)
    {
        ll x=s[i]-'0';
        v.push_back(x);

    } 
    ll last_digit=v[v.size()-1];
    ll val=v.size()-1;
    // for(ll i=0;i<v.size();i++)
    //     cout<<v[i];
    for(ll i=0;i<v.size();i++)
    {
        if(!(v[i]&1) && v[i]<last_digit)
        {
            swap(v[i],v[v.size()-1]);
            flag=1;
            break;
        }
        else if(!(v[i]&1) && v[i]>last_digit)
            val=i;
    }
    if(flag==0)
        swap(v[val],v[v.size()-1]);
    for(ll i=0;i<v.size();i++)
        cout<<v[i];
 return 0;
}
