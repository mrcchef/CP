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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* head)
{
    ListNode* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

bool isInsectionNode(ListNode* head,ListNode* node)
{
    ListNode *temp=head;
    while(temp!=nullptr)
    {
        if(temp==node)
            return true;
        temp=temp->next;
    }

    return false;
}

// Brute force solution of O(n*m)
// We check for every node weather the node can be a intersection or not
// We can optimise it using map<ListNode*,int> and store occurance of the node
// By doing this our time for searching will be reduced to O(logn) 
ListNode* getIntersectionNodeBruteForce(ListNode* headA,ListNode *headB)
{
    ListNode* res=nullptr;
    ListNode *temp=headA;
    while(temp!=nullptr)
    {
        bool check=isInsectionNode(headB,temp); // checing time can be optimised be hashmap 
        if(check)
        {
            res=temp;
            break;
        }
        temp=temp->next;
    }

    return res;
}

stack<ListNode*> getLinkedListPath(ListNode* head)
{
    stack<ListNode*> path;
    ListNode *temp=head;
    while(temp!=nullptr)
    {
        path.push(temp);
        temp=temp->next;
    }

    return path;
}

// Time Complexity O(n) but the code is bit lengthy
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    stack<ListNode*> path1,path2;
    path1=getLinkedListPath(headA);
    path2=getLinkedListPath(headB);

    ListNode* res=nullptr;

    while(!path1.empty() && !path2.empty())
    {
        ListNode* node1=path1.top();
        ListNode* node2=path2.top();

        debug(node1->val);
        path1.pop();
        path2.pop();

        if(node1==node2)
            res=node1;
        else
            break; 
    }

    return res;
}

// Time Complexity is O(n) and code is consise
ListNode *getIntersectionNodeEfficientClean(ListNode *headA, ListNode *headB) {

    ListNode* nodea=headA;
    ListNode* nodeb=headB;

    // If we are traversing from the left then we need to makesure that both the 
    // pointers should move in the same order, otherwise their is no use of traversing from left
    
    while(nodea!=nodeb)
    {
        //for the end of first iteration, we just reset the pointer to the head of another linkedlist
        // By doing that we can be sure that the first time when we need to point to head of another
        // linked list it must be for the smaller list and now smaller list interator is pointing to 
        // the head of longer list. now, in the longer list, smaller list iterator can only interate
        // to the difference of size of both linked list and on the 2nd itertion they will be
        // iterating in the same level
        
        // For more explantaion, refer to TUF video
        nodea=nodea==nullptr?headB:nodea->next;
        nodeb=nodeb==nullptr?headA:nodeb->next;
    }

    return nodea;
}


void solve()
{
    ListNode* head1,*head2;
    head1=new ListNode(4);
    head1->next=new ListNode(1);
    head2=new ListNode(5);
    head2->next=new ListNode(6);
    head2->next->next=new ListNode(1);
    head2->next->next->next=head1->next->next=new ListNode(8);
    head2->next->next->next->next=head1->next->next->next=new ListNode(4);
    head2->next->next->next->next->next=head1->next->next->next->next=new ListNode(5);

    cout<<"Head1 LinkedList:"<<endl;
    printList(head1);

    cout<<"Head2 LinkedList:"<<endl;
    printList(head2);

    ListNode* bruteSol=getIntersectionNodeBruteForce(head1,head2);
    ListNode* intersection=getIntersectionNode(head1,head2);
    ListNode* cleanSol=getIntersectionNodeEfficientClean(head1,head2);
    if(intersection==nullptr)
        cout<<"NO intersection"<<endl;
    else
    {
        cout<<bruteSol->val<<endl;
        cout<<intersection->val<<endl;
        cout<<cleanSol->val<<endl;
    }
}

int main()
{
    fastio
    #ifdef ONLINE_JUDGE
         freopen("Error.txt", "w", stderr);
    #endif
    int t=1;
    cin>>t;
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