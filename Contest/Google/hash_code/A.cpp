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
const ll inf=1e18;
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


string choice(int n,vector<string> &vs,string s)
{
    string flag="***QWERTYUIOPASDFGHJKLZXCVBNM***";
    int sz=flag.size();

    string res(sz,'*');

    map<char,int> hm,isPresent;
    int i=0;

    for(i=0;i<sz;i++)
    {
        hm[flag[i]]=i;
        isPresent[flag[i]]=0;
    }

    for(i=0;i<vs.size();i++)
    {
        string temp=vs[i];
        bool check=true;
        int j;
        int cnt=0;
        for(j=0;j<s.size() && cnt<=s.size();j++)
        {
            if(s[j]!=temp[j] && s[j]!=' ')
            {
                check=false;
                break;
            }
            cnt++;
        }

        if(check)
            isPresent[temp[j]]=1;

    }

    debug(isPresent);

    for(i=0;i<sz;i++)
    {
        char ch=flag[i];
        if(isPresent[ch])
        {
            res[i]=ch;
            debug(i);
        }
    }

    return res; 
}

vector<int> findNumberSequnence(string direction)
{
    stack<int> st;
    vector<int> res;

    int i,n=direction.size();

    for(i=0;i<n;i++)
    {
        if(direction[i]=='R')
        {
            res.push_back(i+1);
        }
        else
        {
            st.push(i+1);
        }
    }

    while(!st.empty())
    {
        int ele=st.top();
        st.pop();
        res.push_back(ele);
    }

    return res;
}

void solve()
{
    int n;
    cin>>n;
    // vector<string> vs(n);
    string s;
    // ll i;
    // fo(i,n)
    //     cin>>vs[i];
    
    cin>>s;
    // debug(n);
    // debug(vs);
    // debug(s);
    vector<int> ans=findNumberSequnence(s);
    debug(ans);

}

int main()
{
    fastio
    #ifdef ONLINE_JUDGE
        // freopen("input.txt", "r", stdin); 
        // freopen("output.txt", "w", stdout);
        freopen("error.txt","w",stderr);
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