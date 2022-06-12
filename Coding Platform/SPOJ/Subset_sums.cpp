#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
#include <string>
#include <algorithm>
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
    ll n,a,b;
    cin>>n>>a>>b;
    vector<ll> v1,v2;
    ll n1=n/2;
    ll n2=n-n1;
    for(ll i=0;i<n1;i++)
    {
        ll x;
        cin>>x;
        v1.push_back(x);
    }
    for(ll i=0;i<n2;i++)
    {
        ll x;
        cin>>x;
        v2.push_back(x);
    }
    // for(ll i=0;i<v1.size();i++)
    //     cout<<v1[i]<<" ";
    // cout<<endl;
    // for(ll i=0;i<v2.size();i++)
    //     cout<<v2[i]<<" ";
    // cout<<endl;
    vector<ll> s1,s2;
    s1.push_back(0);
    s2.push_back(0);
    for(ll i=1;i<(1<<n1);i++)
    {
        ll sm=0,k=0;
        for(ll j=i;j>0;j=j>>1)
        {
            if(j&1)
            {
                sm+=v1[k];
            }
            k++;
        }
        s1.push_back(sm);
    }
    for(ll i=1;i<(1<<n2);i++)
    {
        ll sm=0,k=0;
        for(ll j=i;j>0;j=j>>1)
        {
            if(j&1)
            {
                sm+=v2[k];
            }
            k++;
        }
        s2.push_back(sm);
    }
    sort(s2.begin(),s2.end());
    // for(ll i=0;i<s2.size();i++)
    //     cout<<s2[i]<<" ";
    // cout<<endl;
    // for(ll i=0;i<s1.size();i++)
    //     cout<<s1[i]<<" ";
    // cout<<endl;
    ll res=0;
    for(ll i=0;i<s1.size();i++)
    {
        ll Ll=a-s1[i];
        ll Ul=b-s1[i];
        auto it1=lower_bound(s2.begin(),s2.end(),Ll);
        auto it2=upper_bound(s2.begin(),s2.end(),Ul);
        ll it1v=it1-s2.begin();
        ll it2v=it2-s2.begin();
        // cout<<it1v<<" "<<it2v<<endl;
        res+=it2v-it1v;
    }
    cout<<res<<endl;

 return 0;
}
