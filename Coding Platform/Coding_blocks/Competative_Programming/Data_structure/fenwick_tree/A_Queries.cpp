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

class fenwick{
    public:
        int n;
        vi fen;

        fenwick(int node)
        {
            n=node;
            fen.assign(node+1,0);
        }

        void update(ll in,ll val)
        {
            ll i=in;
            while(i<=n)
            {
                fen[i]+=val;
                i=i+(i&(-i));
            }
        }

        ll add(ll in)
        {
            ll i=in;
            ll sm=0;
            while(i>=1)
            {
                sm+=fen[i];
                i=i-(i&(-i));
            }
            return sm;
        }

        ll rsum(ll l,ll r)
        {
            return add(r)-add(l-1);
        }

        ll find(ll sm)
        {
            ll cur=0;
            ll prevsum=0;

            for(ll i=log2(sm);i>=0;i--)
            {
                if(cur+(1LL<<i)<=n && prevsum+fen[cur+(1LL<<i)]<sm)
                {
                    cur=cur+(1LL<<i);
                    prevsum+=fen[cur];
                }
            }

            return cur;
        }
};

void solve()
{
    ll n,m,i;
    cin>>n>>m;
    vi v(n+1);
    vector<fenwick> fn(m,fenwick(n));
    
    fenwick Fn(n);

    fo(i,n)
    {
        cin>>v[i+1];
        Fn.update(i+1,v[i+1]);

        ll val=Fn.rsum(i+1,i+1);

        if(val<m)
        {
            fn[val].update(i+1,1);
        }
    }

    ll q;
    cin>>q;

    fo(i,q)
    {
        char ch;
        cin>>ch;
        if(ch=='s')
        {
            ll lf,rt,md;
            cin>>lf>>rt>>md;
            // in=value after modulos
            ll in=md%m;
            // ans will return the count of number of value in present in the range lf to rt
            ll ans=fn[in].rsum(lf,rt);
            // their value will be ans*in
            ans*=in;
            cout<<ans;
        }
        else
        {
            ll in,val;
            cin>>in>>val;

            // number at index in before query
            ll prevnum=Fn.rsum(in,in);

            // if num is less than m then decresing it's count from corresponding tree 
            if(prevnum<m)
            {
                fn[prevnum].update(in,-1);
            }

            // perform query
            if(ch=='+')
            {
                Fn.update(in,val);
            }
            else
            {
                // if number is less than the current value then we'll not perfrom the query
                if(prevnum-val>=0)
                    Fn.update(in,-val);
            }
            
            // number at index in after permoring query
            ll num=Fn.rsum(in,in);

            // if num is less than m, increase it's count at correspoding tree
            if(num<m)
            {
                fn[num].update(in,1);
            }
            // current number at index in
            cout<<num;
        }
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