#include <iostream>
#include <vector>
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

void printsubseq(ll n,string s)
{
    ll i=0;
    while(n>0)
    {
        (n&1)?cout<<s[i]:cout<<"";
        i++;
        n=n>>1;
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        ll sz=s.size();
        ll subset=(1<<sz)-1;
        for(ll i=1;i<=subset;i++)
        {
            printsubseq(i,s);
            cout<<endl;
        }
    }
 return 0;
}
