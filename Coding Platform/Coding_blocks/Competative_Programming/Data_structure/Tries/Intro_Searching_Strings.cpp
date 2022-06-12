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

class Node{
    public:
    char data;
    unordered_map<char,Node *> children;
    bool terminalNode;
    Node(char d)
    {
        data=d;
        terminalNode=false;
    }
};

//Questions based on prefix are easliy solved using prefix tree

class Trie{
    Node *root;
    ll cnt;
    public:
        Trie()
        {
            root=new Node('\0');
            cnt=0;
        }
        // Per word Time COmplexity:- O(|word|)
        void insert(string word)
        {
            Node *temp=root;
            for(ll i=0;i<word.size();i++)
            {
                char ch=word[i];
                if(temp->children.count(ch))
                {
                    temp=temp->children[ch];
                }
                else
                {
                    Node *n=new Node(ch);
                    temp->children[ch]=n;
                    temp=n;
                }   
            }
            temp->terminalNode=true;
        }
        // Time COmplexity:- O(|word|)
        bool find(string word)
        {
            Node *temp=root;
            for(ll i=0;i<word.size();i++)
            {
                char ch=word[i];
                if(temp->children.count(ch)==0)
                    return false;
                else
                {
                    temp=temp->children[ch];
                } 
            }
            return temp->terminalNode;
        }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc=1;
    // cin>>tc;
    while(tc--)
    {
        Trie ds;
        ll n,q,i;
        cin>>n>>q;
        vector<string> vs(n);
        fo(i,n)
        {
            cin>>vs[i];
            ds.insert(vs[i]);
        }

        fo(i,q)
        {
            string s;
            cin>>s;

            if(ds.find(s))
            {
                cout<<"Present";
            }
            else
            {
                cout<<"Absent";
            }
            cout<<endl;
        }

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