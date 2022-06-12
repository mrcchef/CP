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

ll modulor_multiplication(ll a,ll b,ll m)
{
    ll res=0;
    a=a%m;
    while(b)
    {
        if(b&1)
            res=(res+a)%m;
        a=(2*a)%m;
        b=b/2;
    }
    return res;
}

ll modulor_exponentitial(ll a,ll b,ll m)
{
    ll res=1;
    while(b)
    {
        if(b&1)
            res=modulor_multiplication(res,a,m);
        a=modulor_multiplication(a,a,m);
        a%=m;
        b/=2;
    }
    return res;
}

bool miller_rabin(ll n)
{
    if(n==1)    return false;
    if(n==2)    return true;
    if(n%2==0)  return false;
    // now here n is odd so n-1 is even
    // i.e n-1 can be written in the form of d*2^s where d is odd and s is some +ive integer
    ll d=n-1,s=0;
    while(d%2==0)
    {
        s++;
        d=d/2;
    }
    vi a={2,3,5,7,11,13,17,19,23};
    for(ll i=0;i<a.size();i++)
    {
        if(a[i]>n-2) // (a[i]^d)%n
            continue;
        ll ad=modulor_exponentitial(a[i],d,n);
        if(ad%n==1) // number can be prime
            continue;
        bool prime=false;
        for(ll r=0;r<=s-1;r++)
        {
            // (2^r)%n
            ll rr=modulor_exponentitial(2,r,n);
            // (a^(d*2*i))%n
            ll ard=modulor_exponentitial(ad,rr,n);
            if(ard%n==n-1)
            {
                prime=true;
                break;
            }
        }
        if(prime==false)
            return false;
    }
    return true;
}

// this algo is correct for number less than 3825123056546413051

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    if(miller_rabin(n))
    {
        cout<<"prime"<<endl;
    }
    else
        cout<<"Not prime"<<endl;
 return 0;
}
ll fxp(ll a,ll b,ll m) {
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp(a*a,b/2,m);
    return fxp(a,b-1,m)*a;
}
