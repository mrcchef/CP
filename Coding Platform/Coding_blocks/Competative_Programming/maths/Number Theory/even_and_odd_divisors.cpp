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

// The problem is as follows: You are given an integer q which denotes the number of queries. For each query, You are given an integer n. You have to find the result of number n.

// The result of a number n is defined as the sum of even divisors of n minus the sum of odd divisors of n.

// More Formally, result = (Sum of even divisors of n) - (Sum of odd divisors of n)

// A divisor of a number n is defined as a positive integer i such that n is divisible by i.

// Input Format
// First line of input contains an integer q denoting the number of queries. After that q lines follow, Each line consists an integer n for which you have to find the value of result.

// Note: Use fast input output as input is quite large;

// Constraints
// 1 <= q <= 100000 1 <= n <= 100000

// Output Format
// You have to print q lines, where the output of the ith line is the result of the ith query.

// Sample Input
// 2
// 3
// 6
// Sample Output
// -4
// 4

ll sm[100001];

// when ever you have to deal with all the divisors of a number you can think of sieve b/c in the 2nd loop we actually iterate all the
// multiples of i so with sudden change you actually customise it

void sieve()
{
    for(ll i=1;i<=100000;i++)
    {   
        for(ll j=i;j<=100000;j+=i)
        {
            if(i&1)
                sm[j]-=i;
            else
                sm[j]+=i;
        }  
    }         
    
}

void add(ll n,ll &odd,ll &even)
{
    if(n&1)
    {
        odd+=n;
    }
    else
        even+=n;
}

ll sm_divi(ll n)
{
    ll sm_odd=0,sm_even=0;
    for(ll i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            add(i,sm_odd,sm_even);
            if(n/i!=i)
                add(n/i,sm_odd,sm_even);
        }
    }
    ll res=sm_even-sm_odd;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(sm,-1,sizeof(sm));
    sieve();
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll res=sm[n];       //method 1 
        // ll res=sm_divi(n); // method 2
        cout<<res<<endl;
    }
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