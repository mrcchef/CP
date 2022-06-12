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
// this is actually based on Linear Search

// Method 1 in which we actually uses the index value i for the array
ll pos(vi v,ll i,ll key)
{
    if(i==-1)
        return -1;
    if(v[i]==key)
        return i;
    return pos(v,i-1,key);
}

// method 2 in which we actually decreses the array as we call it but here we also call first and then check

ll index(ll *v,ll n,ll key)
{
    if(n==0)
        return -1;
    ll i=index(v+1,n-1,key); // here in the next call we are actually decreasing the array
    if(i==-1) //  if the value is not present on the 2nd part then it wil return -1
    {
        if(v[0]==key) // if the value if present at the first part i.e v[0] (it actullay contains only single element)
            return 0;
        else 
            return -1;
    }
    return i+1; // other wise just return the index of key and add one so that index will get adjusted as per the original array
}   // b/c this index i is based on the 2nd part of the array


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,i;
    cin>>n;
    vi v;
    fo(i,n)
    {
        ll x;
        cin>>x;
        v.pb(x);
    }
    ll val;
    cin>>val;
    ll a[n];
    for(ll i=0;i<n;i++)
        a[i]=v[i];
    cout<<pos(v,n-1,val)<<endl;
    // cout<<pos2(v,n-1,val,-1)<<endl;
    cout<<index(a,n,val);
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