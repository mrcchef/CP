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

//Good Problem of Binary Search

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,c,i;
        cin>>n>>c;
        vi v;
        fo(i,n)
        {
            ll x;
            cin>>x;
            v.pb(x);
        }       
        sort(v.begin(),v.end());
        ll l=0,h=v[n-1]-v[0],mid,ans=INT_MIN;
        // search space is the distance b/w the two indexes where cows are palced
         // we should start from 0 b/c first cow has to be placed at very first index
        // Here our search space is the range from 0 to the max. possible distance 
        // WIth the help of binary search we can check of the mid
        while(l<=h)
        {
            ll cnt=c-1,j=0;
            mid=(l+h)/2;
            // deb(mid);
            for(i=1;i<n;i++)
            {
                ll dif=v[i]-v[j];
                if(dif>=mid)
                {
                    cnt--;
                    j=i;
                }
                if(cnt==0)  // if we can place with that mid distance then we can check for bigger range
                {
                    ans=max(ans,mid);
                    l=mid+1;    // so our new search space is from [mid+1,h]
                    break;
                }
            }
            if(cnt!=0)  // if not possible then
            {
                h=mid-1;    // reduce our search space i.e. [l,mid-1]
            }
        }
        cout<<ans<<endl;
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