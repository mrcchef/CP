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

struct node{

    string name;
    int st;
    int byte;
    int isDeleted;

    node(){}

    node(string name,int st,int byte,int isDeleted)
    {
        this->name=name;
        this->st=st;
        this->byte=byte;
        this->isDeleted=isDeleted;
    }
};

void solve()
{
    int n,i;
    cin>>n;
    vector<node> arr(n);
    for(i=0;i<n;i++)
    {
        string name;
        int st;
        string sz;
        int isDeleted;
        int byte;
        cin>>name>>st>>sz>>isDeleted;
        byte=sz[0]-'0';

        if(sz[1]=='m')
            byte*=1e6;

        if(sz[1]=='k')
            byte*=1e3;
        
        node d=node(name,st,byte,isDeleted);
        arr[i]=d;
    } 

    int m;
    cin>>m;

    vector<pair<int,pair<string,int>>> input(m); //<start offset,<name,size>>

    for(i=0;i<m;i++)
    {
        string name;
        string sz;
        cin>>name>>sz;
        int byte=sz[0]-'0';
        if(sz[1]=='m')
            byte*=1e6;

        if(sz[1]=='k')
            byte*=1e3;
    
        input[i]={0,{name,byte}};
    }

    int st=0,ed=0;
    vector<int> avail(m,1);
    set<pair<int,int>> emptySet; //<size,offset>

    for(i=0;i<n;i++)
    {
        if(arr[i].isDeleted==1)
        {
            ed=arr[i].st+arr[i].byte;
        }
        else
        {
            
            if(st<ed)
            {
                int sz=ed-st;

                emptySet.insert({sz,st});
            }
            st=arr[i].st+arr[i].byte;
        }
    }

    if(st<ed)
    {
        int sz=ed-st;
        emptySet.insert({sz,st});
    }


    for(i=0;i<m;i++)
    {
        int sz=input[i].second.second;

        pair<int,int> p={sz,0};
        auto it=lower_bound(emptySet.begin(),emptySet.end(),p);

        if(it!=emptySet.end() && it->first==sz)
        {
            input[i].first=it->second;
            avail[i]=0;
            emptySet.erase(it);
        }
    }

    for(i=0;i<m;i++)
    {
        if(avail[i]==0)
        {
            continue;
        }
        pair<int,int> p={input[i].second.second,0}; // 
        auto it=lower_bound(emptySet.begin(),emptySet.end(),p);

        if(it!=emptySet.end())
        {
            int diff=it->first-p.first;
            input[i].first=it->second;

            emptySet.erase(it);

            emptySet.insert({diff,it->second+p.first});
            avail[i]=0;
        }
    }

    int total=arr[n-1].st+arr[n-1].byte; 

    for(i=0;i<m;i++)
    {
        if(avail[i]==0)
            continue;
        
        input[i].first=total;
        total+=input[i].second.second;
    }


    for(i=0;i<m;i++)
    {
        cout<<input[i].second.first<<" "<<input[i].first<<endl;
    }
}

int main()
{
    fastio
    #ifdef ONLINE_JUDGE
        // freopen("input.txt", "r", stdin); 
        // freopen("output.txt", "w", stdout);
        freopen("error.txt","w",stderr);
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