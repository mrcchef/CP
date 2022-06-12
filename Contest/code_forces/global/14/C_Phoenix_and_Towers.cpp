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


class data{
    public:
    ll val;
    ll index;
    ll grpIndex;  
};

struct compare
{
    bool operator()(data &d1,data &d2)
    {
        return d1.val<d2.val;
    }  
};

void solve()
{
    ll n,m,x,i;
    cin>>n>>m>>x;
    vector<pii> v(n);
    fo(i,n)
    {
        ll ele;
        cin>>ele;
        v[i]={ele,i+1};
    }
    
    sort(all(v));

    multiset<pair<ll,pii>> st; //<ele,<index,grpIndex>>
    
    ll res[n+1];

    fo(i,m)
    {
        pair<ll,pii> tmp;
        
        tmp.first=v[i].first;
        tmp.second.first=v[i].second;
        tmp.second.second=i+1;
        res[v[i].second]=tmp.second.second;

        st.insert(tmp);
    }
    
    ll flag=0;

    if(m==1)
    {
        for(i;i<n;i++)
            res[v[i].second]=1;
    }
    else
    for(i;i<n;i++)
    {
        pair<ll,pii> mn=*st.begin();
        st.erase(st.begin());
        ll newEle=mn.first+v[i].first;
        ll mx=st.rbegin()->first;
        if(abs(mx-newEle)>x)
        {
            flag=1;
            break;
        }
        mn.first=newEle;
        mn.second.first=i+1;
        res[v[i].second]=mn.second.second;
        st.insert(mn);
    }

    if(flag)
        cout<<"NO";
    else
    {
        // for(auto val:st)
        //     cout<<val.first<<" "<<val.second.first<<" "<<val.second.second<<endl;
        cout<<"YES"<<endl;
        Fo(i,1,n)
            cout<<res[i]<<" ";
    }
    cout<<endl;

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