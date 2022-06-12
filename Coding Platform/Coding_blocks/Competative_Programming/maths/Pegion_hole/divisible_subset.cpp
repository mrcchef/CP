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

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        ll i=0;
        fo(i,n)
            cin>>a[i];
        ll sm[n]={0};
        sm[0]=a[0];
        ll index[n]={0};
        index[sm[0]]++;
        for(i=1;i<n;i++)
        {
            sm[i]=sm[i-1]+a[i];
            sm[i]=sm[i]%n;
            index[sm[i]]++;
        }
        for(i=0;i<n;i++)
        {
            if(index[i]>1)
                break;
        }
        if(i==n)
            i=0;
        vi v;
        ll flag=0;
        if(i==0)
        {
            for(ll j=0;j<n;j++)
            {
                if(sm[j]==0)
                    break;
                v.pb(j+1);
            }
        }
        else
        {
            for(ll j=0;j<n;j++)
            {
                if(sm[j]==i)
                {
                    flag=1;
                }
                if(flag)
                {
                    if(sm[j]==i && !v.empty())
                        flag=0;
                    v.pb(j+1);
                    if(flag==0)
                        break;
                }
            } 
        }
        cout<<v.size()<<endl;     
        for(ll j=0;j<v.size();j++)
        {
            cout<<v[j]<<" ";
        }
        cout<<endl;

    }
 return 0;
}
