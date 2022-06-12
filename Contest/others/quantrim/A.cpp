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

int helper(int n,vector<vector<int>> rounds)
{
    int sz=rounds.size();
    int i;

    for(i=0;i<sz;i++)
    {
        cout<<rounds[i][0]<<" "<<rounds[i][1]<<" "<<rounds[i][2]<<endl;
    }

    vector<int> investments(n+2,0);

    for(i=0;i<sz;i++)
    {
        int st=rounds[i][0];
        int ed=rounds[i][1];
        int amount=rounds[i][2];

        investments[ed+1]-=amount;
        investments[st]+=amount;
    }

    int ans=0;

    for(i=1;i<=n;i++)
    {
        investments[i]+=investments[i-1];
        ans=max(investments[i],ans);
    }
    return ans;
}

// bool comp(const pair<int,int> &a, const pair<int,int> &b)
// {
//        return a.first<b.first;
// }

// vector<int> processLogs(vector<string> logs,int threshold){
//     vector<int> ans;
//     map<int,int> m;
//     for(int i=0;i<logs.size();i++)
//     {
//         string cur=logs[i];
//         string a,b,c; 
//         //seperated from logs[i];
//         int j=0;
//         while(cur[j]!=" ") a+=cur[j];
//         j++;
//         while(cur[j]!=" ") b+=cur[j];
//         int x=stoi(a);
//         int y=stoi(b);
//         m[x]++;
//         if(x!=y) m[y]++;
//     }
//     vector<pair<int,int>> vp;
//     for(auto x:m) {
//         if(x.second>=threshold) vp.push_back(make_pair(x.second,x.first));
//     }
//     sort(vp.begin(),vp.end(),comp);
//     for(auto x:vp){
//         ans.push_back(x.first);
//     }
//     // debug()
//     return ans;
// }

void solve()
{
    int n;
    cin>>n;
    int i;
    vector<vector<int>> input(3);

    fo(i,3)
    {
        int st,ed,val;
        cin>>st>>ed>>val;
        vector<int> v={st,ed,val};
        input[i]=v;
    }

    int ans=helper(n,input);

    cout<<ans<<endl;
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