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
        ll n,i;
        cin>>n;
        string s;
        cin>>s;
        ll gold=0,silver=0;
        fo(i,n)
        {
            if(s[i]=='G')
            {
                gold++;
            }
            else
                silver++;
        }

        ll len=0,g1=0,g2=0,S=0,j=0;
        fo(i,n)
        {
            if(s[i]=='G' && S==0)
                g1++;
            else if(s[i]=='G' && S==1)
            {
                g2++;
            }
            else
            {
                S++;
            }

            if(S>1)
            {
                if(g1+g2<gold)
                {
                    len=max(len,i-j);
                }
                else
                {
                    len=max(len,g1+g2);
                }

                while(s[j]=='G')
                {
                    j++;
                }
                j++;
                S=1;
                g1=g2;
                g2=0;
            }  
        } 
        if(g1+g2<gold)
        {
            len=max(len,i-j);
        }
        else
        {
            len=max(len,g1+g2);
        }
        cout<<len<<endl;
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