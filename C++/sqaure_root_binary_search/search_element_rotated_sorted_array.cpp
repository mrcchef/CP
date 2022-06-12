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

ll search(ll a[],ll n,ll key)
{
    ll low=0,high=n-1,mid;

    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==key)
            return mid;
        else if(a[low]<=a[mid])
        {
            if(key>=a[low] && key<=a[mid])
                high=mid-1;
            else 
                low=mid+1;
        }
        else
        {
            if(key>=a[mid] && key<=a[high])
                low=mid+1;
            else
                high=mid-1;
        }
    }

    return -1;
}
// Recurssive method

// ll search_reccursive(ll a[],ll low,ll high,ll key)
// {
//     if(low>high)
//         return -1;
    
//     ll mid=(low+high)/2;
//     if(a[mid]==key)
//         return mid;
//     if(a[low]<=a[mid])
//     {
//         if(key>=a[low] && key<=a[mid])
//             return search_reccursive(a,low,mid-1,key);
//         else
//             return search_reccursive(a,mid+1,high,key);
//     }

//     if(key>=a[mid] && key<=a[high])
//         return search_reccursive(a,mid+1,high,key);
    
//     return search_reccursive(a,low,mid-1,key);

// }

int main()
{
    ll n,key;
    cin>>n>>key;
    ll a[n];
    for(ll i=0;i<n;i++)
        cin>>a[i];
    ll res=search(a,n,key); 
    cout<<res<<endl;
    // cout<<search_reccursive(a,0,n-1,key);   
 return 0;
}
