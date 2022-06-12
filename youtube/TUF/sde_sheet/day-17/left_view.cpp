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


struct tree{
    ll data;
    tree* left;
    tree* right;

};

tree* buildTree(tree *node,ll val)
{
    if(node==NULL)
    {
        tree *temp=new tree;
        temp->data=val;
        temp->left=temp->right=NULL;
        node=temp;
        // debug(val);
        return node;
    }

    if(val<node->data)
    {
        node->left=buildTree(node->left,val);
    }
    else
    {
        node->right=buildTree(node->right,val);
    }
    return node;
}

// here we need to print the first node of the height
// In case of right_view we need to print the last node of the height
// We have used modified Preorder traversal
unordered_map<ll,ll> hm;
void left_view(tree *root,ll height)
{
    if(root==NULL)
        return;

    if(hm.find(height)==hm.end())
    {
        cout<<root->data<<" ";
        hm[height]=1;
    }

    left_view(root->left,height+1);
    left_view(root->right,height+1);
}

// Time Complexity : O(N)
void left_view(tree *root,ll height,vi &leftView)
{
    if(root==NULL)
        return;

    if(leftView.size()==height)
    {
        leftView.pb(root->data);
    }
    
    left_view(root->left,height+1,leftView);
    left_view(root->right,height+1,leftView);
}

void solve()
{
    // vi v={30,15,50,10,20,40,60};
    vi v={3,2,1,4,5,6,7};
    ll sz=v.size();
    tree *root=NULL;
    ll i;
    root=buildTree(root,v[0]);
    Fo(i,1,sz-1)
    {
        buildTree(root,v[i]);
    }

    cout<<"Left View Traversal"<<endl;
    left_view(root,0);

    vi leftView;
    left_view(root,0,leftView);

    debug(leftView);

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