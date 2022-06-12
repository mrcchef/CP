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

// Problem Link:
//https://atcoder.jp/contests/abc246/tasks/abc246_f

// basic question is
// given n strings and a length l
// you need to generate number of unique strings of length l such that the characters are present 
// in the array of strings

// Solution:
// Solution is based on the idea of inclusion and exclusion principle
// eg: 'ab','ac' 
// now strings that could be formed only through 'ab' of length 2 (let l=2): S1= {'aa','ab','bb','ba'}
// strings that could be formed only through 'ac' of length 2 (let l=2):S2= {'aa','ac','cc','ca'}
// but we need uniuqe strings but 'aa' is repeating so
// we need to remove the strings that could be formed with the characters that are common in both the strings
// i.e. 'a' is common in both the strigs
// strings that could be formed only through 'a' of length 2 (let l=2):S12 {'aa'}

// total cnt= |S1|+|S2|-|S12| => 4 + 4 - 1 => 7

// we just need to generalize the idea over n strings
// if in the subset the number of set bits defines the number of string we have used
// to create the string of length l
// if no. of set bits is odd
// then we will add the contribution into the answer
// if no. of set bits are even
// then we will remove the contribution from the answer

// In this way we can generalize the inclusion and exclusion principle 



void solve()
{
    ll n,l,i;
    cin>>n>>l;

    ll j;
    vi arr(n);

    // 
    fo(i,n)
    {
        string s;
        cin>>s;
        ll curr=0;
        // converting the string into a number whose bitwise representation 
        // will help to identify which character is available
        fo(j,s.size())
        {
            ll val=(s[j]-'a');
            curr+=1<<val;
        }
        arr[i]=curr;
    }

    ll ans=0;

    Fo(i,1,(1<<n)-1)
    {       
        ll picked=(1<<26)-1;
        // here in the picked we storing the characters that are common in all the choosen strings
        fo(j,n)
        {
            if((1LL<<j)&i)
                picked&=arr[j];
        }

        // this will simply return the number of strings that are common in the set
        int bits=popcount(picked);

        // if in the current subset the set bits are odd, then we are adding the contri
        if(popcount(i)&1) 
        {
            ans=msum(ans,fxp(bits,l,MOD1),MOD1);
        }// else we are removing the contri
        else
            ans=msub(ans,fxp(bits,l,MOD1),MOD1);

        ans%=MOD1;
    }

    cout<<ans<<endl;
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