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

// *** this is a very important condition in this problem 
// let say we have 
// Main Array:- 2 8 4
// Sorted Array:- 2 4 8 
// Now we will cal. gcd(4,8) which is 4 but min element is 2
// we will swap 4 and 2 and then swap 8 and 2 
// Now :- 4 2 8 
// Now if we gcd(4,2)=2, gcd(2,4)=2 and 8 is already in it's correct position 
//  End Result:- We can use minimum element to rearrange the elements such that we can sort the array by swapping

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,i,mn=INT_MAX,flag=0;
        cin>>n;
        ll a[n],b[n];
        // bool check[n]={false};
        fo(i,n)
        {
            cin>>a[i];
            mn=min(mn,a[i]);
            b[i]=a[i];
        }  
        // deb(mn);  
        sort(b,b+n);
        // for(auto x:b)
        //     cout<<x<<" ";
        cout<<endl;
        for(i=0;i<n;i++)
        {
            if(a[i]!=b[i])
            {
                // deb(a[i]);
                // deb(b[i]);
                ll gcd=__gcd(a[i],b[i]);
                // deb(gcd);
                if(gcd%mn==0) // ***
                    continue;
                if(gcd!=mn )
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1)
            cout<<"NO";
        else
            cout<<"YES";
        cout<<endl;

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