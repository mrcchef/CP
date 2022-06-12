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

struct data{
    int tm;
    string oper;
    string item;
    int dur;
    int q;
};

bool compare(data &d1,data &d2)
{
    return d1.tm<d2.tm;
}


int storeItemsTracker2(vector<string> pricelist,vector<string> logs)
{
    int n=pricelist.size();
    int i;
    int j;

    map<string,int> hm;

    for(i=0;i<n;i++)
    {
        string s=pricelist[i];
        string item;
        string price;

        for(j=0;s[j]!=':';j++)
        {
            item+=s[j];
        }
        j++; 

        for(j;s[j]==' ';j++);
 
        for(j;s[j]!='\0';j++)
        {
            price+=s[j];
        }

        int pr=stoi(price);
        hm[item]=pr;
    }

    debug(hm);   

    int m=logs.size();

    vector<data> arr;

    for(i=0;i<m;i++)
    {
        string oper,times,item,q,dur;
        string s=logs[i];
        debug(s);
        j=0;
        for(j=0;s[j]!=' ';j++)
            oper+=s[j];
        
        for(j;s[j]==' ';j++);

        for(j;s[j]!=',';j++)
        {
            times+=s[j];
        }

        j++; // for comma

        for(j;s[j]==' ';j++);

        if(oper=="discount")
            for(j;s[j]!=',';j++)
                dur+=s[j];
        else
            for(j;s[j]!=',';j++)
                item+=s[j];
        j++;

        for(j;s[j]==' ';j++);

        for(j;j<s.size();j++)
            q+=s[j];

        int tm=stoi(times);
        int q2=stoi(q);

        data d;
        d.tm=tm;
        d.item=item;
        d.oper=oper;
        d.q=q2;
        if(oper=="discount")
        {
            int dur1=stoi(dur);
            d.dur=dur1;
        }

        arr.push_back(d);
    }

    debug(hm);

    sort(arr.begin(),arr.end(),compare);

    for(auto val:arr)
    {
        cout<<val.oper<<" "<<val.tm<<" ";
        if(val.oper=="discount")
            cout<<val.dur<<" ";
        else
            cout<<val.item<<" ";
        cout<<val.q<<endl;
    }
    int ans=0;
    int disTime=0;
    int disPer=0;

    map<string,int> hm2;

    for(i=0;i<arr.size();i++)
    {
        data d=arr[i];

        if(d.oper=="supply")
        {
            hm2[d.item]+=d.q;
        }
        else if(d.oper=="sell")
        {
            int cost=hm[d.item];
            if(hm2[d.item]<d.q)
                continue;
            hm2[d.item]-=d.q;
            if(d.tm<=disTime)
            {
                cost=(cost*(100-disPer)+99)/100;
            }

            int ttcost=cost*d.q;
            ans+=ttcost;
        }
        else
        {
            disTime=d.tm+d.q-1;
            disPer=d.q;
        }
    }
    
    return ans;
}

void solve()
{
    ll n,i,m;
    cin>>n;
    cin>>m;
    vector<string> pr(n),log(m);
    cin.ignore();
    fo(i,n)
    {
        string s;
        getline(cin,s);
        pr[i]=s;
    }

    fo(i,m)
    {
        string s;
        getline(cin,s);
        log[i]=s;
    }
    cout<<storeItemsTracker2(pr,log);

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