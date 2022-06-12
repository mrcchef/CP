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
 
bool compare(string s1,string s2)
{
    return s1.size()<s2.size();
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
        string s1,s2;
        cin>>s1>>s2;
        if(s1.size()<s2.size())
        {
            string temp=s1;
            s1=s2;
            s2=temp;
        }
        // vector<string> vs;
        ll i;
        ll n1=s1.size(),n2=s2.size();
        ll found=0;
        for(i=1;i<=n1;i++)
        {
            if(n1%i!=0)
            {
                continue;
            }
            ll flag=0;
            string sub=s1.substr(0,i);

            for(ll j=0;j+i<=n1;j+=i)
            {
                if(sub!=s1.substr(j,i))
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {   
                ll temp=0;
                if(n2%sub.size()!=0)
                    continue;
                for(ll j=0;j+sub.size()<=n2;j+=sub.size())
                {
                    if(sub!=s2.substr(j,sub.size()))
                    {
                        temp=1;
                        break;
                    }
                }
                if(temp==0)
                {
                    found=1;
                    break;
                }
            }
        }

        if(found==0)
        {
            cout<<-1<<endl;
            continue;
        }
        
        ll times=0;
        // ll t1
        // ll t2=n2/res.size();
        times=(n1*n2)/__gcd(n1,n2);
        times=times/n2;
        string finl;
 
        fo(i,times)
            finl+=s2;
 
        cout<<finl<<endl;
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