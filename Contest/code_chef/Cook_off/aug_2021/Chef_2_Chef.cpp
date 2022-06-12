//LinkedIn:https://www.linkedin.com/in/abhijeettamrakar/
//GitHub:https://github.com/mrcchef/
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

ll cal(mii &hm,ll sm)
{
    auto it=hm.begin();
    ll ele1=it->first;
    ll ele2;
    if(it->second==1)
    {
        it++;
        ele2=it->first;
    }
    else
        ele2=it->first;

    ll tans=sm+ele1+ele2;
    return tans;
}

void solve()
{
    ll n,i;
    cin>>n;
    vi v(n+1);
    fo(i,n)
        cin>>v[i+1];
    
    mii hm;
    // debug(n);
    ll ans=0;
    ll sm=v[1]+v[2];
    // hm[-v[1]]++;
    // hm[-v[2]]++;
    // // debug(hm);
    // ll j=0;
    // Fo(i,2,n-1)
    // {
    //     sm+=v[i];
    //     hm[-v[i]]++;
        
    //     ll tans=cal(hm,sm);
    //     ans=max(ans,tans);
    //     while(tans<0 && i-j+1>2 )
    //     {
    //         hm[-v[j]]--;
    //         sm-=v[j];
    //         if(hm[-v[j]]==0)
    //             hm.erase(-v[j]);

    //         tans=cal(hm,sm); 
    //         ans=max(ans,tans);
    //         j++;  
    //     }

    //     debug(i-j+1);
    // }

    // while(i-j>2)
    // {
    //     hm[-v[j]]--;
    //     sm-=v[j];
    //     if(hm[-v[j]]==0)
    //         hm.erase(-v[j]);
    //     ll tans=cal(hm,sm); 
    //     ans=max(ans,tans);
    //     j++;  
    // }

    
    vi pref(n+1,0);
    vi suff(n+2,0);

    sm=0;
    pref[1]=v[1];
    Fo(i,2,n)
        pref[i]=min(pref[i-1],v[i]),sm+=v[i],hm[-v[i]]++;
    
    suff[n]=v[n];
    for(i=n-1;i>=1;i--)
        suff[i]=min(suff[i+1],v[i]);
    
    debug(pref);
    debug(suff);
    i=1;
    ll j=n;
    
    
    while(j-i+1>2)
    {
        
        debug(mp(i,j));
        ll lf=pref[i];
        ll rt=suff[j];
        while(j-i+1>2 && pref[i]>=lf)
        {
            sm-=v[i];
            hm[-v[i]]--;
            if(hm[-v[i]]==0)
                hm.erase(-v[i]);

            ll tans=cal(hm,sm);
            ans=max(ans,tans);
            i++;
        }
        debug(i);
        while(j-i+1>2 && suff[j]>=rt)
        {
            sm-=v[j];
            hm[-v[j]]--;
            if(hm[-v[j]]==0)
                hm.erase(-v[j]);

            ll tans=cal(hm,sm);
            ans=max(ans,tans);
            j--;
        }
        debug(j);
    }

    cout<<ans<<endl;
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
        return fxp((a*a)%m,b/2,m);
    return (fxp(a,b-1,m)*a)%m;
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