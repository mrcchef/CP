//LinkedIn:https://www.linkedin.com/in/abhijeettamrakar/
//GitHub:https://github.com/mrcchef/
#include <bits/stdc++.h>

// policy based data structure 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 
// find_by_order : finding ith element, order_of_key : number of element smaller than key

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

struct node{
    ll val;
    ll st,ed;
    node(){};

    node(ll val,ll st,ll ed){
        this->val=val;
        this->st=st;
        this->ed=ed;
    }
};

// bool compare()

void solve()
{
    ll n,i;
    cin>>n;
    vi v(n);
    vector<pii> vp(n);
    priority_queue<vi> pq; // {val,st,ed}
    vi visited(n,0);
    fo(i,n)
    {
        cin>>v[i];
        vp[i]={v[i],i};
    }
    
    sort(all(vp),greater<pii>());

    ll neg=0;
    ll cnt=0;

    i=0;

    while(!pq.empty() || i<n)
    {
        if(pq.empty())
        {
            while(i<n && visited[vp[i].second])
            {
                i++;
            }

            if(i<n && vp[i].first>0)
            {
                vi temp={vp[i].first,vp[i].second,vp[i].second};
                visited[vp[i].second]=1;
                pq.push(temp);
                continue;
            }
            else
                break;
        }

        vi node=pq.top();
        pq.pop();

        ll val=node[0];
        ll st=node[1];
        ll ed=node[2];
        
        debug(node);
        
        ll left=st-1;
        ll right=ed+1;
        vi temp;
        bool added=false;

        ll nst=st,ned=ed;

        while((left>=0 && !visited[left]) || (right<n && !visited[right]))
        {
            if(left>=0 && right<n)
            {
                if(!visited[left] && !visited[right])
                {
                    ll mx=max(v[left],v[right]);
                    if(mx+val<=0)
                    {
                        // ll len=ed-st+1;
                        // cnt+=len;
                        break;
                    }

                    added=true;
                    val+=mx;
                    if(mx==v[left])
                    {
                        nst=left;
                        visited[left]=1;
                        left--;
                        // temp={val+mx,left,ed};
                    }
                    else 
                    {
                        ned=right;
                        visited[right]=1;
                        right++;
                        // temp={val+mx,st,right};
                    }
                    // pq.push(temp);
                }
                else if(!visited[left])
                {
                    if(val+v[left]<=0)
                    {
                        ll len=ed-st+1;
                        cnt+=len;
                        break;
                    }
                    added=true;
                    val+=v[left];
                    nst=left;
                    visited[left]=1;
                    left--;
                    // temp={val+v[left],left,ed};
                    // pq.push(temp);
                }
                else if(!visited[right])
                {
                    if(val+v[right]<=0)
                    {
                        ll len=ed-st+1;
                        cnt+=len;
                        break;
                    }
                    added=true;
                    val+=v[right];
                    ned=right;
                    visited[right]=1;
                    right++;
                    // temp={val+v[right],st,right};
                    // pq.push(temp);
                }
            }
            else if(left>=0 && !visited[left] && val+v[left]>0)
            {
                
                // temp={val+v[left],left,ed};
                visited[left]=1;
                val+=v[left];
                nst=left;
                left--;
                added=true;
                // pq.push(temp);
            }
            else if(right<n && !visited[right] && val+v[right]>0)
            {
                // temp={val+v[right],st,right};
                visited[right]=1;
                val+=v[right];
                ned=right;
                right++;
                added=true;
                // pq.push(temp);
            }
            else
            {
                // ll len=ed-st+1;
                // cnt+=len;
                break;
            }
        }

        if(nst!=st || ned!=ed)
        {
            temp={val,nst,ned};
            pq.push(temp);
        }
        else
        {
            ll len=ned-nst+1;
            cnt+=len;
        }
    }

    for(i=0;i<n;i++)
    {
        if(!visited[i])
            neg++;
    }

    debug(visited);

    debug(mp(cnt,neg));

    cout<<cnt-neg<<endl;
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