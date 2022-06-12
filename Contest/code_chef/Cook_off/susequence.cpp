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

#include <bits/stdc++.h> 
  
using namespace std; 
  
// Function to return the 
// index of the pivot 
ll findPivot(ll arr[], ll low, ll high) 
{ 
    // Base cases 
    if (high < low) 
        return -1; 
    if (high == low) 
        return low; 
  
    ll mid = (low + high) / 2; 
    if (mid < high && arr[mid + 1] < arr[mid])  
    { 
        return mid; 
    } 
  
    // Check if element at (mid - 1) is pivot 
    // Consider the cases like {4, 5, 1, 2, 3} 
    if (mid > low && arr[mid] < arr[mid - 1]) 
    { 
        return mid - 1; 
    } 
  
    // Decide whether we need to go to 
    // the left half or the right half 
    if (arr[low] > arr[mid]) 
    { 
        return findPivot(arr, low, mid - 1); 
    } 
    else 
    { 
        return findPivot(arr, mid + 1, high); 
    } 
} 
  
// Function to check if a given array 
// is sorted rotated or not 
bool isRotated(vi arr,ll l,ll r,ll pivot) 
{ 
    // ll l = 0; 
    // ll r = n - 1; 
    // ll pivot = -1; 
    if (arr[l] > arr[r]) 
    {   
        // To check if the elements to the left 
        // of the pivot are in descending or not 
        // if (l < pivot) 
        // { 
        //     while (pivot > l) 
        //     { 
        //         if (arr[pivot] < arr[pivot - 1]) 
        //         { 
        //             return false; 
        //         } 
        //         pivot--; 
        //     } 
        // } 
  
        // // To check if the elements to the right 
        // // of the pivot are in ascending or not 
        // else { 
        //     pivot++; 
        //     while (pivot < r) { 
        //         if (arr[pivot] > arr[pivot + 1]) { 
        //             return false; 
        //         } 
        //         pivot++; 
        //     } 
        // } 
        ll mx=arr[l],mn=arr[pivot+1];
        for(ll i=l+1;i<=pivot;i++)
        {
            if(arr[l]<arr[l-1])
                return false;
            mx=max(mx,arr[i]);
        }
        ll flag=0,flag1=0;
        for(ll i=pivot+2;i<=r;i++)
        {
            if(arr[pivot]<arr[pivot-1])
            {
                flag=1;
                break;
            }
            mn=min(mn,arr[i]);
        }
        for(ll i=pivot+2;i<=r;i++)
        {
            if(arr[pivot]>arr[pivot-1])
            {
                flag1=1;
                break;
            }
        }
        if(flag==1 && flag1==1)
            return false;
  
        // If any of the above if or else is true 
        // Then the array is sorted rotated 
        return true; 
    } 
    
    // Else the array is not sorted rotated 
    else
    { 

        vi temp=arr;
        sort(temp.begin(),temp.end());
        if(temp==arr)
            return true;

        return false; 
    } 
} 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,i;
        cin>>n;
        vi v;
        fo(i,n)
        {
            ll x;
            cin>>x;
            v.pb(x);
        }
        ll cnt=0,l=1;
        for(l;2*l<=n;l=l*2)
        {
            for(i=0;i<n-l;i+=l)
            {
                
                if(isRotated(v,i,i+2*l-1,l-1))
                {
                    deb(i);
                    deb(i+2*l-1);
                    cnt++;
                    deb(cnt);
                }
            }
        }
        cout<<cnt<<endl;
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