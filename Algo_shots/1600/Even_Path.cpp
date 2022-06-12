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

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

int re[1000005]={0},ro[1000005]={0},ce[1000005]={0},co[1000005]={0};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll n,q,i;
        cin>>n>>q;
        
        vi R,C;
        fo(i,n)
        {
            ll x;
            cin>>x;
            R.pb(x);
            ro[i+1]=ro[i];
            re[i+1]=re[i];
            if(x&1)
            {
                ro[i+1]++;
            }
            else
            {
                re[i+1]++;
            }
        }
        fo(i,n)
        {
            ll x;
            cin>>x;
            C.pb(x);
            ce[i+1]=ce[i];
            co[i+1]=co[i];
            if(x&1)
            {
                co[i+1]++;
            }
            else
            {
                ce[i+1]++;
            }
        }
        fo(i,q)
        {
            ll ra,rb,ca,cb;
            cin>>ra>>ca>>rb>>cb;
            if((R[ra-1]%2==0) && (R[rb-1]%2==0) && (C[ca-1]%2==0) && (C[cb-1]%2==0))
            {
                // cout<<"chek"<<endl;
                // deb(abs(ra-rb));
                // deb(abs(re[ra]-re[rb-1]));
                if((abs(ra-rb)==abs(re[ra]-re[rb])) && (abs(ca-cb)==abs(ce[ca]-ce[cb])))
                    cout<<"YES";
                else
                {
                    cout<<"NO";
                }
                
            }
            else if((R[ra-1]%2==1) && (R[rb-1]%2==1) && (C[ca-1]%2==1) && (C[cb-1]%2==1))
            {
                // cout<<"check"<<endl;
                if((abs(ra-rb)==abs(ro[ra]-ro[rb])) && (abs(ca-cb)==abs(co[ca]-co[cb])))
                    cout<<"YES";
                else
                {
                    cout<<"NO";
                }
            }
            else
            {
                cout<<"NO";
            }
            cout<<endl;
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