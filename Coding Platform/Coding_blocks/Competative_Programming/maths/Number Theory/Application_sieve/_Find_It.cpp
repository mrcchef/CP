// You are given N numbers.
// Now you have Q queries.
// For each query you will be given an integer K.
// You have to find out the number of multiples of K among the given N numbers.

// Input Format
// The first line consists of number N.
// Next N line contains N numbers. Next line contains number of queries Q. Next Q lines contains Integer K for each query

// Constraints
// 1 <= N <= 10^5 1 <= numbers <= 10^5 1 <= Q <= 10^5 1 <= K <= 10^5

// Output Format
// Output Q lines the answer for every query.

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
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

vi fact(100005,0);
map<ll,ll> freq;
ll mx=INT_MIN;

void factor(ll n)
{
    fact[1]=n;
    for(ll i=2;i<=mx;i++)
    {
        if(fact[i]==0)
        {
            for(ll j=i;j<=mx;j+=i)
            {
                fact[i]+=freq[j];
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    vi a;
    for(ll i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        mx=max(mx,x);
        a.pb(x);
        freq[x]++;
    }
    ll q,j=0;
    factor(n);
    cin>>q;
    fo(j,q)
    {
        ll val;
        cin>>val;
        cout<<fact[val]<<endl;
    }
    

 return 0;
}
ll fxp(ll a,ll b,ll m) {
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp(a*a,b/2,m);
    return fxp(a,b-1,m)*a;
}
