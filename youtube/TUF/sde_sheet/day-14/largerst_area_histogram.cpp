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

// Time Complexity O(N+N)=O(N)
// Method 1 using two stacks 
// https://www.youtube.com/watch?v=vcv3REtIvEo&t=947s
void largestAreaHistogram(vi &heights)
{
    ll sz=heights.size();
    vi arr(sz+1);
    ll i;
    fo(i,sz)
        arr[i+1]=heights[i];

    stack<ll> st;
    vi prefDescIndex(sz+2,0);
    vi suffDescIndex(sz+2,0);

    Fo(i,1,sz)
    {
        if(st.empty()) 
        {
            prefDescIndex[i]=0;
            st.push(i);
        }
        else
        {
            if(!st.empty() && arr[st.top()]<arr[i])
            {
                prefDescIndex[i]=st.top();
                st.push(i);
            }
            else
            {
                while(!st.empty() && arr[st.top()]>=arr[i])
                {
                    st.pop();
                }

                if(!st.empty())
                    prefDescIndex[i]=st.top();
                else
                    prefDescIndex[i]=0;
                st.push(i);
            }
        }
    }

    while(!st.empty())
        st.pop();

    for(i=sz;i>=1;i--)
    {
        if(st.empty())
        {
            suffDescIndex[i]=sz+1;
            st.push(i);
        }
        else
        {
            if(!st.empty() && arr[st.top()]<arr[i])
            {
                suffDescIndex[i]=st.top();
                st.push(i);
            }
            else
            {
                while(!st.empty() && arr[st.top()]>=arr[i])
                {
                    st.pop();
                }

                if(!st.empty())
                    suffDescIndex[i]=st.top();
                else
                    suffDescIndex[i]=sz+1;
                st.push(i);
            }
        }
    }    

    ll largestArea=0;


    debug(arr);
    debug(prefDescIndex);
    debug(suffDescIndex);

    Fo(i,1,sz)
    {
        ll curr=arr[i];
        ll width=suffDescIndex[i]-prefDescIndex[i]-1;
        
        debug(i)
        debug(largestArea)
        debug(width)
        debug(curr)
        debug(width*curr)
        largestArea=max(largestArea,width*curr);
    }

    debug(largestArea);
}

//Time complexity O(N)
// In order to calculate the largest possible area taking hi as the minimum height
// We need to check first left obstacle and first right obstacle i.e.
// the first left element that is smaller than hi and first right element i.e smaller the hi
// we are maintaing a stack of increasing elements such that 
// for any height hi, the left obstacle is the next top element of stack
// And when we enconter an element hj such that it is smaller that stack top whcih hi
// then hj is the right obstacle for hi 
// Now we simply calculate the width and multiply with hi which is minimum in the width of elements
void laggestAreaHistogram2(vi &heights)
{
    ll sz=heights.size();
    stack<ll> st;
    ll i;

    ll largestArea=0;

    fo(i,sz)
    {
        // if stack is empty then it is the very first element 
        if(st.empty())
        {
            largestArea=max(largestArea,heights[i]*i);
            st.push(i);
        }
        else
        {
            // Here we are checking if we enconter right obstacle for the element
            // if yes, then we will calculate the area
            while(!st.empty() && heights[st.top()]>heights[i])
            {
                ll in=st.top();
                st.pop();
                if(st.empty())
                    largestArea=max(largestArea,heights[in]*i);
                else
                    largestArea=max(largestArea,heights[in]*(i-st.top()-1));
            }
            // will push the element which is the maximum in the stack and maintaing the
            // stack as increading array
            st.push(i);
        }
    }   

    while(!st.empty())
    {
        ll in=st.top();
        st.pop();
        if(st.empty())
            largestArea=max(largestArea,heights[in]*i);
        else
            largestArea=max(largestArea,heights[in]*(i-st.top()-1));
    }

    debug(largestArea);

}

void solve()
{
    vi v={2,1,5,6,2,3};

    largestAreaHistogram(v);
    laggestAreaHistogram2(v);
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