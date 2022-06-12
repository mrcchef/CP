#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0) ; cout.tie(0);
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
#define popcount(x) __builtin_popcount(x)
#define all(x) x.begin(),x.end()
#define mem(a,v) memset(a,v,sizeof(a))

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
    fastio
    int t;
    cin>>t;
    while(t--)
    {
        ll n,i;
        cin>>n;
        vi b(n),a;
        mii m;
        fo(i,n)
        {
            cin>>b[i];
            m[b[i]]=1;
        }
        Fo(i,1,2*n)
        {
            if(m[i]==0)
            {
                a.pb(i);
            }
        }
        
        ll cntl[n+1]={0},cntr[n+1]={0};
        // cntl[0]=cntr[0]=1;
        ll temp=0;
        ll j=0;
        fo(i,n)
        {
            if(b[i]<a[j])
                cntl[temp++]=1;
            else
            {
                while(j<n && b[i]>a[j])
                {
                    j++;
                }
                if(j==n)
                    break;
                else
                    cntl[temp++]=1;
            }
            j++;            
        }
        for(ll k=0;k<=n;k++)
            cout<<cntl[k]<<" ";
        cout<<endl;
        j=n-1;
        temp=0;
        for(i=n-1;i>=0;i--)
        {
            if(b[i]>a[j])
                cntr[temp++]=1;
            else
            {
                while(j>=0 && b[i]<a[j])
                    j--;
                if(j<0)
                    break;
                else
                {
                    cntr[temp++]=1;
                }
            }
            j--;
        }
        for(ll k=0;k<=n;k++)
            cout<<cntr[k]<<" ";
        cout<<endl;
        ll cnt=0;
        Fo(i,0,n)
        {
            if(cntl[i]==1 && cntr[i]==1)
                cnt++;
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