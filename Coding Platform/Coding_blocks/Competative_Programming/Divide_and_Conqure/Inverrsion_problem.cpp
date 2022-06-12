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

// https://www.geeksforgeeks.org/counting-inversions/

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

// used to cal. cross inversions 

ll merge(ll *a,ll st,ll mid,ll ed)
{
    ll b[ed+1],k=0,i=st,j=mid+1;
    ll cnt=0;
    while(i<=mid && j<=ed)
    {
        if(a[i]>a[j])   // if element in 1st array is greater than in second then all the element starting from index i must be greater than 
        {               // all the elements in 2nd array b/c these array are sorted 
            b[k++]=a[j++];
            cnt+=mid-i+1;      // and we add all those pair which satisfy a[i]>a[j] for all i<j 
        }
        else
            b[k++]=a[i++];
    }
    while(i<=mid)
        b[k++]=a[i++];
    while(j<=ed)
        b[k++]=a[j++];
    for(ll j=st;j<=ed;j++)
    {
        a[j]=b[j-st];
    }
    return cnt;
}

ll partition(ll *a,ll st,ll ed)
{
    if(st>=ed)
        return 0;
    ll mid=(st+ed)/2;
    ll x=partition(a,st,mid);  // 1->no. of inversions in array a form st to mid
    ll y=partition(a,mid+1,ed); // 2->no. of inversions in array a from mid+1 to ed
    ll cnt=merge(a,st,mid,ed);  // no. of cross inversion from array 1 and 2
    return x+y+cnt; // total inversions from st to ed explanation is also in a picture and also written in notebook
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
    ll res=partition(a,0,n-1);
    cout<<res<<endl;
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