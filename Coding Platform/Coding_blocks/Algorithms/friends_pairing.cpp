// https://www.geeksforgeeks.org/friends-pairing-problem/

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
// Logic is simple
// There are two cases
// 1st if the nth friend remains single and 2nd when nth friend paired with some other friend
// case-1 the nth friend remains single then there will be no change in the combinations of n-1 friends b/c it just added at the seperately
// case-2 After paring of nth friend we will have n-2 friends remaning i.e. combinations of n-2 friends and now we have n-1 choices to make pair
// with nth element.
int main()
{
    ll n;
    cin>>n;
    ll dp[n+1];
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    for(ll i=3;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2]*(i-1);
    }
    for(ll i=0;i<=n;i++)
        cout<<dp[i]<<" ";
    
 return 0;
}
