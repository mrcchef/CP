//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2302

#include <iostream>
#include <bits/stdc++.h>
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

int main()
{
    ll t;
    ll n=121;
    ll a[n+1];
    a[0]=1;
    a[1]=1;
    for(ll i=2;i<=n;i++)
        a[i]=i-1;
    for(ll i=2;i<=n;i++)
        for(ll j=2*i;j<=n;j+=i)
            a[j]-=a[i];
    cin>>t;
    while(t!=0)
    {
        if(t==1)
            cout<<"0/1"<<endl;
        else if(t==2)
            cout<<"1/1"<<endl;
        else
        {
            ll i,sum=0,k;
            for( i=0;i<=n;i++)
            {
                sum+=a[i];
                if(sum>=t)
                    break;
            }
            t=t-(sum-a[i]);
            ll x=1;
            for(ll j=1;j<i;j++)
            {
                if(__gcd(i,j)==1)
                {
                    if(x==t)
                    {
                        cout<<j<<"/"<<i<<endl;
                    } 
                    x++;   
                }
            }   
        }
    cin>>t;        
    }
 return 0;
}
