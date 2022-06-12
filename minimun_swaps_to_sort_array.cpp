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
// It is based on the logic that we will iterate our array and while iterating we will check wheather value of element is same as it's index
// if yes then skip
// if no then we will move to next index which will be equal to the value of that index
// and this cycle will terminate when we will reach to a element which is already visited.
// total no. of swaps will be equal to total cycle edge minus one.
// for multiple cycle we will add these values.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n+1];
        for(ll i=1;i<=n;i++) cin>>a[i];
        bool visited[n+1]={false};
        ll tswap=0;
        for(ll i=1;i<=n;i++)
        {
            if(visited[i]==false)
            {
                visited[i]=true;
                if(a[i]==i)
                    continue;
                else
                {
                    ll index=a[i];
                    while(!visited[index])
                    {
                        visited[index]=true;
                        index=a[index];
                        tswap++;
                    }
                }
            }
        } 
        cout<<tswap<<endl;
    }
 return 0;
}
