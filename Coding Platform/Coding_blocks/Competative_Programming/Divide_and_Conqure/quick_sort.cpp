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

ll partition(ll *a,ll st,ll ed)
{
    ll i=st-1; // here i denotes the last index of a subarray which consist of elements less than pivot element
    ll j=st;    // here j denotes the first index of a subarray which consist of elements which are greatar then pivot element
    ll pivot=a[ed]; // we always choose last element as pivot and try to put it in it's correct position

    for(j;j<=ed-1;j++) // here we are iterating the larger subarray and checking if there exist any element which is less than pivot  
    {                     // then we will extend i and perform a swaaping operation
        if(a[j]<=pivot)
        {
            i+=1;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[ed]); // at the end we will put pivot at its correct position
    return i+1; // and returns it's index
}

void quick_sort(ll *a,ll st,ll ed)
{
    // base case
    if(st>=ed)
        return;
    // recurrsive case
    ll p=partition(a,st,ed); // we are partitioning our array 
    quick_sort(a,st,p-1); // left one
    quick_sort(a,p+1,ed); // right one
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,i;
    cin>>n;
    ll a[n];
    fo(i,n)
        cin>>a[i];
    quick_sort(a,0,n-1);
    fo(i,n)
        cout<<a[i]<<" ";
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