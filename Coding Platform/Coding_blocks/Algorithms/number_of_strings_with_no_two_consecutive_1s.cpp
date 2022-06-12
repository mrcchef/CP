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

//Logic is pretty simple
//like ones will carry no. of strings which starts with ones and zero will carry  for zeroes
// //initally for the length of one they will both have 1 like 
// 1
// 0
// then for i=2 we have 
// 01
// 00 this presents sum of zeros[1]+ones[1] as zeroes[2]
// and
// 10
// 11 and here we have ones[2]=zeroes[1]
// similary of others

                                                        

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll ones[n+1],zero[n+1];
        ones[1]=zero[1]=1;
        for(ll i=2;i<=n;i++)
        {
            ones[i]=ones[i-1]+zero[i-1];
            zero[i]=ones[i-1];
        }
        for(ll i=1;i<=n;i++)
        {
            cout<<ones[i]<<" "<<zero[i]<<endl;
        }
        cout<<"res:"<<ones[n]+zero[n]<<endl;

    }
 return 0;
}
