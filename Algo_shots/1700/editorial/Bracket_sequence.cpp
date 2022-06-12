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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        ll sz=s.size()+1;
        s+='*';
        // deb(s);
        for(ll i=s.size()-1;i>=0;i--)
        {
            s[i+1]=s[i];
        }
        s[0]=' ';
        // deb(s);
        ll *cnt=new ll[sz]{0};
        vector<ll>  st(100004,0);
        ll res=0,l=0,r=0,k=0;
        for(ll i=1;i<sz;i++)
        {
            cnt[i]=cnt[i-1];
            if(s[i]=='(' || s[i]=='[')
            {
                st[k++]=i;
                if(s[i]=='[')
                    cnt[i]+=1;
            }
            else if(k==0 || (s[i]==')' && s[st[k-1]]!='(') || (s[i]==']' && s[st[k-1]]!='['))
            {
                k=0;
            }
            else
            {
                if(k==0)
                    continue;
                k--;
                if(res<cnt[i]-cnt[st[k]-1])
                {
                    l=st[k];
                    r=i;
                    res=cnt[i]-cnt[st[k]-1];
                }
            }   
        }
        // deb(l),deb(r);
        cout<<res<<endl;
        cout<<s.substr(l,r-l+1);
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