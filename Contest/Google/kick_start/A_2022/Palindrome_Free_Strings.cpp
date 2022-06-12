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
int t=1;
ll p;
void printG(string res)
{
    cout<<"Case #"<<p<<": "<<res;
    cout<<endl;
    // cout<<(cnt==-1?"IMPOSSIBLE":cnt)<<endl;
}

map<string,ll> hm;

bool check(string s,ll n)
{
    for(ll i=0;i<n;i++)
    {
        ll j=i+4;
        if(j>=n)
            continue;
        bool flag=false;
        ll t=i;
        while(t<j)
        {
            if(s[t]!=s[j] || s[t]=='*' || s[j]=='*')
            {
                flag=true;
                break;
            }
            t++;
            j--;
        }

        if(!flag)
            return false;

        j=i+5;
        t=i;
        
        if(j>=n)
            continue;
        
        flag=false;
        t=i;
        while(t<j)
        {
            if(s[t]!=s[j] || s[t]=='*' || s[j]=='*')
            {
                flag=true;
                break;
            }
            t++;
            j--;
        }

        if(!flag)
            return false;
    }


    return true;
}

bool dfs(ll i,ll n,string &s)
{
    if(i==n)
    {
        bool val=check(s,n);
        // debug(mp(s,val));
        return val;
    }

    bool flag=false;

    if(s[i]=='?')
    {
        s[i]='1';
        flag|=dfs(i+1,n,s);
        s[i]='0';
        flag|=dfs(i+1,n,s);
        s[i]='?';
    }
    else
    {
        flag|=dfs(i+1,n,s);
    }

    return flag;
}

void solve()
{
    string s;
    ll n;
    cin>>n;
    cin>>s;
    // n=s.size();
    ll i;
    string res=s;
    map<ll,set<ll>> hm;
    bool flag=true;
    for(i=0;i<n;i++)
    {
        if(s[i]=='?')
        {
            ll j=i-4;
            
            if(j>=0)
            {
                if(res[j]=='*')
                {
                    res[i]='*';
                }
                else
                {
                    res[i]=((res[j]=='1')?'0':'1');
                }
            }
            else
            {
                res[i]='*';
            }

            j=i-5;
            if(j>=0)
            {
                if(res[j]!='*')
                {
                    char poss=((res[j]=='1')?'0':'1');
                    if(poss!=res[i])
                    {
                        flag=false;
                        break;
                    } 
                }
                else
                {
                    
                }
            }
        }
        else
        {
            res[i]=s[i];   
        }
    }
    debug(res);
    reverse(res.begin(),res.end());
    string temp=res;
    for(i=0;i<n;i++)
    {
        if(res[i]=='*')
        {
            ll j=i-4;
            if(j>=0)
            {
                temp[i]=res[j];
            }

            j=i-5;
            if(j>=0){
                if(temp[i]!=res[j])
                {
                    flag=false;
                    break;
                }
            }
        }
        else
        {
            temp[i]=res[i];            
        }
    }
    debug(temp);
    reverse(temp.begin(),temp.end());
    string arr=temp;
    for(i=0;i<n;i++)
    {
        if(temp[i]=='*')
        {
            ll j=i-4;
            if(j>=0)
            {
                arr[i]=temp[j];
            }

            j=i-5;

            if(j>=0)
            {
                char ch=temp[j];
                if(ch!=arr[i])
                {
                    flag=false;
                    break;
                }
            }
        }
        else
            arr[i]=temp[i];
    }
    debug(arr);
    string ans;
    if(!flag)
    {
        ans="IMPOSSIBLE";
        printG(ans);
    }
    else
    {
        bool result=check(arr,n);
        debug(result);
        ans=result?"POSSIBLE":"IMPOSSIBLE";
        printG(ans);
    }

    // bool flag=dfs(0,n,s);
    // printG(res);
}

int main()
{
    fastio
    #ifdef ONLINE_JUDGE
        // freopen("input.txt", "r", stdin); 
        // freopen("output.txt", "w", stdout);
        freopen("error.txt","w",stderr);
    #endif
    cin>>t;

    // hm["0"]=1;
    // hm["1"]=1;
    // hm["00"]=1;
    // hm["11"]=1;
    // hm["000"]=1;
    // hm["010"]=1;
    // hm["101"]=1;
    // hm["111"]=1;
    // hm["0000"]=1;
    // hm["0110"]=1;
    // hm["1001"]=1;
    // hm["1111"]=1;

    for(p=1;p<=t;p++)
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