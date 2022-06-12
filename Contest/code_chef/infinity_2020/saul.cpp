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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,i,k;
        cin>>n>>k;
        ll cnto=0,cnte=0;
        fo(i,n)
        {
            ll x;
            cin>>x;
            if(x&1)
            {
                cnto++;
            }
            else
                cnte++;
        }
        ll mv=1;
        fo(i,k)
        {
            if(mv==1)
            {
                    if(i==k-2 && cnte==1)
                    {
                        if(cnto==0 || !(cnto&1))
                        {
                            cnte--;
                            mv=mv*-1;
                            continue;
                        }
                    }
                    if(cnto>0 && (cnto&1))
                    {
                        if(cnte>0)
                        {
                            cnte--;
                        }
                        else
                        {
                        cnto--;
                        }
                        mv=mv*-1;
                    }
                    else if(cnto>0 && !(cnto&1))
                    {
                        cnto--;
                        mv=mv*-1;
                    }
                    else
                    {
                        cnte--;
                        mv=mv*-1;
                    }
            }
            else
            {
                if(i==k-3 && (cnto&1) && (cnte==1))
                {
                    cnte--;
                    mv=mv*-1;
                    continue;
                }
                if(cnto>0 && (cnto&1))
                {
                    cnto--;
                }
                else if(cnto>0 && !(cnto&1))
                {
                    if(cnte>0)
                    {
                        cnte--;
                    }
                    else
                        cnto--;
                }
                else
                {
                    cnte--;
                }
                
                     mv=mv*-1;
            }
        }
        // deb(cnto);
        // deb(cnte);
        if(cnto&1)
        {
            cout<<"Walter";
        }
        else
        {
            cout<<"Jesse";
        }
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