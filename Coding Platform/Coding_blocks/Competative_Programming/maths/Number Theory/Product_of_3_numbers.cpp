#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
#include <string>
#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define deb(x) cout << #x << "=" << x << endl
const double mod = 1e9+7;

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll fxp(ll a,ll b) {
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp(a*a,b/2);
    return fxp(a,b-1)*a;
}
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,num,flag=0;
        cin>>n;
        num=n;
        vi primes,fac;
        ll a=1,b=1,c=1;
        for(ll i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                primes.pb(i);
                ll cnt=0;
                while(n%i==0)
                {
                    n=n/i;
                    cnt++;
                }
                fac.pb(cnt);
            }
        }
        if(n>1)
        {
            primes.pb(n);
            fac.pb(1);
        }
        // for(auto x:fac)
        //     cout<<x<<" ";
        // cout<<endl;
        if(primes.size()>=3)
        {
            a=fxp(primes[0],fac[0]);
            b=fxp(primes[1],fac[1]);
            for(ll i=2;i<primes.size();i++)
            {
                c*=fxp(primes[i],fac[i]);
            }
        }
        else if(primes.size()==2)
        {
            ll div=fac[0]+fac[1];
            if(div<=3)
            {
                flag=1;
            }
            else
            {
                a=primes[0];
            b=primes[1];
            c=num/(a*b);
            }
            
            
        }
        else
        {
            ll div=fac[0];
            if(div<=5)
            {
                flag=1;
            }
            else
            {
                a=primes[0];
            b=primes[0]*primes[0];
            c=fxp(primes[0],fac[0]-3);    
            }
            
            
        }
        
        if(flag==1)
        {
            cout<<"NO";
        }
        else
        {
            cout<<"YES"<<endl;
            cout<<a<<" "<<b<<" "<<c;
        }
        cout<<endl;        
        
    }
 return 0;
}

