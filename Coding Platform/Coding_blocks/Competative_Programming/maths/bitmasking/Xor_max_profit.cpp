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

void set_ith_bit(ll &n,ll i)
{
    ll mask=1<<i;
    n=n|mask;
}

void clear_ith_bit(ll &n,ll i)
{
    ll mask=~(i<<i);
    n=n&mask;
}

int main()
{
    ll val1,val2;
    cin>>val1>>val2;
    ll sz=log2(val2)+1;
    ll flag=0;
    for(ll i=sz-1;i>=0;i--)
    {
        ll bit1,bit2;
        bit1=val1&(1<<i);
        bit2=val2&(1<<i);
        if(bit1!=bit2)
        {
            flag=1;
        }
        if(flag==1 && bit1==bit2)
        {
            if(bit1==0)
                set_ith_bit(val1,i);
            else
            {
                clear_ith_bit(val2,i);
            }
        }
    }
    ll res=val1^val2;
    cout<<res<<endl;
 return 0;
}
