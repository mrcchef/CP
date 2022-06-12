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
        ll n,i,k,flag=1;
        cin>>n>>k;
        string s1,s2;
        cin>>s1>>s2;
        map<char,ll> m1,m2;
        fo(i,n)
        {
            m1[s1[i]]++;
            m2[s2[i]]++;
        }
        for(auto it=m2.begin();it!=m2.end();it++)
        {
            if(m1[it->first]==0)
            {
                m1[it->first]=0;
            }
        }
        for(auto it=m1.begin();it!=m1.end();it++)
        {
            ll rem=m2[it->first]-it->second;
            // deb(rem);
            if(rem<0)
            {
                if(abs(rem)%k==0)
                {
                    auto temp=next(it,1);
                    if(temp!=m1.end())
                    {
                        // deb(temp->first);
                        temp->second+=abs(rem);
                    }
                }
                else
                {
                    flag=0;
                    break;
                }
                
            }
            else if(rem>0)
            {
                flag=0;
                break;
            }

        }
        
            if(flag==0)
            {
                cout<<"No";
            }
            else
            {
                cout<<"Yes";
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