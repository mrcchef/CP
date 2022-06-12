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

// This is a modified DSU which has more functionalities than normal 
// Queries that this code covers
// 1) checking two nodes are friends or not i.e. are they belong to the same set
// 2) checking two nodes are enemies ot not i.e. they can not belong to the same set
// 3) merging two friends i.e. mergeing two sets
// 4) merging two enemies set i.e. mergeing two sets in which elements can not belong
//   to the same set (can never be friends)

// basically here we are also learning to manages nodes whhich should never be merged

class DSU{
    public:
    ll n;
    vi parent;
    vi rank;
    
    DSU(ll n)
    {
        this->n=n;
        parent=vi(2*n+1,-1);
        // To distinguish friends of node i 
        // index from 1 to n represet friend parent node of every node i
        // index from n+1 to 2*n+1 represent enemy parent of every node i
        rank=vi(2*n+1,1);
    }

    ll getParent(ll node)
    {
        if(parent[node]==-1)
            return node;
        return parent[node]=getParent(parent[node]);
    }

    bool isCyclePresent(ll node1,ll node2)
    {
        ll par1=getParent(node1);
        ll par2=getParent(node2);

        return par1==par2;
    }

    void mergeSet(ll node1,ll node2)
    {
        ll par1=getParent(node1);
        ll par2=getParent(node2);

        if(par1==par2)
            return;
        
        if(rank[par1]<rank[par2])
        {
            parent[par1]=par2;
            rank[par2]+=rank[par1];
        }
        else
        {
            parent[par2]=par1;
            rank[par1]+=rank[par2];
        }
    }


    bool areFriends(ll node1,ll node2)
    {
        // if the nodes belong to the same parent
        return getParent(node1)==getParent(node2);
    }

    bool areEnemies(ll node1,ll node2)
    {
        // conditions to be enemy
        // friend of enemy of node2 will be enemy of node1 and vive versa
        return ((getParent(node1)==getParent(node2+n)) || (getParent(node1+n)==getParent(node2)));
    }

    void mergeFriends(ll node1,ll node2)
    {
        // merge friends of node1 and node2 
        mergeSet(node1,node2);
        // as well as enemy of node1 and node2
        mergeSet(node1+n,node2+n);
    }

    void mergeEnemies(ll node1,ll node2)
    {
        // We need to merge node1 with all the enemy friends of node2
        // and vice versa
        mergeSet(node1,node2+n);
        mergeSet(node1+n,node2);
    }
};

void solve()
{
    ll n,m,q;
    cin>>n>>m>>q;

    ll i;
    vector<string> vs(n);
    map<string,ll> hm;
    fo(i,n)
    {
        cin>>vs[i];
        hm[vs[i]]=i+1;
    }

    DSU dsu(n);
    // debug(dsu.parent);
    fo(i,m)
    {
        ll type;
        cin>>type;
        string s1;
        string s2;
        cin>>s1>>s2;

        ll node1=hm[s1];
        ll node2=hm[s2];

        if(type==1)
        {
            if(dsu.areEnemies(node1,node2))
            {
                cout<<"NO"<<endl;
            }
            else
            {
                dsu.mergeFriends(node1,node2);
                cout<<"YES"<<endl;
            }
        }
        else
        {
            if(dsu.areFriends(node1,node2))
            {
                cout<<"NO"<<endl;
            }
            else
            {
                dsu.mergeEnemies(node1,node2);
                cout<<"YES"<<endl;
            }
        }
        // debug(dsu.parent);
    }


    fo(i,q)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        
        ll node1=hm[s1];
        ll node2=hm[s2];

        if(dsu.areFriends(node1,node2))
        {
            cout<<1<<endl;
            continue;
        }        

        if(dsu.areEnemies(node1,node2))
        {
            cout<<2<<endl;
            continue;
        }   

        cout<<3<<endl;
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
