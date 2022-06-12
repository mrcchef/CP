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

void solve()
{
    ll n,m,i;
    cin>>n>>m;

    vector<queue<int>> vm(m+5); // for storing balls in m cylinders
    vector<vector<int>> arr(n+5); // for storing the index of cylinder on which 
    // the color i ball is present

    fo(i,m)
    {
        ll k;
        cin>>k;
        ll j;
        mii hm; // to check if in an cylinder we have two balls with the same color
        fo(j,k)
        {
            ll x;
            cin>>x;
            // making it 0 based 
            x--;
            
            vm[i].push(x);
            arr[x].push_back(i);
            hm[x]++;

            if(hm[x]==2)
            {
                cout<<"No"<<endl;
                return;
            }
        }
    }

    // stores the cnt of elemets that are present on the top most position of every cylinder
    mii cnt;
    
    queue<int> q;
    // inititalising queue by putting elements from the top most ball of each cylinder
    fo(i,m)
    {
        ll ele=vm[i].front();
        cnt[ele]++;
        if(cnt[ele]==2)
        {
            // if cnt of any color ball is 2 then push the cylinder index in the queue
            q.push(arr[ele][0]);
            q.push(arr[ele][1]);
        }   
    }
    
    ll total=2*n;


    //popping one by one all the elements from the queue and discover new top elements
    // of the cylinders and adding there cylinder index if they 2 of the same color present on the top
    while(!q.empty())
    {
        ll col=q.front();
        q.pop();    

        total--;
        
        ll ele=vm[col].front();
        // decreased the cnt 
        cnt[ele]--;

        // removed the ball from clynder index col
        vm[col].pop();

        // if cylinder is not empty
        if(!vm[col].empty())
        {
            // descovering new top element of the cylinder
            ll newEle=vm[col].front();
            cnt[newEle]++;
            
            // if we have 2 new top elements then push the cylinder index in the queue
            if(cnt[newEle]==2)
            {
                q.push(arr[ele][0]);
                q.push(arr[ele][1]);
            }
        }
    }
    
    // if all the elements are removed then simply Yes else No
    if(total==0)
    {
        cout<<"Yes"<<endl;
    }
    else
        cout<<"No"<<endl;
    
    

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