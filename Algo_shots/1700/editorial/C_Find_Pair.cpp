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
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll n,i,k;
        cin>>n>>k;
        vi v(n);
        mii m;
        fo(i,n)
        {
            cin>>v[i];
            m[v[i]]++;
        }
        sort(v.begin(),v.end());
        ll total=0;
        ll fir,wei,sec;
        ll com=0;
        for(auto p:m)
        {
            if(total+p.second*n<k)
            {
               total+=p.second*n;
            }
            else
            {
                fir=p.first; 
                wei=p.second;
                break;
            }
        }
        ll rem=k-total;
        ll tt=0;
        for(auto p:m)
        {
            if(tt+wei*p.second<rem)
                tt+=wei*p.second;
            else
            {
                sec=p.first;
                break;
            }
        }

        cout<<fir<<" "<<sec<<endl;


        
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