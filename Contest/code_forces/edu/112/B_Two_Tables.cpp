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

void solve()
{
    ll W,H;
    cin>>W>>H;

    ll x1,x2,y1,y2;
    cin>>x1>>y1;
    cin>>x2>>y2;

    ll h,w;
    cin>>w>>h;

    ll hf=abs(y1-y2);
    ll wf=abs(x1-x2);

    if(h>H-hf && w>W-wf)
    {
        cout<<-1<<endl;
        return;
    }

    ll uph=H-y2;
    ll dnh=y1;

    ll lfw=x1;
    ll rtw=W-x2;

    debug(mp(hf,wf));
    ll dis=0;
    debug(mp(uph,dnh));
    debug(mp(lfw,rtw));
    debug(mp(h,w));
    if(h<=uph)
    {
        dis=0;
        // if(w<=lfw)
        // {
        //     dis=0;
        // }
        // else if(w<=rtw)
        // {
        //     dis=0;
        // }
        // else
        // {
        //     dis=min(w-lfw,w-rtw);
        // }
    }
    else if(h<=dnh)
    {
        dis=0;
        // if(w<=lfw)
        // {
        //     dis=0;
        // }
        // else if(w<=rtw)
        // {
        //     dis=0;
        // }
        // else
        // {
        //     dis=min(w-lfw,w-rtw);
        // }
    }   
    else
    {
        

        if(w<=lfw)
        {
            dis=0;
        }
        else if(w<=rtw)
        {
            dis=0;
        }
        else
        {
            
            dis=min(h-uph+w-rtw,h-uph+w-lfw);
            ll val=min(h-dnh+w-rtw,h-dnh+w-lfw);
            dis=Min(dis,h-dnh+w-lfw,h-uph+w-lfw);
            dis=Min(dis,h-uph+w-rtw,h-dnh+w-rtw);
            dis=min(dis,val);
            if(h<=uph+dnh)
            {
                dis=Min(dis,h-uph,h-dnh);

            }
            else
            {
                if(w<=lfw+rtw)
                {
                    dis=Min(dis,w-lfw,w-rtw);
                }
                else
                {
                    dis=-1;
                }
            }

            // debug("in");
            // dis=min(h-uph,h-dnh);
            // if()
            // dis=Min(dis,w-lfw,w-rtw);
            // dis+=min(w-lfw,w-rtw);
        }

    }


    cout<<dis<<endl;

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