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

bool check(ll rem,vi &v,ll cur)
{
    for(auto val:v)
        if(val<=cur)
            return true;
    return false;
}


int main()
{
    fastio
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k,i;
        cin>>n>>k;
        vi v(n);
        fo(i,n)
            cin>>v[i];
        
        mii m;
        map<ll,vi> mvv;
        ll val=0;
        // vi temp;
        fo(i,10)
        {
            val+=k;
            ll rem=val%10;
            m[rem]++;
            // temp.pb(val);
            mvv[rem].pb(val);
        }

        for(auto it:mvv)
            sort(it.second.begin(),it.second.end());

        fo(i,n)
        {
            ll rem=v[i]%10;
            vi val=mvv[rem];
            if(v[i]>=10*k)
                cout<<"YES"<<endl;
            else
            {
            if(m[rem]>0)
            {
                bool flag=check(rem,val,v[i]);
                if(flag)
                    cout<<"YES"<<endl;
                else
                {
                    cout<<"NO"<<endl;
                }   
            }
            else
            {
                cout<<"NO"<<endl;
            }
                
            }
            
            
        }
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