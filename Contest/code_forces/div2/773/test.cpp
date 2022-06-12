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

int helper(int n,vector<vector<int>> &links,int src,int des)
{
    vector<vector<int>> g(n+1);

    int sz=links.size(),i;
    for(i=1;i<=sz;i++)
    {
        for(int j=0;j<links[i-1].size();j++)
        {
            int x=i;
            int y=links[i-1][j];
            g[x].pb(y);
            // g[y].pb(x);
        }
    }

    queue<pair<int,int>> q; // {node,cost}
    int mx=1e9;
    vector<int> dist(n+1,mx);


    q.push({src,0});
    dist[src]=0;

    while(!q.empty())
    {
        pair<int,int> p=q.front();
        q.pop();

        int node=p.first;
        int cost=p.second;

        if(cost>dist[node])
            continue;

        for(auto nbr:g[node])
        {
            if(dist[nbr]<cost+1)
                continue;

            dist[nbr]=cost+1;
            q.push({nbr,cost+1});
        }
    }

    return dist[des]==mx?-1:dist[des];
    
}

// int helper2(int n,vector<string> &vs,int k)
// {
//     int i;
//     int cnt=0;

//     for(i=0;i<n;i++)
//     {
//         vec
//     }

//     while(cnt<k)
//     {
        
//     }
// }

struct node{
    string name;
    int age;
    char ch;
    int x,y;

    node(){

    }

    node(string name,int age,char ch,int x,int y)
    {
        this->name=name;
        this->age=age;
        this->ch=ch;
        this->x=x;
        this->y=y;
    }
};

bool compare(node &n1,node &n2)
{
    if(n1.age==n2.age)
    {
        if(n1.ch==n2.ch)
        {
            return n1.name<n2.name;
        }

        return n1.ch=='A';
    }

    return n1.age>n2.age;
}

void helper3(int n,vector<pair<int,int>> &center,int m,vector<node> &arr)
{
    int i;
    int mx=1e9;
    vector<vector<node>> user(n);

    for(i=0;i<m;i++)
    {
        node d=arr[i];
        int mn=mx;
        int in;

        for(int j=0;j<n;j++)
        {
            int dist=abs(d.x-center[j].first)+abs(d.y-center[j].second);

            if(mn>dist)
            {
                mn=dist;
                in=j;
            }
        }

        user[in].push_back(d);
    }

    for(i=0;i<n;i++)
    {
        sort(user[i].begin(),user[i].end(),compare);
    
        if(user[i].size()==0)
        {
            cout<<"Empty Centre";
        }
        for(int j=0;j<user[i].size();j++)
        {
            cout<<user[i][j].name<<" ";
        }
        cout<<endl;
    }
}

    // ll n,i;
    // n=5;
    // int src,des;
    // vector<vector<int>> v(n);
    // vector<int> temp={2,4};
    // v[0]={2,4};
    // v[1]={1};
    // v[2]={1,5};
    // v[3]={2,3};
    // v[4]={5};

    // src=2;
    // des=3;

    // cout<<helper(n,v,src,des)<<endl;
void solve()
{
    int n,i;
    cin>>n;
    vector<pair<int,int>> centre(n);
    for(i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        centre[i]={x,y};
    } 

    int m;
    cin>>m;
    vector<node> arr(m);
    for(i=0;i<m;i++)
    {
        string name;
        int age;
        char ch;
        int x,y;
        cin>>name>>age>>ch>>x>>y;
        node d=node(name,age,ch,x,y);
        arr[i]=d;
    }

    helper3(n,centre,m,arr);

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