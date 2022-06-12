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

int main() {
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll primes[]={2,3,5,7,11,13,17,19};
        ll sets=1<<8;
        ll val=0;
        for(ll i=1;i<sets;i++)
        {
            ll j=7,num=1,bits=0;
             while(j>=0)
            {
                if(i&(1<<j))
                {
                    bits++;
                    num=num*primes[j];
                }
                j--;
            }
            if(bits&1)
                val=val+(n/num);
            else
                val=val-(n/num);
        }
        cout<<val<<endl;
    }
    
}
