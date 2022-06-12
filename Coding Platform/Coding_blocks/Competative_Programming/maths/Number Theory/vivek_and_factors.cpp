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

// That is, given a positive number 'S' , they have to find a number whose factors add up to 'S'. 
// Realizing that this task is tougher than the original task, Vivek came to you for help.

// Input Format
// There are several cases . Each case of input will consist of a positive integer 'S'<= 10000 . The last case is followed by a value of 0 .

// Constraints
// 0 < S <= 10000

// Output Format
// print the integer whose factors sum is equal to 'S'. Print the largest Integer whose factors sum is 'S' . If no such number exists, output '-1' .

// Sample Input
// 1
// 102
// 1000
// 0
// Sample Output
// 1
// 101
// -1

const ll n=1e5;
bitset<n+1> b;

void fact(ll x)
{
    ll sm=1;
    for(ll i=2;i*i<=x;i++)
    {
        if(x&i==0)
        {
            x=x/i;
            sm+=i;
        }
    }
    if(x>1)
    {
        sm+=x;
    }
    retuen sm;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll x;
    cin>>x;

    
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