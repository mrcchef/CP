#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
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

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

string s;

ll cost(ll st,ll ed,char ch)
{
    ll cnt=0;
    for(ll i=st;i<=ed;i++)
        if(s[i]!=ch)
            cnt++;
    // deb(cnt);
    return cnt;
}

ll get_min(ll st,ll ed,char ch)
{
    if(st==ed)
    {
        if(s[st]==ch)
            return 0;
        return 1;
    }
    ll mid=(st+ed)/2;
    return min(cost(st,mid,ch)+get_min(mid+1,ed,ch+1),cost(mid+1,ed,ch)+get_min(st,mid,ch+1));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        // string s;
        cin>>n;
        cin>>s;
        ll res=get_min(0,n-1,'a');
        cout<<res<<endl;
        s.clear();
    }
 return 0;
}
ll fxp(ll a,ll b,ll m) {
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp(a*a,b/2,m);
    return fxp(a,b-1,m)*a;
}
