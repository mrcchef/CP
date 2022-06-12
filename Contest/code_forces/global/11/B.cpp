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

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

bool check(string s,ll cnt[],ll mid,ll k)
{

    for(ll i=1;i+mid<=s.size();i++)
    {
        if(cnt[i+mid-1]-cnt[i-1]<=k)
            return true;
    }
    return false;
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
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        s+='*';
        for(ll i=n-1;i>=0;i--)
            s[i+1]=s[i];
        s[0]=' ';
        ll cnt[s.size()]={0};
        
        for(ll i=1;i<=n;i++)
        {
            cnt[i]=cnt[i-1]+(s[i]=='L');
        }
        // for(auto x:cnt)
        //     cout<<x<<" ";
        // cout<<endl;
        ll ans=0,st=1,ed=s.size();
        while(st<=ed)
        {
            ll mid=(st+ed)/2;
            // deb(st);
            // deb(ed);
            // deb(mid);
            if(check(s,cnt,mid,k))
            {
                ans=max(ans,mid);
                st=mid+1;
            }
            else
            {
                ed=mid-1;
            }
            
        }
        // deb(ans);
        for(ll i=1;i+ans<=s.size();i++)
        {   
            if(cnt[i+ans-1]-cnt[i-1]<=k)
            {
                // cout<<"IN"<<endl;
                for(ll j=i;j<i+ans;j++)
                {
                    s[j]='W';
                }
                break;
            }
        }
        // deb(s);
        ll res=0;
        for(ll i=1;i<s.size();i++)
        {
            if(s[i]=='W')
            {
                if(i==1)
                    res+=1;
                else
                {
                    if(s[i-1]=='W')
                        res+=2;
                    else
                        res+=1;
                }
            }
        }
        cout<<res<<endl;

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