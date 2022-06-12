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

bool visited[30];
vector<vector<ll>> g(30);
mii char_check;
string ans;


void solve()
{
    ll n,i;
    cin>>n;
    vector<string> vs(n);
    fo(i,n)
        cin>>vs[i];
    
    ll indegree[26]={0};

    fo(i,n-1)
    {
        string s1=vs[i];
        string s2=vs[i+1];
        ll j;
        ll sz=min(s1.size(),s2.size());
        
        for(j=0;j<sz;j++)
        {
            if(s1[j]!=s2[j])
            {
                indegree[s2[j]-'a']++;
                g[s1[j]-'a'].pb(s2[j]-'a');
                break;
            }
        }
        if(j==sz)
        {
            if(s1.size()>sz)
            {
                cout<<"Impossible";
                cout<<endl;
                return;
            }
        }
    }

    stack<ll> st;
    for(i=0;i<26;i++)
    {
        if(indegree[i]==0)
        {
            st.push(i);
            // cout<<(char)(i+'a')<<endl;
        }
    }

    if(st.size()==0)
    {
        cout<<"Impossible";
        return;
    }

    while(!st.empty())
    {
        char ch=st.top();
        st.pop();
        ans+=ch+'a';
        for(i=0;i<g[ch].size();i++)
        {
            indegree[g[ch][i]]--;
            if(indegree[g[ch][i]]==0)
                st.push(g[ch][i]);
        }
    }
    // cout<<"N"<<endl;
    if(ans.size()!=26)
        ans="Impossible";
    cout<<ans<<endl;

}

int main()
{
    fastio
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