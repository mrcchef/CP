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
ll fxp(ll a,ll b,ll m) {
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp(a*a,b/2,m);
    return fxp(a,b-1,m)*a;
}
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

// Mike found an interesting problem. In this problem you are given two integers, n and k. 
// You need to find the the maximum value of x, such that, n! % kx = 0.

// Input Format
// First line contains number of test cases, T. Each test case contains two integers each, n and k.

// Constraints
// 1<=T<=20 1<=n<=10^8 2<=k<=10^8

// Output Format
// Print the value of x for each test case.

// Sample Input
// 2
// 5 2
// 1000 2
// Sample Output
// 3
// 994
// Explanation
// In the first test case, n = 5 and k = 2. So, n! = 120. n! % 2^0 = 0, n! % 2^1 = 0, n! % 2^2 = 0, n! % 2^3 = 0, n! % 2^4 = 8, n! % 2^5 = 24, 
// n! % 2^6 = 56, n! % 2^7 = 120. So, the answer should be 3.


vi primes,di;

void cal_prime(ll n)
{
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            ll cnt=0;
            primes.pb(i);
            while(n%i==0)
            {
                cnt++;
                n=n/i;
            }
            di.pb(cnt);
        }
    }
    if(n>1)
    {
        primes.pb(n);
        di.pb(1);
    }
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       ll n,k,res=INT_MAX;
       cin>>n>>k;
       cal_prime(k);
       vi fact;
       for(ll i=0;i<primes.size();i++)
       {
           ll p=1,cnt=0;
           while(fxp(primes[i],p,mod)<n)
           {
               cnt+=n/fxp(primes[i],p,mod); // We are doing this do find the total number of numbers form 1 to n which are actually multiple of 
               p++;                         // prime[i]^p 
           }
           res=min(res,cnt/di[i]);
       }
       cout<<res<<endl; 
    }
 return 0;
}
