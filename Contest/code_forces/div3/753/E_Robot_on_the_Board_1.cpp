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

ll isGood(ll x,ll y,ll n,ll m)
{
    if(x<1)
        return 1;
    else if(x>n)
        return 2;
    else if(y<1)
        return 3;
    else if(y>m)
        return 4;
    else 
        return 0;
}

void solve()
{
    ll n,m,i;
    cin>>n>>m;
    string s;
    debug(mp(n,m));
    cin>>s;
    ll len=s.size();
    ll mxx=1,mxy=1,mnx=1,mny=1;

    ll posx=1,posy=1;
    ll ansx=1,ansy=1;
    fo(i,len)
    {
        debug(s[i]);
        debug(mp(posx,posy));
        debug(mp(mnx,mxx));
        debug(mp(mny,mxy));
        if(s[i]=='L')
        {
            ll npx=posx;
            ll npy=posy-1;
            ll val=isGood(npx,npy,n,m);
            debug(val);
            if(val==3)
            {
                if(mxy+1<=m)
                {
                    ansy+=1;
                    mxy+=1;
                    npy=posy;
                }
                else
                    break;
            }
            
            posx=npx;
            posy=npy;
            mny=min(mny,posy);

        }
        else if(s[i]=='R')
        {
            ll npx=posx;
            ll npy=posy+1;
            ll val=isGood(npx,npy,n,m);

            if(val==4)
            {
                if(mny-1>=1)
                {
                    ansy-=1;
                    mny-=1;
                    npy=posy;
                }
                else
                    break;
            }
            
            posx=npx;
            posy=npy;
            mxy=max(mxy,posy);
            
        }
        else if(s[i]=='U')
        {
            ll npx=posx-1;
            ll npy=posy;
            ll val=isGood(npx,npy,n,m);

            if(val==1)
            {
                if(mxx+1<=n)
                {
                    ansx+=1;
                    mxx+=1;
                    npx=posx;
                }
                else
                    break;
            }
            
            posx=npx;
            posy=npy;
            mnx=min(mnx,posx);
        }
        else 
        {
            ll npx=posx+1;
            ll npy=posy;
            ll val=isGood(npx,npy,n,m);

            if(val==2)
            {
                if(mnx-1>=1)
                {
                    ansx-=1;
                    mnx-=1;
                    npx=posx;
                }
                else
                    break;
            }
            
            posx=npx;
            posy=npy;
            mxx=max(mxx,posx);
        }

        debug(mp(posx,posy));
        debug(mp(ansx,ansy));
        
    }

    cout<<ansx<<" "<<ansy<<endl;
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