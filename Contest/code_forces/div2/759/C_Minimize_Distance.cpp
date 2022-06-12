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

pair<ll,ll> helper(vi &arr1,ll n,ll k,mii &hm)
{
    ll i;
    ll sm=0;
    ll cnt=0;
    ll ans1=0;
    ll lastAdd=-1;
    fo(i,n)
    {
        // sm+=arr1[i];
        debug(i);
        debug(mp(cnt,hm[arr1[i]]));

        if(cnt+hm[arr1[i]]<k)
        {
            cnt+=hm[arr1[i]];
        }
        else if(cnt+hm[arr1[i]]==k)
        {
            if(i==n-1)
            {
                ans1+=arr1[i];
                lastAdd=arr1[i];
            }
            else
            {
                ans1+=2*arr1[i];
            }
            cnt=0;
        }
        else if(hm[arr1[i]]>k)
        {
            ll q=hm[arr1[i]]/k;
            ll rem=hm[arr1[i]]%k;
            ll contri=0;
            if(cnt==0)
            {
                contri=q*2*arr1[i];
                cnt=rem;
                if(cnt==0)
                {
                    if(i==n-1)
                    {
                        contri-=arr1[i];
                        lastAdd=arr1[i];
                    }
                }
            }
            else
            {
                ll case1=arr1[i-1]*2;
                case1+=q*2*arr1[i];
                ll q2=(cnt+hm[arr1[i]])/k;
                ll rem2=(cnt+hm[arr1[i]])%k;
                ll case2=q2*2*arr1[i];
                debug(mp(case1,case2));
                if(rem==0 && i==n-1)
                    case1-=arr1[i];
                
                if(rem2==0 && i==n-1)
                    case2-=arr1[i];
                debug(mp(rem,rem2));
                debug(case1+(rem==0)?0:arr1[i]);
                debug(case2+(rem2==0)?0:arr1[i]);
                ll vcase1;
                ll vcase2;
                if(rem!=0)
                {
                    vcase1=case1+arr1[i];
                }
                else if(i!=n-1)
                {
                    vcase1+=arr1[i+1];
                }

                if(rem2!=0)
                {
                    vcase2=case2+arr1[i];
                }
                else if(i!=n-1)
                {
                    vcase2+=arr1[i+1];
                }

                if(vcase1<vcase2)
                {
                    contri=case1;
                    cnt=rem;
                    
                }
                else
                {
                    contri=case2;
                    cnt=rem2;
                }

                if(cnt==0 && i==n-1)
                {
                    lastAdd=arr1[i];
                }
            }
            debug(contri);
            ans1+=contri;
        }
        else
        {
            ans1+=2*arr1[i-1];
            cnt=hm[arr1[i]];
        }
    }

    if(cnt!=0)
    {
        ans1+=arr1[n-1];
        lastAdd=arr1[n-1];
    }
    return {ans1,lastAdd};
}


void solve()
{
    ll n,i,k;
    cin>>n>>k;
    vi v(n);
    fo(i,n)
        cin>>v[i];

    vi arr1; //-ive
    vi arr2; // +ive
    mii hm1,hm2;
    fo(i,n)
    {
        if(v[i]<0)
        {
            if(hm1[-v[i]]==0)
                arr1.pb(-v[i]);
            hm1[-v[i]]++;
        }
        else
        {
            if(hm2[v[i]]==0)
                arr2.pb(v[i]);
            hm2[v[i]]++;
        }
    }

    sort(all(arr1));
    sort(all(arr2));

    debug(arr1);
    debug(arr2);
    
    pii ans1=helper(arr1,arr1.size(),k,hm1);
    pii ans2=helper(arr2,arr2.size(),k,hm2);
    debug(mp(ans1,ans2));
    ll ans=ans1.first+ans2.first;

    if(arr1.size()==0)
    {

    }
    else if(arr2.size()==0)
    {

    }
    else
    {
        ll lastAdd1=ans1.second;
        ll lastAdd2=ans2.second;
        if(lastAdd1<lastAdd2)
        {
            ans+=lastAdd1;
        }
        else
            ans+=lastAdd2;
    }
    

    cout<<ans<<endl;
}

int main()
{
    fastio
    #ifdef ONLINE_JUDGE
         freopen("Error.txt", "w", stderr);
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