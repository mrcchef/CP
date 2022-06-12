#include <iostream>
#include <vector>
#include <string>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1e9+7
#include<climits>

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

// THis function is for specific number of coins
// int cal(ll n,ll f[]) 
// {
//     if(n==0)
//         return 0;
//     if(n==1||n==7||n==10)
//     {
//         return 1;
//     }
//     ll op1,op2,op3;
//     if(n>=1 && f[n-1]==0)
//     {
//         f[n-1]=cal(n-1,f);
//         op1=f[n-1];
//     }    
//     if(n>=7 && f[n-7]==0)
//     {
//         f[n-7]=cal(n-7,f);
//         op2=f[n-7];
//     }    
//     if(n>=10 && f[n-10]==0)
//     {
//         f[n-10]=cal(n-10,f);
//         op3=f[n-10];
//     }
//     return min(min(op1,op2),op3)+1;
// }

ll CalCoin(ll f[],ll coin[],ll n,ll m)
{
    if(n==0)
        return 0;
    if(f[n]!=0)
        return f[n];
    ll res=INT_MAX;
    for(ll i=0;i<m;i++)
    {
        ll subsol=0;
        if(n-coin[i]>=0)
        {
            subsol=CalCoin(f,coin,n-coin[i],m);
            res=min(res,subsol+1);
        }   
        else
        {
            break;
        }
        
        
    }
    f[n]=res;
    return f[n];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        ll f[n+1]={0};
        ll coin[m];
        for(ll i=0;i<m;i++)
            cin>>coin[i];
        sort(coin,coin+m);
        ll res=CalCoin(f,coin,n,m);
        cout<<res<<endl;
    }
 return 0;
}
