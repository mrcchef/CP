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

void calPref(vi &v,vi &prev)
{
    ll i;
    Fo(i,1,v.size())
    {
        prev[i]=prev[i-1]+v[i-1];
        // debug(v[i-1])
    }
}

void solve()
{
    ll n,m,k,i;
    cin>>n>>m>>k;

    vi both,alice,bob,noOne;

    fo(i,n)
    {
        ll val,a,b;
        cin>>val>>a>>b;
        if(a==1 && b==1)
        {
            both.pb(val);
        }
        else if(a==1)
        {
            alice.pb(val);
        }
        else if(b==1)
            bob.pb(val);
        else
        {
            noOne.pb(val);
        }
    }

    // if(alice.size()>0)
        sort(all(alice));
    // if(bob.size()>0)
        sort(all(bob));
    // if(both.size()>0)
        sort(all(both));

        sort(all(noOne));

    vi prefAlice(alice.size()+1,0);
    vi prefBob(bob.size()+1,0);
    vi prefBoth(both.size()+1,0);
    vi prefnoOne(noOne.size()+1,0);

    ll asz=alice.size();
    ll bsz=bob.size();
    ll sz=both.size();
    ll nsz=noOne.size();

    // calPref(alice,prefAlice);
    // calPref(bob,prefBob);
    calPref(noOne,prefnoOne);


    Fo(i,1,alice.size())
    {
        prefAlice[i]=prefAlice[i-1]+alice[i-1];
        // debug(v[i-1])
    }

    Fo(i,1,bob.size())
    {
        prefBob[i]=prefBob[i-1]+bob[i-1];
        // debug(v[i-1])
    }

    Fo(i,1,both.size())
    {
        prefBoth[i]=prefBoth[i-1]+both[i-1];
        // debug(v[i-1])
    }

    // debug(alice)
    // debug(bob)
    // debug(both)

    // debug(prefAlice)
    // debug(prefBob)
    // debug(prefBoth)
    ll ans=inf;

    // debug(alice.size()*1ll)
    // debug(bob.size()*1ll)

    // if(k>)

    debug(prefnoOne);

    Fo(i,0,sz)
    {
        ll rem=k-i;
        ll tval=inf;
        ll tcnt=m-k;
    
        // debug(i)
        // debug(rem)
        // debug(asz)
        // debug(bsz)
        if(rem<=asz && rem<=bsz && rem>=0 && noOne.size()>=tcnt)
        {
            tval=prefBoth[i]+prefAlice[rem]+prefBob[rem]+prefnoOne[tcnt];
            // debug(tval)
            // debug(rem)
        }

        ans=min(ans,tval);
    }   

    if(ans==inf)
        ans=-1;
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