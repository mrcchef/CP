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
#define ll int
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
// const ll inf=1e18;
#define popcount(x) __builtin_popcount(x)
#define all(x) x.begin(),x.end()
#define mem(a,v) memset(a,v,sizeof(a))
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))

// debugging code
// ---------------------------------------------------------------------------------------------------------------------------------
// void _print(ll t) {cerr << t;}
// void _print(int t) {cerr << t;}
// void _print(string t) {cerr << t;}
// void _print(char t) {cerr << t;}
// void _print(lld t) {cerr << t;}
// void _print(double t) {cerr << t;}
// void _print(ull t) {cerr << t;}

// template <class T, class V> void _print(pair <T, V> p);
// template <class T> void _print(vector <T> v);
// template <class T> void _print(set <T> v);
// template <class T, class V> void _print(map <T, V> v);
// template <class T> void _print(multiset <T> v);
// template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
// template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// ---------------------------------------------------------------------------------------------------------------------------------

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

void swap(ll &a,ll &b);
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
ll msum(ll a,ll b,ll m);
ll msub(ll a,ll b,ll m);
ll mpro(ll a,ll b,ll m);

struct data{
    string ch;
    ll val;
    data *left,*right;

    data()
    {}

    data(string &_ch,ll _val)
    {
        ch=_ch;
        val=_val;
        left=nullptr;
        right=nullptr;
    }
};

bool insert(data &key,data *root)
{
    data *node=root;
    while(node!=nullptr)
    {
        if(key.ch>node->ch && node->right==nullptr)
        {
            node->right=new data(key.ch,key.val);
            return true;
        }

        if(key.ch<=node->ch && node->left==nullptr)
        {
            node->left=new data(key.ch,key.val);
            return true;
        }

        if(key.ch>node->ch)
        {
            node=node->right;
        }
        else 
        {
            node=node->left;
        }
    }

    return false;
}

string traverse(data *root)
{
    if(root==nullptr)
        return "";
    
    string centre=root->ch+"/"+to_string(root->val);
    string left=traverse(root->left);
    string right=traverse(root->right);
    
    return "("+left+centre+right+")";
}

bool compare(pair<ll,string> &p1,pair<ll,string> &p2)
{
    return p1.first>p2.first;   
}

void solve(ll n)
{
    vector<pair<ll,string>> edge;

    ll i;
    fo(i,n)
    {
        string s;
        cin>>s;

        string label;
        string num;
        ll j=0;

        ll pos=s.find('/');
        label=s.substr(0,pos);
        num=s.substr(pos+1,s.size()-pos);

        edge.pb({stoll(num),label});
    }

    sort(all(edge),compare);

    data *root=new data(edge[0].second,edge[0].first);

    for(i=1;i<n;i++)
    {
        data d=data(edge[i].second,edge[i].first);
        insert(d,root);
    }

    string res=traverse(root);

    cout<<res<<endl;

}

int main()
{
    fastio
    #ifdef ONLINE_JUDGE
         freopen("Error.txt", "w", stderr);
    #endif
    int t=1;
    // cin>>t;
    ll sz;
    cin>>sz;
    while(sz>0)
    {
        solve(sz);
        cin>>sz;   
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