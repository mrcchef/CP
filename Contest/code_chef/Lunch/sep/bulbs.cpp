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
// 0|1|000|1|00|111|00

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k,i,j;
        string s;
        cin>>n>>k;
        cin>>s;
        vi v1,v2;
        ll cnt=0,flag=0;
        for(i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                cnt++;
                if(i==n-1)
                {
                    v1.pb(cnt);
                }
            }    
            else
            {
                if(flag==0)
                {
                    v1.pb(cnt);
                }
                else
                {
                    v2.pb(cnt);
                }
                cnt=0;
                flag=1;
            }
        }
        sort(v1.begin(),v1.end());
        if(v1.size()==1 && v1[0]==n)
        {
            cout<<0<<endl;
            continue;
        }
        sort(v2.begin(),v2.end());
        ll res=0,rm=v1.size()+2*v2.size()-k;
        i=j=0;
        while(i<v1.size() && j<v2.size() && rm>0)
        {
            ll val1,val2;
            if(i+1<v1.size() && rm>1)
            {
                val1=v1[i]+v1[i+1];
                val2=v2[j];
                if(val1<val2)
                {
                    i+=2;
                    res+=val1;
                }
                else
                {
                    j+=1;
                    res+=val2;
                }
                rm-=2;
            } 
            else if(i+1==v1.size() && rm>1)
            {
                val2=v2[j];
                j+=1;
                res+=val2;
                rm-=2;
                
            }
            else if(rm==1)
            {
                val1=v1[i];
                val2=v2[j];
                if(val1<val2)
                {
                    i+=1;
                    res+=val1;
                }
                else
                {
                    j+=1;
                    res+=val2;
                }    
                rm-=1;
            }
        }
        while(i<v1.size() && rm>0)
        {
            res+=v1[i++];
            rm--;
        }
        while(j<v2.size() && rm>0)
        {
            res+=v2[j++];
            rm-=2;
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