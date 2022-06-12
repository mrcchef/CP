#include <bits/stdc++.h>
using namespace std;
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

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

ll subtask(ll a,ll b,ll c)
{
    if(b>a && b>c)
        return 1;
    else if(b<a && b<c)
        return 1;
    return 0;
}

ll check(ll a,ll b,ll c,ll d,ll e)
{
    ll cnt=0;
    cnt+=subtask(a,b,c);
    cnt+=subtask(b,c,d);
    cnt+=subtask(c,d,e);
    return cnt;
}

ll perform(ll i,ll n,vi &v)
{
    ll val=0;
                if(i>1 && i<n-2)
                    val=check(v[i-2],v[i-1],v[i],v[i+1],v[i+2]);
                else if(i==1 && i==n-2)
                {
                    val=subtask(v[i-1],v[i],v[i+1]);
                }
                else if(i>1)
                {
                    val=subtask(v[i-1],v[i],v[i+1]);
                    val+=subtask(v[i-2],v[i-1],v[i]);
                }
                else
                {
                    val=subtask(v[i-1],v[i],v[i+1]);
                    val+=subtask(v[i],v[i+1],v[i+2]);
                }
    return val;
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
        // deb(t);
        ll n,i;
        cin>>n;
        vi v(n);
        fo(i,n)
            cin>>v[i];
        // ll check[n]={0};
        ll cnt=0;
        
        ll sub=0,temp=0;
        for(i=1;i<=n-2;i++)
        {
            if(subtask(v[i-1],v[i],v[i+1]))
            {
                ll original=perform(i,n,v);
                ll val=v[i];
                v[i]=v[i-1];
                ll op1=perform(i,n,v);
                v[i]=v[i+1];
                ll op2=perform(i,n,v);
                v[i]=val;

                sub=max(sub,original-min(op1,op2));
                cnt++;
            }
        }
      
        cout<<cnt-sub<<endl;
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
