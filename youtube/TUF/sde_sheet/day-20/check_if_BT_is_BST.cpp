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

    treeNode(ll data)
    {
        data=data;
        left=NULL;
        right=NULL;
    }
};

treeNode* buildTree(treeNode *node,ll data)
{
    if(node==NULL)
    {
        treeNode *temp=new treeNode(data);
        node=temp;
        return node;
    }

    if(data<node->data)
    {
        node->left=buildTree(node->left,data);
    }
    else
    {
        node->right=buildTree(node->right,data);
    }
    return node;
}

ll data;

// THis function checks weather the current tree with root node
// is a valid bst or not
// https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
// for better understanding
bool helper(treeNode *root,ll mn,ll mx)
{
    if(root==NULL)
        return true;
    
    if(root->data<=mn || root->data>=mx)
        return false;
    
    if(root->left!=NULL && root->left->data>=root->data)
    {
        return false;
    }

    if(root->right!=NULL && root->right->data<=root->data)
    {
        return false;
    }

    return (helper(root->left,mn,root->data) && helper(root->right,root->data,mx));
}

// Used the property of inorder traversal i.e inorder traversal of BST is always sorted
bool inorderTraversal(treeNode *root)
{
    stack<treeNode*> st;

    ll prevData=-1e18;
    while(root!=NULL || !st.empty())
    {
        if(root!=NULL)
        {
            st.push(root);
            root=root->left;
        }
        else
        {
            root=st.top();
            st.pop();

            if(root->data<=prevData)
                return false;

            prevData=root->data;
            
            root=root->right;
            
        }
    }

    return true;
}

struct BSTPair{
    bool isBST;
    ll mx;
    ll mn;
};


BSTPair checkIfBTisBST(treeNode *root)
{
    if(root==NULL)
    {
        BSTPair temp;
        temp.isBST=true;
        temp.mn=1e18;
        temp.mx=-1e18;
        return temp;
    }

    BSTPair lf,rt;
    lf=checkIfBTisBST(root->left);
    rt=checkIfBTisBST(root->right);

    BSTPair cur;
    cur.isBST=lf.isBST && rt.isBST && (root->data>lf.mx && root->data<rt.mn);

    cur.mn=min(root->data,min(lf.mn,rt.mn)*1LL);
    cur.mx=max(root->data,max(lf.mx,rt.mx)*1LL);

    return cur;
}


// Timecomplexity of both the algorithms are same i.e. O(n)
//  where n is the number of nodes 
bool isValidBST(treeNode *root)
{
    ll method1=helper(root,-1e18,1e18);
    ll method2=inorderTraversal(root);
    BSTPair method3=checkIfBTisBST(root);
    debug(method1);
    debug(method2);
    debug(method3.isBST);
    return method2;

}

void solve()
{
    vi v={30,15,50,10,20,40,60};
    ll sz=v.size();
    treeNode *root=NULL;
    ll i;
    root=buildTree(root,v[0]);
    Fo(i,1,sz-1)
    {
        buildTree(root,v[i]);
    }
    
    cout<<"Is BT is BST: ";
    
    if(isValidBST(root))
        cout<<"YES";
    else   
        cout<<"NO";
    cout<<endl;
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