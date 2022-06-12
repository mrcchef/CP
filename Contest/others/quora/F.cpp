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

vector<int> storeItemsTracker(vector<string> logs)
{
    map<string,map<int,int>> m1;
    vector<int> res;

    for(auto x:logs){

        string s1=x.substr(0,4);
        string s2=x.substr(0,6);
        if(s2=="supply"){
            string item,p1,p2;
            int i;
            for(i=7;x[i]!=':';i++) item+=x[i];
            for(i=i+1;x[i]!=' ';i++) p1+=x[i];
            for(i=i+1;x[i]!='\0';i++) p2+=x[i];
            int p11,p22;
            p11=stoi(p1);
            p22=stoi(p2);
          
            map<int,int> helper=m1[item];
            helper[p22]+=p11;
            
            m1[item]=helper;

        }
        else if(s1=="sell"){
            string item,q1,p2;
            int i;
            for(i=5;x[i]!=':';i++) item+=x[i];
            for(i=i+1;x[i]!='\0';i++) q1+=x[i];

            int q2=stoi(q1);
            debug(item);
            debug(q2);            
            map<int,int> helper=m1[item];

            if(helper.size()==0)
            {
                res.push_back(-1);
                continue;
            }
            auto it=helper.begin();

            int q=0;
            int cost=0;
            while(it!=helper.end())
            {
                ll mn=min(it->second,q2-q);
                cost+=mn*it->first;
                q+=mn;
                
            }

            debug(mp(it->first,it->second));

            if(it->second >= q2)
            {
                int cost=q2*it->first;
                helper[it->first]-=q2;
                if(helper[it->first]==0)
                    helper.erase(it->first);

                res.push_back(cost);
            }
            else
                res.push_back(-1);
            
            m1[item]=helper;
        }   
        else
        {
            string item,p1,p2,reason;
            int i;
            for(i=7;x[i]!=':';i++) item+=x[i];
            for(i=i+1;x[i]!=' ';i++) p1+=x[i];
            for(i=i+1;x[i]!=' ';i++) p2+=x[i];
            for(i=i+1;x[i]!='\0';i++) reason+=x[i];
            int p11,p22;
            p11=stoi(p1);
            p22=stoi(p2);

            map<int,int> helper=m1[item];

            if(reason!="defect")
            {
                ll newPrice=((p22*8)+9)/10;
                helper[newPrice]+=p11;
            }
            
        }
    }

    debug(res);

    return res;
}
        
int main()
{
    fastio
    #ifdef ONLINE_JUDGE
         freopen("Error.txt", "w", stderr);
    #endif
    vector<string> v;
    ll n;
    cin>>n;
    ll i;
    fo(i,n){
        string s;
        getline(cin,s);
        if(i==0)
            continue;
        v.pb(s);

        // debug(s);
    }

    //for(auto x:v) cout<<x<<endl;
    vector<int> ans;
    //ans;
    storeItemsTracker(v);
    debug(ans);
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