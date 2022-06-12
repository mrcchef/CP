#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0) ; cout.tie(0);

#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
    #define debug(x);
#endif
 
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<=n;i++)
#define ll long long
#define ull unsigned long long
#define lld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define endl "\n"
const ll MOD = 1e9+7;
const ll MOD1= 998244353;
const ll inf=1e18;
#define popcount(x) __builtin_popcount(x)
#define all(x) x.begin(),x.end()
#define mem(a,v) memset(a,v,sizeof(a))
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))

// debugging code
// ---------------------------------------------------------------------------------------------------------------------------------
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// ---------------------------------------------------------------------------------------------------------------------------------

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

void swap(ll &a,ll &b);
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
ll msum(ll a,ll b,ll m);
ll msub(ll a,ll b,ll m);
ll mpro(ll a,ll b,ll m);


ll helper(vi &v,ll n,ll key,mii &index,vi &tmp)
{
    // v has 1 based indexing
    ll st=1,ed=n;
    ll swaps=0;

    vi midPos;
    ll lf=0;
    ll rt=0;

    // s=no. of elements smaller than key
    ll s=lower_bound(all(tmp),key)-tmp.begin()-1; //

    // g=no. of elements greater than key
    ll g=n-s-1;

    // cout<<"s:"<<s<<endl;
    // cout<<"g:"<<g<<endl;

    while(st<=ed)
    {
        ll mid=((ed-st)/2)+st;
        
        // if mid is greater than required index then
        // we need to reduce mid by reducing the range
        // inorder to move left, element at position mid 
        // should be greater than the element x
        
        // so number of elements that are available and greater than x are reduced by 1
        // same goes with the opposite case
        if(mid>index[key])
        {
            ed=mid-1;
            g--;

            if(v[mid]<key)
                lf++;
        }
        else if(mid<index[key])
        {
            st=mid+1;
            s--;

            if(v[mid]>key)
                rt++;
        }
        else
            break;
    }

    // if we do not have enough elements to swap than it's not possible
    // to search the key element
    if(g<0 || s<0)
        return -1;

    // swaps is the maximum of both of them b/c we can 
    // diff=abs(rt-lf) can be solved by swapping 
    // remaning can be swaps with other avaialble elements
    swaps=max(lf,rt);

    return swaps;
}

void solve()
{
    ll n,q;
    cin>>n>>q;
    vi v(n+1);
    ll i;
    mii hm;
    v[0]=-inf;
    fo(i,n)
    {
        cin>>v[i+1];
        hm[v[i+1]]=i+1;
    }
    
    vi tmp=v;

    sort(all(tmp));

    fo(i,q)
    {
        ll x;
        cin>>x;
        ll ans=helper(v,n,x,hm,tmp);
        cout<<ans<<endl;
    }

}

int main()
{
    fastio
    #ifdef ONLINE_JUDGE
         freopen("Error.txt", "w", stderr);
    #endif
    int t=1;
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
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}
ll msum(ll a,ll b,ll m) { return ((a%m+b%m)+m)%m; }
ll msub(ll a,ll b,ll m) { return ((a%m-b%m)+m)%m; }
ll mpro(ll a,ll b,ll m) { return (((a%m)*(b%m)+m))%m; }