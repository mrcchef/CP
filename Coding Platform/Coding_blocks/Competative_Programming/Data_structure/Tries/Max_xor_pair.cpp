#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<=n;i++)
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define endl "\n"
#define deb(x) cout << #x << "=" << x << endl
const ll mod = 1e9+7;

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

// Question:-
// Given a list of numbers you have to print the maximum xor of a pair

// TC
// 6
// 3 10 5 25 2 8
// 2

class Node{
    public:
    Node *left;
    Node *right;
};

class Trie{
    Node *root;
    public:
        Trie()
        {
            root=new Node();
        }

    void insert(ll val)
    {
        Node *temp=root;
        for(ll i=31;i>=0;i--)
        {
            if(val&(1<<i))
            {
                if(temp->right==NULL)
                {
                    temp->right=new Node();
                }
                temp=temp->right;
            }
            else
            {
                if(temp->left==NULL)
                {
                    temp->left=new Node();
                }
                temp=temp->left;
            }
        }
    }

    ll xor_helper(ll val)
    {
        Node *temp=root;
        ll txor=0;
        for(ll i=31;i>=0;i--)
        {
            if(val&(1<<i))
            {
                if(temp->left!=NULL)
                {
                    txor+=(1<<i);
                    temp=temp->left;
                }
                else
                    temp=temp->right;
            }
            else
            {
                if(temp->right!=NULL)
                {
                    txor+=(1<<i);
                    temp=temp->right;
                }
                else
                    temp=temp->left;
            }
        }
        return txor;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll n,i;
        cin>>n;
        vi v(n);
        Trie td;
        fo(i,n)
        {
            cin>>v[i];
            td.insert(v[i]);
        }
        
        ll ans=0;

        for(auto val:v)
        {
            ans=max(ans,td.xor_helper(val));
        }
        cout<<ans<<endl;
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