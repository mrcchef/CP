#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll int
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

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,i;
        cin>>n;
        string S;
        ll ans[n];
        cin>>S;
        set<ll> s[2];
        s[0].clear();
        s[1].clear();
        fo(i,n)
        {
            if(S[i]=='0')
                s[0].insert(i);
            else
                s[1].insert(i);
        }
        ll st=-1,sub=1;
        while(!s[0].empty() && !s[1].empty())
        {
            if(*s[0].begin()>*s[1].begin())
                st=1;
            else
                st=0;
            ll cur=-1;   
            while(true)
            {
                auto it=lower_bound(s[st].begin(),s[st].end(),cur);
                if(it==s[st].end())
                    break;
                cur=*it;
                ans[cur]=sub;
                s[st].erase(it);
                st=1-st;
            }
            sub++;
        }
        while(!s[0].empty())
        {
            auto it=s[0].begin();
            ans[*it]=sub++;
            s[0].erase(it);
        }
        while (!s[1].empty())
        {
            auto it=s[1].begin();
            ans[*it]=sub++;
            s[1].erase(it);
        }
        sub--;
        cout<<sub<<endl;
        fo(i,n)
            cout<<ans[i]<<" ";
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