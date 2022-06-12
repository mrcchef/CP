#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define ll long long int
#define mod 1000000007

ll add(ll trr, ll brr,ll p=mod) { trr%=p; brr%=p; return (trr+brr + p)%p;}
ll mul(ll trr, ll brr,ll p=mod) { trr%=p; brr%=p; return (trr*brr + p)%p;}

ll power(ll x,ll n,ll p=mod)
{   if(x==0) return 0; 
    if(n==0 || x==1) return 1LL;
    ll r = (power(x,n/2,p))%p; 
    if(n&1) return mul(mul(r,r,p) , x,p); 
    else return mul(r,r,p);
}


int main()
 {
	// your code goes 
    ll test;
    cin>>test;
    while(test--)
    {
        ll n,c=0,trr,brr,s=0;
        cin>>trr>>brr;
        if(trr>brr)
        {
        for(ll i=0;i<=60;i++)
        {
            if(brr<<i==trr)
                {
                    c=1;
                    s=i;
                    break;
                }
        }
        }
        if(trr<brr)
        {
            for(ll i=0;i<=60;i++)
        {
            if(trr<<i==brr)
                {
                    c=1;
                    s=i;
                    break;
                }
        }
        }
        if(trr==brr)
            cout<<0<<endl;
        else if(c==0)
            cout<<-1<<endl;
        else
        {
            ll ans=0;
            while(s!=0)
            {
                if(s>=3)
                {
                    s-=3;
                    ans++;
                }
                else if(s>=2)
                {
                    s-=2;
                    ans++;
                }
                else if(s>=1)
                {
                    s-=1;
                    ans++;
                }
            }
            cout<<ans<<endl;
        }
   
    }
}