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

bool compare(pii &p1,pii &p2)
{
    if(p1.first==p2.first)
        return p1.second<p2.second;
    else
        return p1.first>p2.first;
}

void solve()
{
    ll n;
    vector<pii> ele(4),dup(4);
    ll u,r,d,l,i;
    cin>>n;
    fo(i,4)
    {
        ele[i].second=i;
        cin>>ele[i].first;   
    }
    mii m;
    sort(ele.begin(),ele.end(),compare);
    fo(i,4)
        dup[i]=ele[i];
    ll flag=0;

    // if(n==2)
    // {

    // }
    // else
    fo(i,4)
    {
        ll val=ele[i].first;
        ll pos=ele[i].second;
        
        ll j,k;
        for(j=0;j<4;j++)
            if(ele[j].second==(pos-1+4)%4)
                break;
        for(k=0;k<4;k++)
            if(ele[k].second==(pos+1)%4)
                break;

        if(val<0)
        {
            flag=1;
            break;
        }

        m[pos]+=val;
        ele[i].first=0;
        if(val==n)
        {
            m[ele[j].second]+=1;
            m[ele[k].second]+=1;
            ele[j].first--;
            ele[k].first--;
        }
        else if(val==n-1)
        {   
            if(ele[j].first<ele[k].first && ele[j].first>0)
            {
                m[ele[j].second]+=1;
                ele[j].first--;
            }
            else
            {
                m[ele[k].second]+=1;
                ele[k].first--;
            }
        }
        // ll te;
        // fo(te,4)
        // {
        //     cout<<ele[te].second<<" "<<ele[te].first<<endl;
        // }
    }

    // if(!flag)
    //     cout<<"YES";
    // else
    //     cout<<"NO";

    fo(i,4)
    {
        ll val=ele[i].first;
        ll pos=ele[i].second;
        
        if(m[pos]!=dup[i].first)
        {
            flag=1;
            break;
        }
    }
    if(!flag)
        cout<<"YES";
    else
        cout<<"NO";
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