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
        ll n,k;
        cin>>n>>k;
        vi v;
        ll sz=log2(k)+1;
        ll i=0;
        mii m;
        ll cnt=0;
        map<ll,char> ma;
        char ch='a';
        for(ll j=0;j<=25;j++)
        {
            char va=ch+j;
            ma[j]=va;
            // cout<<j<<" "<<va<<endl;
        }
        while(i<sz)
        {
            if(k&(1<<i))
            {
                m[i]++;
                v.pb(i);
                cnt++;
            }
            i++;
        }

        // for(auto val:v)
        //     cout<<val<<" ";
        ll flag=0;
        if(cnt>n)
        {
            flag=1;
        }
        while(cnt<n)
        {
            if(m.size()==1 && m.count(0))
            {
                flag=1;
                break;
            }
            else
            {
                // ll c=0;
                auto it=m.begin();
                for(;it!=m.end();it++)
                {
                    if(it->first==0)
                        continue;
                    // deb(it->first);
                        m[it->first]--;
                        m[(it->first)-1]+=2;
                        if(m[it->first]==0)
                            m.erase(it->first);
                        cnt++;
                    break;
                    
                }
            }
            
        }

        if(flag==1)
        {
            cout<<-1<<endl;
            continue;
        }

        string res;
        for(auto val:m)
        {
            ll c=val.second;
            for(ll j=0;j<c;j++)
            {
            res+=ma[val.first];
                
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