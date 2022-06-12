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

bool compare(string s1,string s2)
{
    return s1.size()<s2.size();
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
        ll n,i;
        cin>>n;
        vector<string> v[n];
        map<string,int> m;
        fo(i,n)
        {
            string x;
            cin>>x;
            map<string,int> temp;
            for(ll j=1;j<=9;j++)
            {
                string val;
                ll cnt=0,k=0;
                for(k;k<j;k++)
                {
                    val+=x[k];
                    cnt++;
                }
                for(;k<9;k++)
                {
                    if(cnt==j)
                    {
                        v[i].pb(val);
                        temp[val]++;
                        val=val.substr(1,j);
                        cnt--;
                    }
                        val+=x[k];
                        cnt++;  
                }
                if(cnt==j)
                {
                    v[i].pb(val);
                    temp[val]++;
                }
            }
            for(auto ele:temp)
            {
                m[ele.first]++;
            }
        }
        fo(i,n)
        {
            string ans;
            sort(v[i].begin(),v[i].end(),compare);
            for(ll j=0;j<v[i].size();j++)
            {
                if(m[v[i][j]]==1)
                {
                    ans=v[i][j];
                    break;
                }
            }
            cout<<ans<<endl;
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