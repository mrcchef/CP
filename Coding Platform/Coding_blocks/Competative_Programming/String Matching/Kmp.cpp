#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0) ; cout.tie(0);
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<=n;i++)
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define endl "\n"
#define deb(x) cout << #x << "=" << x << endl
const ll mod = 1e9+7;
#define popcount(x) __builtin_popcount(x)
#define all(x) x.begin(),x.end()
#define mem(a,v) memset(a,v,sizeof(a))

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}
// TC --> O(N^3) brute force
vi build_lps(string s)
{
    ll n=s.size();
    vi lps(n);
    lps[0]=0;
    for(ll i=0;i<n;i++)
    {
        for(ll len=0;len<i;len++)
        {
            if(s.substr(0,len)==s.substr(i-len+1,len))
            {
                lps[i]=len;
            }
        }
    }
    return lps;
}
// TC --> O(N)
vi build_lps_efficient(string s)
{
    ll n=s.size();
    vi lps(n);
    lps[0]=0;
    ll i=1,j=0;
    while(i<n)
    {
        if(s[i]==s[j])
        {
            lps[i]=j+1;
            i++;
            j++;
        }
        else
        {
            if(j==0)
            {
                lps[i]=0;
                i++;
            }
            else
            {
                j=lps[j-1]; // longest prefix of the sequence equal to the suffix of the squence
            }
        }
    }
    return lps;
}

vi kmp(string text,string pattern)
{
        ll n=text.size(),m=pattern.size();
        vi lps=build_lps_efficient(pattern);
        vi occurances;
        ll j=0,i=0;

        while(i<n)
        {
            if(text[i]==pattern[j])
            {
                i++;
                j++;
            }
            else
            {
                if(j==0)
                {
                    i++;
                }
                else
                {
                    j=lps[j-1];
                }
            }
            if(j==m)
            {
                j=lps[j-1];  
                // we fonund a occurance and now we again have to seach for another occurance 
                // and for that best choice is to move to next longest mattring prifix of pattern
                occurances.pb(i-m);
            }
        }

        return occurances;
}

vi kmp_lps(string text,string pattern)
{
    string good=pattern+'$'+text;
    ll n=text.size();
    ll m=pattern.size();
    vi lps=build_lps_efficient(good);
    for(auto ch:good)
        cout<<ch<<" ";
    cout<<endl;
    for(auto val:lps)
        cout<<val<<" ";
    cout<<endl;
    vi occurances;
    for(ll i=m+1;i<lps.size();i++)
    {
        if(lps[i]==m)
        {
            ll in=(i-m+1)-(m+1);
            occurances.pb(in);
        }
    }
    // for()
    return occurances;

}

int main()
{
    fastio
    int t=1;
    // cin>>t;
    while(t--)
    {
        string text,pattern;
        cin>>text>>pattern;
        // vi lps=build_lps_efficient(s);
        vi lps=build_lps_efficient(pattern);
        // for(auto ch:pattern)
        //     cout<<ch<<" ";
        // cout<<endl;
        // for(auto val:lps)
        //     cout<<val<<" ";
        // cout<<endl;
        
        vi occurances=kmp_lps(text,pattern);

        for(auto val:occurances)
            cout<<val<<" ";
        cout<<endl;



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