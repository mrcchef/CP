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


void Print(ll mx,ll window_no)
{
    cout<<"Window_No:"<<window_no<<endl;
    cout<<"Maximum:"<<mx<<endl;
} 

// This approach takes O(nlogn) 
// Core-ly based on sliding window technique in an array
void OnLogn(vi &v,ll window_size)
{
    ll sz=v.size();
    vi res(sz-window_size+1);

    ll mx=INT_MIN,i;
    map<ll,ll> hm; 

    ll window_cnt=0;

    window_cnt++;
    fo(i,window_size)
    {
        mx=max(mx,v[i]);
        hm[v[i]]++;
    }
    res[window_cnt-1]=mx;
    
    // Print(mx,window_cnt);

    for(i;i<sz;i++)
    {
        window_cnt++;
        ll rem_ind=i-window_size;
        hm[v[rem_ind]]--;
        if(hm[v[rem_ind]]==0)
        {
            hm.erase(v[rem_ind]);
            if(!hm.empty())
                mx=hm.rbegin()->first;
            else
                mx=INT_MIN;
        }

        mx=max(mx,v[i]);
        hm[v[i]]++;
        res[window_cnt-1]=mx;
        // Print(mx,window_cnt);
    }

    debug(res);
}

// This approach takes O(n)
void On(vi &v,ll window_size)
{
    ll sz=v.size();
    vi res(sz-window_size+1);

    // queue will store the elements in decreasing order
    // i.e front element will always points to the
    // maximum element in the window
    // we will be storing indecies b/c they are unique but
    // values can be duplicate
    deque<ll> q;

    ll i;
    fo(i,sz)
    {
        // if window not-epmty and size of curr window is equal to 
        // window_size then in order to add one more element 
        // in the window we have to remove one element from left
        if(!q.empty() && q.front()==i-window_size)
            q.pop_front();
        
        // Since we are maintaing the queue in increasing order so, 
        // before inserting the queue we need to remove all the 
        // elemets which are less than current 
        while(!q.empty() && v[q.back()]<v[i])
            q.pop_back();

        // simple add current elelment in the window
        q.push_back(i);

        // if window size is full we will add res to our arrat 'res'
        if(i-window_size+1>=0)
        {
            res[i-window_size+1]=v[q.front()];
        }
    }

    debug(res);

}

void solve()
{
    vi v={1,3,-1,-3,5,3,6,7};
    ll sz=v.size();
    ll window_size=3;

    OnLogn(v,window_size);
    On(v,window_size);
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