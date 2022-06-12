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
#define deb1(x)                cout<<#x<<": "<<x<<endl
#define deb2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define deb3(x, y, z)          cout<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<" : "<<f<<endl
const ll mod = 1e9+7;
#define popcount(x) __builtin_popcount(x)
#define all(x) x.begin(),x.end()
#define mem(a,v) memset(a,v,sizeof(a))
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

void helper(vi &v,vi &ans)
{
    ll i;
    stack<ll> st;
    st.push(0);
    i=1;
    while(i<v.size())
    {
        ll in=st.top();
        while(v[in]<v[i])
        {
            st.pop();
            if(st.empty())
                break;
            in=st.top();
        }
        if(!st.empty())
        {
            ll in=st.top();
            // trace4(in,v[in],i,v[i]);
            if(v[in]==v[i])
            {
                ans[i]=1+ans[in];
            }
        }
        st.push(i);
        i++;
    }

    // while(!st.empty())
    // {
    //     ll in=st.top();
    //     st.pop();
    //     if(!st.empty())
    //     {
    //         ll in2=st.top();
    //         // deb2(in,in2);
    //         // deb2(v[in],v[in2]);
    //         if(v[in]<v[in2])
    //             break;
    //         else if(v[in]==v[in2])
    //             ans[in2]++;
    //         else
    //         {
    //             st.pop();
    //             st.push(in);
    //         }
    //     }
    // }
    // fo(i,v.size())
    //     cout<<ans[i]<<" ";
    // cout<<endl;
}

void solve()
{
    ll n,i;
    cin>>n;
    vi v(n);
    fo(i,n)
        cin>>v[i];

    vi ans(n,0),ans2(n,0);
    // cout<<"First"<<endl;
    helper(v,ans);

    reverse(v.begin(),v.end());
    reverse(ans2.begin(),ans2.end());
    
    // cout<<"2nd"<<endl;
    helper(v,ans2);
    
    reverse(ans2.begin(),ans2.end());
    fo(i,n)
        cout<<ans[i]+ans2[i]<<" ";
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