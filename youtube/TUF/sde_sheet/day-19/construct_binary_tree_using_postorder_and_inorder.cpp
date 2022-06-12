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


struct treeNode{
    ll data;
    treeNode* left;
    treeNode* right;

    treeNode(ll val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

//Similar to preorder just few modifications
// 1-> postOrderIndex will start from size()-1
// 2-> first we will move to right child then to left 
int searchNode(vector<int> &inorder,int val,int start,int end)
{
    ll pos;

    for(pos=start;pos<=end;pos++)
        if(inorder[pos]==val)
            return pos;
    
    // return pos;
}

treeNode* buildTree(vector<int> &inorder,vector<int> &postorder,int start,int end,unordered_map<int,int> &hm)
{
    if(start>end)
        return NULL;

    static int postorderIndex=postorder.size()-1;
   
    treeNode* node=new treeNode(postorder[postorderIndex]);
    postorderIndex--;
    if(start==end)
    {
        return node;
    }

    int pos=hm[node->data];
    // int pos=searchNode(inorder,node->data,start,end);
   
    node->right=buildTree(inorder,postorder,pos+1,end,hm);
    node->left=buildTree(inorder,postorder,start,pos-1,hm);

    return node;
}

void postOrder(treeNode* root)
{
    if(root==NULL)
        return;
    
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}


void solve()
{
    vector<int> postorder={10,20,15,40,60,50,30};
    vector<int> inorder={10,15,20,30,40,50,60};
    ll sz=postorder.size();
    treeNode *root=NULL;
    ll i;
    unordered_map<int,int> hm;
    for(i=0;i<sz;i++)
        hm[inorder[i]]=i;
    root=buildTree(inorder,postorder,0,sz-1,hm);

    cout<<"Preorder Traversal of built Tree Through inorder and preoder traversal"<<endl;
    postOrder(root);
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