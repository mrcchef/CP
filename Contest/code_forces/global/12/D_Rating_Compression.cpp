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
        mii m;
        fo(i,n)
        {
            cin>>v[i];
            m[v[i]]++;
        }

        string ans(n,'0');
        if(m.size()==n)
        {
            ans[0]='1';
        }

        if(m.begin()->first==1)
        {
            ans[n-1]='1';
        }

        ll l=0,r=n-1,val=1,pos=n-2;
        while(l<r)
        {
            m[v[l]]--;
            if(m[v[l]]==0)
                m.erase(v[l]);
            m[v[r]]--;
            if(m[v[r]]==0)
                m.erase(v[r]);
            
            ll mn=m.begin()->first;

            if(v[l]==val && min(mn,v[r])==val+1)
            {
                ans[pos]='1';
                pos--;
                l++;
                val++;
                m[v[r]]++;
            }
            else if(v[r]==val && min(mn,v[l])==val+1)
            {
                ans[pos]='1';
                pos--;
                r--;
                val++;
                m[v[l]]++;
            }
            else 
                break;
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