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

void merge_sort(ll *a,ll st1,ll ed1,ll st2,ll ed2)
{
    ll b[ed2+1],k=0,i=st1;
    while(st1<=ed1 && st2<=ed2)
    {
        if(a[st1]>a[st2])
        {
            b[k++]=a[st2++];
        }
        else
            b[k++]=a[st1++];
    }
    while(st1<=ed1)
        b[k++]=a[st1++];
    while(st2<=ed2)
        b[k++]=a[st2++];
    for(ll j=i;j<=ed2;j++)
        a[j]=b[j-i];
}

void partition(ll *a,ll st,ll ed)
{
    if(st>=ed)
        return;
    ll mid=(st+ed)/2;
    partition(a,st,mid);
    partition(a,mid+1,ed);
    merge_sort(a,st,mid,mid+1,ed);
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
    partition(a,0,n-1);
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