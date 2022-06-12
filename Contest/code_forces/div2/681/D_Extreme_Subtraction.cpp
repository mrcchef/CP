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
        {
            cin>>v[i];
        }
        ll val=v[0],check=0,prev;
        v[0]=0;
        Fo(i,1,n-1)
        {
            if(check==1)
            {
                if(v[i]<v[i-1])
                    break;
                else if(v[i]-val>=v[i-1])
                {
                    v[i]-=val;
                }
                else
                {
                    val=v[i]-v[i-1];
                    v[i]=v[i-1];
                }
                
            }
            else if(v[i]<=val)
            {
                val=v[i];
                v[i]=0;
            }
            else
            {
                v[i]-=val;
                check=1;
            }    
        }
        val=v[n-1];
        v[n-1]=0;
        ll flag=0;
        for(i=n-2;i>=0;i--)
        {
            if(v[i]<=val)
            {
                val=v[i];
                v[i]=0;
            }
            else
            {
                v[i]-=val;
            }
        }
        fo(i,n)
        {
            if(v[i]!=0)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            cout<<"NO";
        }
        else
        {
            cout<<"YES";
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