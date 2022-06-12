#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0) ; cout.tie(0);
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
#define popcount(x) __builtin_popcount(x)
#define all(x) x.begin(),x.end()
#define mem(a,v) memset(a,v,sizeof(a))

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

void output(ll n,ll in1,ll in2)
{
    ll i;
    cout<<"YES"<<endl;
    fo(i,n+1)
    {
        if(i%2==0)
        {
            cout<<in1<<" ";
        }
        else 
            cout<<in2<<" ";
    }
    cout<<endl;
    return;
}


void solve()
{
    ll n,i,m;
    cin>>n>>m;
    vector<string> vs(n);
    fo(i,n)
        cin>>vs[i];
    
    if(m&1)
    {
        output(m,1,2);
    }
    else
    {
        for(i=0;i<n;i++)
        {
            for(ll j=0;j<n;j++)
            {
                if(i==j)
                    continue;
                if(vs[i][j]==vs[j][i])
                {
                    output(m,i+1,j+1);
                    return ;
                }
            }
        }
        
        vector<vi> ina(n);
        vector<vi> outa(n); 
        for(i=0;i<n;i++)
        {
            for(ll j=0;j<n;j++)
            {
                if(vs[i][j]=='a')
                {
                    ina[j].pb(i);
                    outa[i].pb(j);
                }
            }
            // deb(i);
            // for(auto val:outa[i])
            //     cout<<val<<" ";
            // cout<<endl;
        }

        for(i=0;i<n;i++)
        {
            for(ll j=0;j<n;j++)
            {
                if(vs[i][j]=='a' && (m/2)%2==0)
                {
                    if(ina[i].size()!=0)
                    {
                        cout<<"YES"<<endl;
                        for(ll k=0;k<m/2+1;k++)
                        {
                            if(k%2==0)
                                cout<<i+1<<" ";
                            else
                                cout<<ina[i][0]+1<<" ";
                        }
                        for(ll k=0;k<m/2;k++)
                        {
                            if(k%2==0)
                            {
                                cout<<j+1<<" ";
                            }
                            else
                                cout<<i+1<<" ";
                        }
                        cout<<endl;
                        return;
                    }
                }
                else if(vs[i][j]=='a' && (m/2)%2!=0)
                {
                    if(outa[j].size()!=0)
                    {
                        cout<<"YES"<<endl;
                        for(ll k=0;k<m/2;k++)
                        {
                            if(k%2==0)
                                cout<<i+1<<" ";
                            else
                                cout<<j+1<<" ";
                        }
                        for(ll k=0;k<m/2+1;k++)
                        {
                            if(k%2==0)
                                cout<<j+1<<" ";
                            else
                                cout<<outa[j][0]+1<<" ";
                        }
                        cout<<endl;
                        return;
                    }
                }
            }
        }
        cout<<"NO"<<endl;
        return;
    }
}

int main()
{
    fastio
    int t;
    cin>>t;
    while(t--)
    {
        // init();
        solve();   
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