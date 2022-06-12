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

ll mx=52*52*52;

ll char_to_int(char ch)
{
    if(ch>='A' && ch<='Z')  return ch-'A';
    return ch-'a'+26;
}

ll map_string_to_int(char ch1,char ch2,char ch3)
{
    return char_to_int(ch1)*52*52 + char_to_int(ch2)*52 + char_to_int(ch3);
}

vector<vi> g(mx);
vi cnt(mx,0);

vi ans(mx,-1);

void solve()
{
    ll n,i;
    cin>>n;
    vector<string> vs(n);
    vector<pii> edges;
    mii hm;
    fo(i,n)
    {
        cin>>vs[i];
        ll sz=vs[i].size();
        pii p={map_string_to_int(vs[i][0],vs[i][1],vs[i][2]),map_string_to_int(vs[i][sz-3],vs[i][sz-2],vs[i][sz-1])};
        cnt[p.first]++;
        debug(p);
        hm[p.first]=1;
        hm[p.second]=1;
        // edges.pb({p.second,p.first});
        edges.pb(p);
        g[p.second].pb(p.first);
    }

    queue<ll> q;
    // debug(ans);
    fo(i,mx)
    {
        if(cnt[i]==0)
        {
            ans[i]=0;
            q.push(i);
        }
    }

    while(!q.empty())
    {
        ll node=q.front();
        q.pop();
        if(hm[node]==1)
        {
            debug(node);
        }

        for(auto nbr:g[node])
        {
            if(ans[nbr]==-1)
            {
                cnt[nbr]--;
                if(ans[node]==0)
                {
                    // ans[nbr]=0;
                    ans[nbr]=1;
                    q.push(nbr);
                }
                else if(cnt[nbr]==0)
                {
                    // ans[nbr]=1;
                    ans[nbr]=0;
                    q.push(nbr);
                }
            }
        }
    }

    // debug(ans);

    fo(i,n)
    {
        if(ans[edges[i].second]==0)
            cout<<"Takahashi";
        else if(ans[edges[i].second]==1)
        {
            cout<<"Aoki";
        }
        else
            cout<<"Draw";
        cout<<endl;
    }


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