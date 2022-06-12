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

ll A,B,n;

bool compare(pii &p1,pii &p2)
{
    if(p1.first==p2.first)
        return p1.second<p2.second;
    return p1.first<p2.first;

}

void solve()
{
    ll i;
    cin>>A>>B>>n;
    vi a(n),b(n);
    vector<pii> vp(n);
    fo(i,n)
        cin>>a[i];
    fo(i,n)
    {
        cin>>b[i];
        vp[i]={a[i],b[i]};
    }
    
    ll flag=0;

    fo(i,n)
    {

        ll f1=vp[i].second/A;
        ll f2=B/vp[i].first;
        ll r1=vp[i].second%A;
        ll r2=B%vp[i].first;

        if(r1==0)
            f1--;
        if(r2==0)
            f2--;

        ll mn=min(f1,f2);

        if(mn==f1)
        {
            B-=f1*vp[i].first;
            vp[i]={vp[i].first,vp[i].second-A*f1};
        }
        else
        {
            flag=1;
            break;
        }
    }

    sort(vp.begin(),vp.end(),compare);

    fo(i,n)
    {
        if(i==n-1)
        {

        }
        else
        {
            B-=vp[i].first;
            if(B<=0)
            {
                flag=1;
                break;
            }
        }
    }


    if(flag==1)
        cout<<"NO";
    else
        cout<<"YES";
    cout<<endl;

}

int main()
{
    fastio
    int t;
    cin>>t;
    while(t--)
    {
        solve();   
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