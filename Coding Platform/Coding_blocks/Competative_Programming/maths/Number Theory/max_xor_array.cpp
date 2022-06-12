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
#define endl "\n"
#define deb(x) cout << #x << "=" << x << endl
const ll mod = 1e9+7;

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

// You are given an array containing n elements. Xor of an array is defined as the xor of all the elements present in the array.
//  You can remove atmost one element from the array to maximize the value of XOR of array.
//   Find the maximum XOR value you can get for the resulting array.

// Input Format
// First line of input contains an integer n denoting the size of the array. After that n lines follow,
//  where the i th line contains the i'th element of the array.

// Constraints
// 1 <= n <= 1000000 0 <= elements of array <= 10^18

// what we can do is we can first cal cumulative xor of the whole array and then if one by one we take cumu. xor with all elements
// then that particular elements get elemenated from the array and we get the resultant xor of the array
// we will take the maximum among all the xor

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,i,mx=INT_MIN;
    ll xo=0;
    cin>>n;
    vi v;
    fo(i,n)
    {
       ll x;
       cin>>x;
       v.pb(x);
       xo=xo^x;
    }
    xo=xo^v[0];
    for(ll i=1;i<n;i++)
    {
        xo=max(xo,xo^v[i]);
    }
    cout<<xo<<endl;

 return 0;
}
ll fxp(ll a,ll b,ll m) {
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp(m_m(a,a,m),b/2,m);
    return m_m(fxp(a,b-1,m),a,m);
}
ll m_m(ll a,ll b,ll m) 
{
    ll res=0;
    a=a%m;
    while(b)
    {
        if(b&1)
        {
            res+=a; 
            res=res%m;
        }
        a=(a*2)%m;
        b=b/2;
    }
    return res;
}
