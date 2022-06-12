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
// https://www.youtube.com/watch?v=kSyQvEykffs

// Good Approach

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
    ll n,i,sz=1e5+1;
    cin>>n;
    ll a[n],f[sz]={0},grp[sz]={0};;
    fo(i,n)
    {
        cin>>a[i];
        f[a[i]]++;
        grp[f[a[i]]]++;
    }
    // for(i=0;i<=8;i++)
    // {
    //     cout<<grp[i]<<" ";
    // }
    // cout<<endl;
    ll q;
    cin>>q;
    while(q--)
    {
        char ch;
        ll x;
        cin>>ch>>x;
        if(ch=='+')
        {
            f[x]++;
            grp[f[x]]++;
        }    
        else
        {
            grp[f[x]]--;
            f[x]--;
            
        }
        // for(i=0;i<=8;i++)
        // {
        //     cout<<grp[i]<<" ";
        // }
        // cout<<endl;
        if(grp[8]>=1 || grp[4]>=2 || (grp[6]>=1 && grp[2]>=2) || (grp[4]>=1 && grp[2]>=3))
            cout<<"YES";
        else
        {
            cout<<"NO";
        }
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