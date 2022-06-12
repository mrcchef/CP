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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll n,d,h;
        cin>>n>>d>>h;
        if(d<h || d>2*h)
        {
            cout<<-1;
            return 0;
        }
        else if(h==1 && d==1 && n>2)
        {
            cout<<-1;
            return 0;
        }
        ll e=n-1,i=0,v1=1,v2,cur_vertex=1;
        vector<pii> vp;
        for(i;i<h;i++)
        {
            cur_vertex++;
            vp.pb({v1,cur_vertex});
            v1=cur_vertex;
        }
        while(i<e)
        {
            v1=1;
            if(d-h==0)
            {
                while(i<e)
                {
                    cur_vertex++;
                    vp.pb({2,cur_vertex});
                    i++;
                }
            }
            else
            {
            
            for(ll j=0;j<d-h && i<e;j++)
            {
                cur_vertex++;
                vp.pb({v1,cur_vertex});
                v1=cur_vertex;
                i++;
            }
                
            }
        }
        for(auto edge:vp)
        {
            cout<<edge.first<<" "<<edge.second<<endl;
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