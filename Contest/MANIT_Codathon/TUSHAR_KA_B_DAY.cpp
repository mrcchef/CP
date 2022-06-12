#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<=n;i++)
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

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

int countEvenSum(vi &arr, int n) 
{ 
	// A temporary array of size 2. temp[0] is 
	// going to store count of even subarrays 
	// and temp[1] count of odd. 
	// temp[0] is initialized as 1 because there 
	// a single even element is also counted as 
	// a subarray 
	int temp[2] = {1, 0}; 

	// Initialize count. sum is sum of elements 
	// under modulo 2 and ending with arr[i]. 
	int result = 0, sum = 0; 

	// i'th iteration computes sum of arr[0..i] 
	// under modulo 2 and increments even/odd count 
	// according to sum's value 
	for (int i=0; i<=n-1; i++) 
	{ 
		// 2 is added to handle negative numbers 
		sum = ( (sum + arr[i]) % 2 + 2) % 2; 

		// Increment even/odd count 
		temp[sum]++; 
	} 

	// Use handshake lemma to count even subarrays 
	// (Note that an even cam be formed by two even 
	// or two odd) 
	result = result + (temp[0]*(temp[0]-1)/2); 
	result = result + (temp[1]*(temp[1]-1)/2); 

	return (result); 
} 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,i;
        cin>>n;
        vi v(n);
        fo(i,n)
            cin>>v[i];
        ll even=0,odd=0;
        ll xr=0;
        ll cnt=0;
        fo(i,n)
        {
            xr^=v[i];
            ll val=0;
            if(xr&1)
            {
                val=odd;
                odd++;
            }
            else
            {
                even++;
                val=even;
            }
            cnt+=val;
        }

        // ll ans=countEvenSum(v,n);
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