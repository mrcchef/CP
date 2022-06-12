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

ll mergeArray(vi &v,vi &temp,ll st,ll mid,ll ed)
{
    ll i=st;
    ll j=mid;
    ll inv=0;
    ll k=st;
    while(i<=mid-1 && j<=ed)
    {
        if(v[i]<=v[j])
        {
            temp[k]=v[i];
            k++;
            i++;
        }
        else
        {
            inv+=mid-i;
            temp[k]=v[j];
            k++;
            j++;
        }
    }

    while(i<=mid-1)
    {
        temp[k++]=v[i++];
    }

    while(j<=ed)
    {
        temp[k++]=v[j++];
    }

    Fo(i,st,ed)
    {
        v[i]=temp[i];
    }
    // debug(inv);
    return inv;
}

ll mergeSort(vi &v,vi &temp,ll st,ll ed)
{
    debug(mp(st,ed))
    if(st>=ed)
    {
        return 0;
    }

    // the reason I have taken the ciel is
    // inorder to not stuck in TLE we need to keep reducing the invterval
    // Floor of a value has a tendency of lesser value than the actual value
    // eg:- floor of 11 is 5 which is less than actual mid 5.5
    // due to which we need to increse mid by one inorder to make sure that every
    // time the interval reduces other wise it may stuck into TLE
    // ed: st=0 ,ed=1 , mid(floor)=0 
    // first interval= st,mid-1 i.e 0 to -1 
    // second interval = mid,ed i.e 0 to 1 
    // and 2nd interval will has not reduced which ultimately leads us to TLE
    // that's why ciel which ensure that 2nd interval will reduce 
    // and first interval we are reducing by subtracting by 1

    // we could also use floor but, in that case 
    // first interval will be = st to mid
    // 2nd interval = mid+1 to ed
    // and according few changes in the implementation

    ll mid=(st+ed+1)/2; 

    // first half st to mid-1
    // 2nd half mid to ed

    ll inv=0;
    debug(mid);
    inv+=mergeSort(v,temp,st,mid-1);
    inv+=mergeSort(v,temp,mid,ed);

    inv+=mergeArray(v,temp,st,mid,ed);
    debug(v);
    debug(inv);
    return inv;
}

ll calInversion(vi &v,ll n)
{
    vi temp(n);
    debug(v);
    return mergeSort(v,temp,0,n-1); 
}

void solve()
{
    ll n,i;
    cin>>n;
    vi v(n);
    fo(i,n)
        cin>>v[i];
    
    ll ans=calInversion(v,n);

    cout<<ans<<endl;
}

int main()
{
    fastio
    #ifdef ONLINE_JUDGE
         freopen("Error.txt", "w", stderr);
    #endif
    int t=1;
    // cin>>t;
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