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

// Commented area needs to be changed according to the need
// this segment tree is for range sum queries
struct SegTree{
    struct node{
        // variable
        ll sum ;
        node(){ // constructor 
            sum = 0;
        }
        // + operator overloading
        friend node const operator + (const node &a,const node &b){
            node res;
            res.sum = max(a.sum , b.sum);
            return res;
        }
    };
    int n;
    vector<node> v; 
    node dummy; // dummy node
    SegTree(int n){
        this->n = n;
        v.assign(4*n+10,dummy);
    }
    void update(int id,const int pos,const int val,int s,int e){
        if(s>e) return;
        if(s==e){ // bse case
            v[id].sum += val;
            return;
        }
        int mid = (s+e)/2;
        if(pos<=mid) update(2*id,pos,val,s,mid);
        else update(2*id+1,pos,val,mid+1,e);
        // operation after updation of child nodes
        v[id] = v[2*id] + v[2*id+1];
        return;
    }
    void update(const int pos,const int val){
        update(1,pos,val,1,n);
    }
    node query(int id,const int l,const int r,const int s,const int e){
        if(s>e || r<s || l>e) return dummy;
        else if(l<=s && e<=r) return v[id];
        else return query(2*id,l,r,s,(s+e)/2) + query(2*id+1,l,r,(s+e)/2+1,e);
        // above else return is query dependent
    }
    node query(const int l,const int r){
        return query(1,l,r,1,n);
    }
    ll get(int l,int r){
        return query(l,r).sum;
    }
};

void solve()
{
    ll n,m;
    cin>>n>>m;
    
    ll i,j;
    vector<string> vs(n);
    fo(i,n)
        cin>>vs[i];
    
    vector<vi> isExitable(n,vi(m,0));

    // fo(i,n)
    // {
    //     fo(j,m){
    //         if(i==0 || j==0)
    //         {
    //             if(vs[i][j]=='.')
    //                 isExitable[i][j]=1;
    //             else
    //                 isExitable[i][j]=0;
    //         }
    //         else
    //         {
    //             if(vs[i][j]=='.')
    //                 isExitable[i][j]=isExitable[i-1][j]|isExitable[i][j-1];
    //             else
    //                 isExitable[i][j]=0;
    //         }
    //     }
    //     debug(isExitable[i]);
    // }    

    
    fo(j,m)
    {
        fo(i,n){
            if(i==0)
            {
                if(vs[i][j]=='.')
                    isExitable[i][j]=0;
                else
                    isExitable[i][j]=j+1; // i based index
             } 
             else if(j==0)
             {
                if(vs[i][j]=='.')
                    isExitable[i][j]=0;
                else
                    isExitable[i][j]=1; // i based index
             }
            else
            {
                if(vs[i][j]=='.')
                {
                    if(isExitable[i-1][j]==0 || isExitable[i][j-1]==0)
                        isExitable[i][j]=0;
                    else if(vs[i-1][j]=='X' && isExitable[i][j-1]=='X')
                        isExitable[i][j]=j;
                    else if(vs[i-1][j]=='X')
                        isExitable[i][j]=isExitable[i][j-1];
                    else if(vs[i][j-1]=='X')
                        isExitable[i][j]=isExitable[i-1][j];
                    else
                        isExitable[i][j]=max(isExitable[i-1][j],isExitable[i][j-1]);
                }
                else
                    isExitable[i][j]=j+1;
            }
        }
        // debug(isExitable[j]);
    }    

    // fo(i,n)
    // {
    //     debug(isExitable[i]);
    // }

    vi isValid(m+1,0);

    // Fo(i,1,m)
    // {
    //     bool check=true;
    //     fo(j,n)
    //     {
    //         if(!isExitable[j][i-1] && vs[j][i-1]=='.')
    //         {
    //             check=false;
    //             break;
    //         }
    //     }

    //     if(check)
    //     {
    //         isValid[i]=1;
    //     }
    // }

    Fo(i,1,m)
    {
        ll mx=0;
        fo(j,n)
        {
            if(isExitable[j][i-1]>=1 && vs[j][i-1]=='.')
            {
                mx=max(mx,isExitable[j][i-1]);
            }
        }

        // if(check)
        // {
        isValid[i]=mx;
        // }
    }

    debug(isValid);

    SegTree sg(m);
    Fo(i,1,m)
        sg.update(i,isValid[i]);


    // vi pref(m+1,0);
    // Fo(i,1,m)
    // {
    //     pref[i]=pref[i-1]+isValid[i];
    // }

    ll q;
    cin>>q;



    fo(i,q)
    {
        ll x,y;
        cin>>x>>y;
        // ll range=pref[y]-pref[x-1];
        // debug(range);
        // debug(y-x+1);

        ll mx=sg.get(x,y);
        debug(mx);
        if(mx>=x && mx<=y)
        {
            cout<<"NO";
        }
        else
            cout<<"YES";
        cout<<endl;
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