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

// After this problem 
// To Do :- https://leetcode.com/problems/arithmetic-slices-ii-subsequence/

// Logic is similar to longest subsequence
// we are starting from index 2 and check if it last 3 elements are arithmetic sequence then
// we will do 1 + freq[i-1];
// here freq[i]  stores total no. of arithemtic sequence ending at index i
// we are adding 1 b/c the last element can be added to all the sequences which are ending at index i-1 and 
// there will be one extra sequence from i-2 to i
// eles freq[i]=0; 

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++)
            cin>>a[i];
        ll freq[n]={};
        ll sm=0;
        for(ll i=2;i<n;i++)
        {
            if(a[i]-a[i-1]==a[i-1]-a[i-2])
            {
                freq[i]=1+freq[i-1];
            }
            else
            {
                freq[i]=0;
            }
            sm+=freq[i];
        }
        cout<<sm<<endl;
            
    }
 return 0;
}
