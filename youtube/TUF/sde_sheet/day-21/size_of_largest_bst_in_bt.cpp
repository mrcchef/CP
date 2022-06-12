
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

pair<int,bool> helper(treeNode* root,ll mn,ll mx,ll &maxSize)
{
    if(root==NULL)
        return {0,true};
    
    if(root->data<=mn || root->data>=mx)
        return {0,false};
    
    pair<int,bool> leftPair=helper(root->left,mn,root->data,maxSize);
    pair<int,bool> rightPair=helper(root->right,root->data,mx,maxSize);



    if(!leftPair.second || !rightPair.second)
        return {0,false};
    
    ll BSTSize=1+leftPair.first+rightPair.first;

    maxSize=max(maxSize,BSTSize);

    return {BSTSize,true};

}

ll largestBSTInBT(treeNode* root)
{
    ll mn=INT_MIN;
    ll mx=INT_MAX;
    stack<treeNode*> st;

    ll maxSize=0;

    while(root!=NULL || !st.empty())
    {
        if(root!=NULL)
        {
            ll BSTSize=0;

            pair<int,bool> res=helper(root,mn,mx,BSTSize);

            if(res.second)
                maxSize=max(maxSize,BSTSize);
            debug(root->data);
            debug(maxSize);
            debug(BSTSize);
            st.push(root);
            root=root->left;
        }
        else
        {
            root=st.top();
            st.pop();
            root=root->right;
        }
    }

    return maxSize;
    
}

struct BSTPair
{
    bool isBST;
    ll mx;
    ll mn;
    ll maxSize; // Size of that maxSize subtree
    treeNode* maxSizeRoot; // stores the root of subtree with max size
    // not necessary that this value is eqaul to the root value subtree

    BSTPair()
    {
        this->isBST=true;
        this->mn=INT_MAX;
        this->mx=INT_MIN;
        this->maxSize=0;
        this->maxSizeRoot=NULL;
    }

};

//https://www.youtube.com/watch?v=UGsJz8fSYp0
// Idea is to return a BSTPair from each subtree and check 
// weather the the current node is a valid BST
BSTPair largestBSTinBT2(treeNode *root)
{
    if(root==NULL)
    {
        BSTPair temp;
        return temp;
    }

    BSTPair lf,rt,curr;

    lf=largestBSTinBT2(root->left);
    rt=largestBSTinBT2(root->right);

    // For being a valid bst
    // 1-> left subtree must be a bst
    // 2-> right subtree must be a bst
    // 3-> max of left subtree must be less than current node 
    //     and min of right subtree must be greater then current node 
    curr.isBST=lf.isBST && rt.isBST && (root->data>lf.mx && root->data<rt.mn);

    // calculating the min and max of the current node b/c min and max will be 
    // useful for checking for it's parent
    curr.mn=min(root->data,min(lf.mn,rt.mn));
    curr.mx=max(root->data,min(lf.mx,rt.mx));

    // If it a BST
    if(curr.isBST)
    {
        curr.maxSizeRoot=root;
        curr.maxSize=lf.maxSize+rt.maxSize+1;
    }
    else if(lf.maxSize>rt.maxSize) // it will never reach this condition leaf node
    {   // b/c leaf node is always a BST 
        curr.maxSizeRoot=root->left;
        curr.maxSize=lf.maxSize;
    }
    else
    {
        curr.maxSizeRoot=root->right;
        curr.maxSize=rt.maxSize;
    }
    
    return curr;
}


void solve()
{
    // vi v={30,15,50,10,20,40,60};
    // ll sz=v.size();
    // treeNode *root=NULL;
    // ll i;
    // root=buildTree(root,v[0]);
    // Fo(i,1,sz-1)
    // {
    //     buildTree(root,v[i]);
    // }
    // ll treeNode;

    treeNode *root = new treeNode(50); 
    root->left = new treeNode(10); 
    root->right = new treeNode(60); 
    root->left->left = new treeNode(5); 
    root->left->right = new treeNode(20); 
    root->right->left = new treeNode(55); 
    root->right->left->left = new treeNode(45); 
    root->right->right = new treeNode(70); 
    root->right->right->left = new treeNode(65); 
    root->right->right->right = new treeNode(80); 

    // 10 15 20 30 40 50 60

    ll mn=INT_MIN;
    ll mx=INT_MAX;

    ll res=largestBSTInBT(root);
    BSTPair ans=largestBSTinBT2(root);
    debug(ans.maxSizeRoot->data);
    debug(ans.maxSize);
    cout<<"Largest BST in BT : "<<res<<endl;
    
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