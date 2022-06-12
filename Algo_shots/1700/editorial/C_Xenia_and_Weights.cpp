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
vi v,res;
ll n;
bool check=false;

void dfs(ll sz,ll prev,ll sum1,ll sum2,ll state)
{
    if(sz==n)
    {
        cout<<"YES"<<endl;
        for(ll val:res)
            cout<<val<<" ";
        check=true;
        exit(0);

    }

    for(ll val:v)
    {
        if(prev==val)
            continue;
        
        if(state==1)
        {
            if(sum1+val>sum2)
            {
                res.pb(val);
                dfs(sz+1,val,sum1+val,sum2,state*-1);
                res.pop_back();
            }
        }
        else
        {
            if(sum2+val>sum1)
            {
                res.pb(val);
                dfs(sz+1,val,sum1,sum2+val,state*-1);
                res.pop_back();
            }
        }
    }

}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        ll i;
        cin>>n;
        // mii m;
        v.clear();
        res.clear();
        fo(i,s.size())
        {
            if(s[i]=='1')
            {
                v.pb(i+1);
            }
        }

        // vi left,right;
        // ll lsum=0,rsum=0,prev=-1,rprev=-1;

        // ll state=1;
        dfs(0,-1,0,0,1);

        
        if(check==false)
        {
            cout<<"NO";
        }
        // else
        // {
        //     cout<<"YES"<<endl;
        //     for(auto val:res)
        //         cout<<val<<" ";
        // }
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