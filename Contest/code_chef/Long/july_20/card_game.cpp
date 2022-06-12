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

ll digits(ll a)
{
    ll cnt=0;
    while(a)
    {
        ll rem=a%10;
        cnt+=rem;
        a=a/10;
    }
    return cnt;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vi v1,v2;
        ll i;
        fo(i,n)
        {
            ll x,y;
            cin>>x>>y;
            v1.pb(x);
            v2.pb(y);
        }
        ll point1=0,point2=0;
        fo(i,n)
        {
            ll p1=digits(v1[i]);
            ll p2=digits(v2[i]);
            if(p1<p2)
            {
                point2++;
            }
            else if(p1==p2)
            {
                point1++;
                point2++;
            }
            else
            {
                point1++;
            }
        }
        ll res_point,res_person;
        if(point1>point2)
        {
            res_person=0;
            res_point=point1;
        }
        else if(point1==point2)
        {
                        res_person=2;
            res_point=point2;
        }
        else
        {
                        res_person=1;
            res_point=point2;
        }
        cout<<res_person<<" "<<res_point<<endl;
        
    }
 return 0;
}
