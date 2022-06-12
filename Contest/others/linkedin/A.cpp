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

// int minTime(vector<int> bs,vector<int> pt,vector<int> nt)
// {

// }

int maxTickets(vector<int> tickets)
{
    int i;
    int n=tickets.size();
    
    map<int,int> hm;

    for(i=0;i<n;i++)
        hm[tickets[i]]++;

    map<int,int> m=hm;
    int ans=0;
    for(auto val:hm)
    {
        int num=val.first;
 
        if(m[num+1]>0)
            continue;
        else
        {
            int cnt=0;
            while(m[num]>0)
            {
                cnt+=m[num];
                m[num]=0;
                num--;
            }
            ans=max(ans,cnt);
        }
    }

    return ans;
}

int counts(int n, vector<int>& vs) {
    if (n <= 0) return 1;
    int ans = 0;
    for (int i=0; i<n; ++i) {
        if (vs[i]%n==0 || n%vs[i]==0) {
            swap(vs[i], vs[n-1]);
            ans += counts(n-1, vs);
            swap(vs[i], vs[n-1]);
        }
    }
    return ans;
}

int countArrangement(int N) {
    vector<int> vs;
    for (int i=0; i<N; ++i) vs.push_back(i+1);
    return counts(N, vs);
}


long minTime(vector<int> batchSize, vector<int> processingTime, vector<int> numTasks){
    int n=batchSize.size();
    vector<long> dp(n+1,0);
    for(int i=0;i<n;i++){
        long tot=numTasks[i]/batchSize[i];
        if(numTasks[i]%batchSize[i]) tot++;
        dp[i+1]=processingTime[i]*tot;
    }
    long ans=dp[1];
    for(int i=2;i<=n;i++){
        if(dp[i]>ans) ans=dp[i];
    }
    return ans;
}

void solve()
{
    vector<int> v={8,8,4,4,5};
    // ll ans=maxTickets(v);
    // ll ans=countArrangement(5);
    vector<int> batchSize={3,2,5,7};
    // {4,3};
    vector<int> processingTime={5,4,10,12};
    // {6,5};
    vector<int> numTasks={10,6,10,5};
    // {8,8};

    ll ans=minTime(batchSize,processingTime,numTasks);
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