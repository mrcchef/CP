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

// Method 1
void iter(vi &v,ll i,ll n)
{
    if(i==n-1)
        return ;
    if(v[i]>v[i+1])
        swap(v[i],v[i+1]);
    iter(v,i+1,n);
}

void bubble_sort(vi &v, ll n)
{
    if(n==1)
        return;
    iter(v,0,n);
    bubble_sort(v,n-1);
}

// Method 2 

void bubble_sort_recurrsion(vi &v,ll i,ll n)
{
    // Whne all the elements are sorted
    if(n==1)
        return;
    // this is when we have completed our 1 iteration to entire array
    if(i==n-1)
        return bubble_sort_recurrsion(v,0,n-1);
    
    if(v[i]>v[i+1])
        swap(v[i],v[i+1]);
    // for the next iteration of a particular stage in Bubble_sort
    return bubble_sort_recurrsion(v,i+1,n);

}

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
    bubble_sort_recurrsion(v,0,n);
    fo(i,n)
        cout<<v[i]<<" ";
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