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

struct node{
    ll x,y;
    ll sz;
};

// Based on scanline algorithm and dp 
// scanline i.e. range updates in array 

void solve()
{
    ll n,m,i,j;
    cin>>n>>m;
    vector<string> vs(n+1);

    fo(i,n)
    {
        cin>>vs[i+1];
        vs[i+1]='$'+vs[i+1];
    }   

    vector<vi> up(n+2,vi(m+2));
    vector<vi> down(n+2,vi(m+2)); 
    vector<vi> left(n+2,vi(m+2));
    vector<vi> right(n+2,vi(m+2));
    vector<vi> markh(n+2,vi(m+2));
    vector<vi> markv(n+2,vi(m+2));
    fo(i,n+2)
    {
        fo(j,m+2)
        {
            up[i][j]=down[i][j]=left[i][j]=right[i][j]=markh[i][j]=markv[i][j]=0;
        }
    }

    Fo(i,1,n)
    {
        Fo(j,1,m)
        {
            if(vs[i][j]=='*')
            {
                down[i][j]=down[i-1][j]+1;
                right[i][j]=right[i][j-1]+1;
            }
        }
    }


    for(i=n;i>=1;i--)
    {
        for(j=m;j>=1;j--)
        {
            
            if(vs[i][j]=='*')
            {
                up[i][j]=up[i+1][j]+1;
                left[i][j]=left[i][j+1]+1;
            }
        }
    }
    // cout<<"Down"<<endl;
    // fo(i,n+2)
    // {
    //     fo(j,m+2)
    //         cout<<down[i][j]<<" ";
    //     cout<<endl;
    // }    

    // cout<<"Down"<<endl;
    // fo(i,n+2)
    // {
    //     fo(j,m+2)
    //         cout<<up[i][j]<<" ";
    //     cout<<endl;
    // }

    // cout<<"Down"<<endl;
    // fo(i,n+2)
    // {
    //     fo(j,m+2)
    //         cout<<right[i][j]<<" ";
    //     cout<<endl;
    // }

    // cout<<"Down"<<endl;
    // fo(i,n+2)
    // {
    //     fo(j,m+2)
    //         cout<<left[i][j]<<" ";
    //     cout<<endl;
    // }

    vector<node> res;

    Fo(i,1,n)
    {
        Fo(j,1,m)
        {
            if(vs[i][j]=='*')
            {
                ll mn=INT_MAX;
                mn=min(mn,left[i][j]);
                mn=min(mn,right[i][j]);
                mn=min(mn,up[i][j]);
                mn=min(mn,down[i][j]);
                mn-=1; // center is also included
                if(mn>=1)
                {
                    debug(i)
                    debug(j)
                    debug(mn)
                    node temp;
                    temp.x=i;
                    temp.y=j;
                    temp.sz=mn;
                    debug(i-mn);
                    debug(i+mn+1);
                    debug(j-mn);
                    debug(j+mn+1);
                    markh[i][j-mn]+=1;
                    markh[i][j+mn+1]-=1;
                    markv[i-mn][j]+=1;
                    markv[i+mn+1][j]-=1;
                    res.pb(temp);
                }
            }
        }
    }

    // cout<<"HR"<<endl;
    // fo(i,n+2)
    // {
    //     fo(j,m+2)
    //         cout<<markh[i][j]<<" ";
    //     cout<<endl;
    // }

    // cout<<"VR"<<endl;
    // fo(i,n+2)
    // {
    //     fo(j,m+2)
    //         cout<<markv[i][j]<<" ";
    //     cout<<endl;
    // }

    Fo(i,1,n+1)
    {
        Fo(j,1,m+1)
        {
            markh[i][j]+=markh[i][j-1];
        }
    }

    Fo(i,1,n)
    {
        Fo(j,1,m)
        {
            markv[i][j]+=markv[i-1][j];
        }
    }

    // cout<<"HR"<<endl;
    // fo(i,n+2)
    // {
    //     fo(j,m+2)
    //         cout<<markh[i][j]<<" ";
    //     cout<<endl;
    // }

    // cout<<"VR"<<endl;
    // fo(i,n+2)
    // {
    //     fo(j,m+2)
    //         cout<<markv[i][j]<<" ";
    //     cout<<endl;
    // }

    ll flag=1;

    Fo(i,1,n)
    {
        Fo(j,1,m)
        {
            if(vs[i][j]=='*' && markh[i][j]==0 && markv[i][j]==0)
            {
                flag=0;
                break;
            }
        }
    }

    if(!flag)
        cout<<-1<<endl;
    else
    {
        cout<<res.size()<<endl;
        for(auto val:res)
        {
            cout<<val.x<<" "<<val.y<<" "<<val.sz<<endl;
        }

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