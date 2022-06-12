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
// #define endl "\n"
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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=0;
    vi arr;
    vi num1,num2;

    for(ll i=1;i<=100;i++)
    {
        num1.pb(i);
        num2.pb(i<<7);
    }   
        
    // cin>>t;
    while(t<2)
    {
        cout<<"? ";
        if(t==0)
        for(ll i=0;i<num1.size();i++)
            cout<<num1[i]<<" ";
        else
        {
            for(ll i=0;i<num2.size();i++)
            {
                cout<<num2[i]<<" ";
            }
        }
        cout<<endl;

        ll val;
        cin>>val;
        arr.pb(val);
        t++;
    }
    ll res=0;
    ll val1=arr[0];
    ll val2=arr[1];

    ll i=0;
    while(i<7)
    {
        if(val2&(1<<i))
        {
            res+=1<<i;
        }
        i++;
    }
    while(i<14)
    {
        if(val1&(1<<i))
            res+=1<<i;
            i++;
    }
    cout<<"! "<<res<<endl;

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