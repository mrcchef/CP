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

// Making push operation costly
class Queue{
    stack<ll> st1,st2;
    public:
        void push(ll ele)
        {
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }

            st1.push(ele);

            while(!st2.empty())
            {
                st1.push(st2.top());
                st2.pop();
            }
        }

        ll pop()
        {
            if(st1.empty())
                return -1;
            ll del=st1.top();
            st1.pop();
            return del;
        }

        bool isEmpty()
        {
            return st1.empty();
        }
};


// pop operation is costly
class Queue2{
    stack<ll> st1,st2;
    public:
        void push(ll ele)
        {
            st1.push(ele);
        }

        ll pop()
        {
            if(st1.empty())
                return -1;
            
            while(st1.size()>1)
            {
                st2.push(st1.top());
                st1.pop();
            }

            ll del=st1.top();
            st1.pop();

            while(!st2.empty())
            {
                st1.push(st2.top());
                st2.pop();
            }
            return del;
        }

        bool isEmpty()
        {
            return st1.empty();
        }
};


void solve()
{
    Queue q1;

    Queue2 q2;

    vi v={1,2,3,4,5,6,7};
    ll sz=v.size();

    cout<<"Making push costly"<<endl;
    for(auto val:v)
    {
        cout<<val<<" inserted in queue"<<endl;
        q1.push(val);
    }

    while(!q1.isEmpty())
    {
        ll del=q1.pop();
        if(del==-1)
            cout<<"Queue is Empty"<<endl;
        else
            cout<<del<<" deleted"<<endl;
    }


    cout<<"Making pop costly"<<endl;
    for(auto val:v)
    {
        cout<<val<<" inserted in queue"<<endl;
        q2.push(val);
    }

    while(!q2.isEmpty())
    {
        ll del=q2.pop();
        if(del==-1)
            cout<<"Queue is Empty"<<endl;
        else
            cout<<del<<" deleted"<<endl;
    }
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