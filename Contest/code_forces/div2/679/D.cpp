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
        ll n;
        cin>>n;
        ll plus=0,minus=0,prev=-1,len=0,pos=0,flag=0;
        ll freq[n+1]={0};
        ll ans[n]={0};
        // mii m;
        set<ll> s;
        for(ll i=0;i<2*n;i++)
        {
            char x;
            cin>>x;
            if(x=='+')
            {
                plus++;
                s.insert(pos);
                pos++;
                if(prev!=-1)
                    len++;
            }
            else
            {
                ll cost;
                cin>>cost;
                minus++;
                if(plus-minus<0)
                {
                    flag=1;
                    break;
                }
                auto it=s.end();
                it--;
                if(prev==-1)
                {
                    prev=cost;
                }
                else
                {
                    if(cost<prev)
                    {
                        if(len==0)
                        {
                            flag=1;
                            break;
                        }
                    }
                    else
                    {
                        if(ans[*it+1]>cost)
                        {
                            flag=1;
                            break;
                        }
                    }
                    
                }
                len=0;
                ans[*it]=cost;
                prev=cost;
                s.erase(*it);
                freq[cost]=1;
                // m[pos-1]=1;
                
            }
        }
        if(flag==1)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        ll p=0;
        auto it=s.begin();
        for(ll i=n;i>=1;i--)
            if(freq[i]==0)
            {
                ans[*it]=i;
                it++;
            }

        for(auto x:ans)
            cout<<x<<" ";
        cout<<endl;
        }
        

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