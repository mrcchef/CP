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
    ll n,m,x,y,k;
    cin>>n>>m;
    cin>>x>>k>>y;
    ll a[n],b[m];
    map<ll,ll> ma,mb;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        ma[a[i]]++;
    }   
    for(ll i=0;i<m;i++)
    {
        cin>>b[i];
        mb[b[i]]++;
    }
    ll cost=0,cnt=0,flag=0;
    for(ll i=0;i<n;i++)
    {

        if(cnt==k)
        {
            cost+=min(x,k*y);
            flag=1;
            cnt=0;
        }
        if(ma[a[i]]>mb[a[i]])
        {
            cnt++;
        }
        else
        {   if(flag==0)
            {
                cnt++;
            cost+=cnt*y;
            cnt=0;
            flag=1;
            }
            
        }
    }
    cout<<cost<<endl;
 return 0;
}
