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

bool compare(ll a,ll b)
{
    return a>b;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        int a[n];
        map<ll,ll> m;
        int flag=0;
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
            m[a[i]]++;
        }
        for(ll i=0;i<n;i++)
        {
            if(m[a[i]]>=3)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            cout<<"NO";
        else
        {
            cout<<"YES"<<endl;
            vi a1,a2;
            int i=0,j=0;
            for(auto it=m.begin();it!=m.end();it++)
            {
                if(it->second==2)
                {
                    a1.pb(it->first);
                    a2.pb(it->first);
                    it->second=0;
                }
                else
                {
                    a2.pb(it->first);
                    it->second=0;
                }
            }
            sort(a1.begin(),a1.end());
            sort(a2.begin(),a2.end(),compare);
            for(ll i=0;i<a1.size();i++)
                cout<<a1[i]<<" ";
            for(ll i=0;i<a2.size();i++)
                cout<<a2[i]<<" ";      
        }
        cout<<endl;
        
    }
 return 0;
}
