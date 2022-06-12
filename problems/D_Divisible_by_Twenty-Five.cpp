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

vector<char> zero={'0','5'};
vector<char> one={'0','2','5','7'};

ll dfs(ll in,string &s,ll x,ll n,vi &pref)
{
    // base case
    if(in==2)
    {
        string temp=s.substr(0,2);
        reverse(temp.begin(),temp.end());

        ll val=stoi(temp);

        // if len of string is also 2
        // only three valid case {25,50,75}
        if(n==2)
        {
            if(val==0)
                return 0;
            else
            {
                return (val%25==0);
            }
        }

        // now len>2

        // if the first digit is '0' then it can not form a valid configuration
        // two cases such that first place can have zero
        // 1) by default it has zero
        // 2) it has character 'X' and for the current dfs value of x is 0

        if(s.back()=='0' || (s.back()=='X' && x==0))
            return 0;
        
        
    
        // now if the last two digit belongs to {00,25,50,75}
        // then it's a valid string
        if(val%25==0)
        {
            ll cnt=pref[n]-pref[2]; // number of '_'
            // each '_' can have 10 digits {0,1,...,9}
            ll total=1;
        
            // but the very first digit can not be 0 
            // hence if first position is '_' then total 9 digits are possible 
            if(s.back()=='_')
            {
                cnt--;
                total*=9;
            }

            total=total*pow(10,cnt);

            return total;
        }
        return 0;
    }

    // now, the in<2

    ll val=0;
    char prev=s[in];
    
    if(s[in]=='_')
    {
        // 0th character can either be 0 or 5
        // 1st character can either be 2,5,7,0
        if(in==0)
        {
            for(auto &ch:zero)
            {
                s[in]=ch;
                ll output=dfs(in+1,s,x,n,pref);
                val+=output;
            }
        }
        else if(in==1)
        {
            for(auto &ch:one)
            {
                s[in]=ch;
                ll output=dfs(in+1,s,x,n,pref);
                val+=output;
            }
        }
        else
        {
            // i>=2
        }
    }
    else if(s[in]=='X')
    {
        s[in]=(char)(x+48);
        val+=dfs(in+1,s,x,n,pref);
    }
    else
    {
        val+=dfs(in+1,s,x,n,pref);
    }

    s[in]=prev;
    return val;
}

void solve()
{
    string s;
    cin>>s;
    ll n=s.size();
    ll i;

    reverse(all(s));

    string temp(n,'0');

    // '0' single digit 0 is a valid configuration
    // hence if the size of string is 1 
    // and there are three ways in which we can have single digit zero 
    if(s.size()==1)
    {
        if(s[0]=='_' || s[0]=='0' || s[i]=='X') // three ways for single digit zero
            cout<<1<<endl;
        else
            cout<<0<<endl;
        return;
    }   

    vi pref(n+1,0);
    bool isPresent=false;
    fo(i,n)
    {
        pref[i+1]=pref[i];
        if(s[i]=='X')
            isPresent=true;
        if(s[i]=='_')
            pref[i+1]+=1;
    }
    
    ll ans=0;
    // if 'X' is not present then only once I need to do dfs
    // but if X is present then for all the possible value of X
    // I need to do dfs
    if(!isPresent)
    {
        ans=dfs(0,s,5,n,pref);
    }
    else
    {
        for(ll x=0;x<=9;x++)
        {
            ll cnt=dfs(0,s,x,n,pref);
            ans+=cnt;   
        }
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