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
// Given a list of strings, you have to print the unique and smallest prefix of the list of string

class Node{
    public:
    char data;
    unordered_map<char,Node *> children;
    ll freq;
    bool terminalNode;
    Node(char d)
    {
        data=d;
        terminalNode=false;
        freq=0;
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

        void insert(string word)
        {
            Node *temp=root;
            for(ll i=0;i<word.size();i++)
            {
                char ch=word[i];
                if(temp->children.count(ch))
                {
                    temp=temp->children[ch];
                    // if(temp->children.size()!=0)
                }
                else
                {
                    Node *n=new Node(ch);
                    temp->children[ch]=n;
                    temp=n;
                }   
                temp->freq+=1;
                // deb(ch);
                // deb(temp->data);
                // deb(temp->freq);
            }
            temp->terminalNode=true;
        }

        
    void prefix(string word)
    {
        Node *temp=root;
        string res;
        ll flag=0;
        for(ll i=0;i<word.size();i++)
        {
            char ch=word[i];
            res+=ch;
            // here tm is the parent node so we need to check the frequency of children node
            if(temp->children[ch]->freq==1)
            {
                cout<<res<<" ";
                flag=1;  
                break;
            }
            temp=temp->children[ch];
        }
        if(flag==0)
            cout<<"Empty Prefix"<<" ";
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
        Trie td;
        vector<string> vs(n);
        fo(i,n)
        {
            // string s;
            cin>>vs[i];
            td.insert(vs[i]);
        }

        for(auto str:vs)
        {
            td.prefix(str);
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