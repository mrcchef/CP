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

// Explanation video 
// https://www.youtube.com/watch?v=Ss9ta1zmiZo&t=1281s

bool isValidConfig(ll a[],ll n,ll m,ll ans)
{
    ll curr_sum=0,students=1;
    for(ll i=0;i<n;i++)
    {
        if(curr_sum+a[i]>ans)
        {
            curr_sum=a[i];
            students++;
            if(students>m)
                return false;
        }
        else
        {
            curr_sum+=a[i];
        }
    }    
    return true;
}

ll binary_search(ll a[],ll n,ll m)
{
    ll low=a[n-1],high,mid;
    ll total_pages=0;
    for(ll i=0;i<n;i++)
    {
        total_pages+=a[i];
    }
    high=total_pages;
    ll final_ans=0;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(isValidConfig(a,n,m,mid))
        {
            final_ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return final_ans;
}

int main()
{
    ll n,m;
    cin>>n>>m;
    ll a[n];
    for(ll i=0;i<n;i++)
        cin>>a[i];
    ll res=binary_search(a,n,m);
    cout<<res<<endl;    
 return 0;
}
