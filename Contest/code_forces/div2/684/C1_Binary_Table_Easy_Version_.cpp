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
        ll n,i,j,m;
        cin>>n>>m;
        ll arr[n+1][m+1];
        vi res[3*n*m];
        for(i=1;i<=n;i++)
        {
            string s;
            cin>>s;
            for(j=1;j<=m;j++)
            {
                arr[i][j]=s[j-1]-'0';
            }
        }
        ll cnt=0;
        for(i=1;i+1<=n;i+=2)
        {
            for(j=1;j+1<=m;j+=2)
            {
                vector<pair<ll,ll>> one,zero;
                if(arr[i][j]==1)
                    one.pb({i,j});
                else
                {
                    zero.pb({i,j});
                }
                if(arr[i+1][j]==1)
                    one.pb({i+1,j});
                else
                {
                    zero.pb({i+1,j});
                }
                if(arr[i][j+1]==1)
                    one.pb({i,j+1});
                else
                {
                    zero.pb({i,j+1});
                }
                if(arr[i+1][j+1]==1)
                    one.pb({i+1,j+1});
                else
                {
                    zero.pb({i+1,j+1});
                }
                if(one.size()==3)
                {
                    for(auto p:one)
                    {
                        res[cnt].pb(p.first);
                        res[cnt].pb(p.second);
                    }
                    cnt++;
                }
                else if(one.size()==2)
                {
                    for(auto p:zero)
                    {
                        res[cnt].pb(p.first);
                        res[cnt].pb(p.second);
                    }
                    res[cnt].pb(one[0].first);
                    res[cnt].pb(one[0].second);
                    cnt++;
                    for(auto p:zero)
                    {
                        res[cnt].pb(p.first);
                        res[cnt].pb(p.second);
                    }
                    res[cnt].pb(one[1].first);
                    res[cnt].pb(one[1].second);
                    cnt++;
                }
                else if(one.size()==1)
                {
                    res[cnt].pb(one[0].first);
                    res[cnt].pb(one[0].second);
                    res[cnt].pb(zero[0].first);
                    res[cnt].pb(zero[0].second);
                    res[cnt].pb(zero[1].first);
                    res[cnt].pb(zero[1].second);
                    cnt++;
                    res[cnt].pb(one[0].first);
                    res[cnt].pb(one[0].second);
                    res[cnt].pb(zero[0].first);
                    res[cnt].pb(zero[0].second);
                    res[cnt].pb(zero[2].first);
                    res[cnt].pb(zero[2].second);
                    cnt++;
                    res[cnt].pb(one[0].first);
                    res[cnt].pb(one[0].second);
                    res[cnt].pb(zero[1].first);
                    res[cnt].pb(zero[1].second);
                    res[cnt].pb(zero[2].first);
                    res[cnt].pb(zero[2].second);
                    cnt++;
                }
                else if(one.size()==4) 
                {
                    res[cnt].pb(one[0].first);
                    res[cnt].pb(one[0].second);
                    res[cnt].pb(one[1].first);
                    res[cnt].pb(one[1].second);
                    res[cnt].pb(one[2].first);
                    res[cnt].pb(one[2].second);
                    cnt++;
                    res[cnt].pb(one[0].first);
                    res[cnt].pb(one[0].second);
                    res[cnt].pb(one[1].first);
                    res[cnt].pb(one[1].second);
                    res[cnt].pb(one[3].first);
                    res[cnt].pb(one[3].second);
                    cnt++;
                    res[cnt].pb(one[0].first);
                    res[cnt].pb(one[0].second);
                    res[cnt].pb(one[2].first);
                    res[cnt].pb(one[2].second);
                    res[cnt].pb(one[3].first);
                    res[cnt].pb(one[3].second);
                    cnt++;
                    res[cnt].pb(one[3].first);
                    res[cnt].pb(one[3].second);
                    res[cnt].pb(one[1].first);
                    res[cnt].pb(one[1].second);
                    res[cnt].pb(one[2].first);
                    res[cnt].pb(one[2].second);
                    cnt++;
                }
                arr[i][j]=arr[i][j+1]=arr[i+1][j]=arr[i+1][j+1]=0;
                
            }

            if(m&1)
            {
                vector<pair<ll,ll>> one,zero;
                j=m-1;
                if(arr[i][j]==1)
                    one.pb({i,j});
                else
                {
                    zero.pb({i,j});
                }
                if(arr[i+1][j]==1)
                    one.pb({i+1,j});
                else
                {
                    zero.pb({i+1,j});
                }
                if(arr[i][j+1]==1)
                    one.pb({i,j+1});
                else
                {
                    zero.pb({i,j+1});
                }
                if(arr[i+1][j+1]==1)
                    one.pb({i+1,j+1});
                else
                {
                    zero.pb({i+1,j+1});
                }
                if(one.size()==3)
                {
                    for(auto p:one)
                    {
                        res[cnt].pb(p.first);
                        res[cnt].pb(p.second);
                    }
                    cnt++;
                }
                else if(one.size()==2)
                {
                    for(auto p:zero)
                    {
                        res[cnt].pb(p.first);
                        res[cnt].pb(p.second);
                    }
                    res[cnt].pb(one[0].first);
                    res[cnt].pb(one[0].second);
                    cnt++;
                    for(auto p:zero)
                    {
                        res[cnt].pb(p.first);
                        res[cnt].pb(p.second);
                    }
                    res[cnt].pb(one[1].first);
                    res[cnt].pb(one[1].second);
                    cnt++;
                }
                else if(one.size()==1)
                {
                    res[cnt].pb(one[0].first);
                    res[cnt].pb(one[0].second);
                    res[cnt].pb(zero[0].first);
                    res[cnt].pb(zero[0].second);
                    res[cnt].pb(zero[1].first);
                    res[cnt].pb(zero[1].second);
                    cnt++;
                    res[cnt].pb(one[0].first);
                    res[cnt].pb(one[0].second);
                    res[cnt].pb(zero[0].first);
                    res[cnt].pb(zero[0].second);
                    res[cnt].pb(zero[2].first);
                    res[cnt].pb(zero[2].second);
                    cnt++;
                    res[cnt].pb(one[0].first);
                    res[cnt].pb(one[0].second);
                    res[cnt].pb(zero[1].first);
                    res[cnt].pb(zero[1].second);
                    res[cnt].pb(zero[2].first);
                    res[cnt].pb(zero[2].second);
                    cnt++;
                }
                else if(one.size()==4) 
                {
                    res[cnt].pb(one[0].first);
                    res[cnt].pb(one[0].second);
                    res[cnt].pb(one[1].first);
                    res[cnt].pb(one[1].second);
                    res[cnt].pb(one[2].first);
                    res[cnt].pb(one[2].second);
                    cnt++;
                    res[cnt].pb(one[0].first);
                    res[cnt].pb(one[0].second);
                    res[cnt].pb(one[1].first);
                    res[cnt].pb(one[1].second);
                    res[cnt].pb(one[3].first);
                    res[cnt].pb(one[3].second);
                    cnt++;
                    res[cnt].pb(one[0].first);
                    res[cnt].pb(one[0].second);
                    res[cnt].pb(one[2].first);
                    res[cnt].pb(one[2].second);
                    res[cnt].pb(one[3].first);
                    res[cnt].pb(one[3].second);
                    cnt++;
                    res[cnt].pb(one[3].first);
                    res[cnt].pb(one[3].second);
                    res[cnt].pb(one[1].first);
                    res[cnt].pb(one[1].second);
                    res[cnt].pb(one[2].first);
                    res[cnt].pb(one[2].second);
                    cnt++;
                }
                arr[i][j]=arr[i+1][j]=arr[i][j+1]=arr[i+1][j+1]=0;
            
            }
        }
        // deb(cnt);
        if(n&1)
        {
            i=n-1;
            for(j=1;j+1<=m;j+=2)
            {
                vector<pair<ll,ll>> one,zero;
                if(arr[i][j]==1)
                    one.pb({i,j});
                else
                {
                    zero.pb({i,j});
                }
                if(arr[i+1][j]==1)
                    one.pb({i+1,j});
                else
                {
                    zero.pb({i+1,j});
                }
                if(arr[i][j+1]==1)
                    one.pb({i,j+1});
                else
                {
                    zero.pb({i,j+1});
                }
                if(arr[i+1][j+1]==1)
                    one.pb({i+1,j+1});
                else
                {
                    zero.pb({i+1,j+1});
                }
                // deb(one.size());
                // deb(zero.size());
                if(one.size()==0)
                {
                    continue;
                }
                else if(one.size()==3)
                {
                    for(auto p:one)
                    {
                        res[cnt].pb(p.first);
                        res[cnt].pb(p.second);
                    }
                    cnt++;
                    // cout<<cnt<<" "<<one.size()<<endl;
                }
                else if(one.size()==2)
                {
                    for(auto p:zero)
                    {
                        res[cnt].pb(p.first);
                        res[cnt].pb(p.second);
                    }
                    res[cnt].pb(one[0].first);
                    res[cnt].pb(one[0].second);
                    cnt++;
                    for(auto p:zero)
                    {
                        res[cnt].pb(p.first);
                        res[cnt].pb(p.second);
                    }
                    res[cnt].pb(one[1].first);
                    res[cnt].pb(one[1].second);
                    cnt++;
                    // cout<<cnt<<" "<<one.size()<<" "<<zero.size()<<endl;
                }
                else if(one.size()==1)
                {
                    res[cnt].pb(one[0].first);
                    res[cnt].pb(one[0].second);
                    res[cnt].pb(zero[0].first);
                    res[cnt].pb(zero[0].second);
                    res[cnt].pb(zero[1].first);
                    res[cnt].pb(zero[1].second);
                    cnt++;
                    res[cnt].pb(one[0].first);
                    res[cnt].pb(one[0].second);
                    res[cnt].pb(zero[0].first);
                    res[cnt].pb(zero[0].second);
                    res[cnt].pb(zero[2].first);
                    res[cnt].pb(zero[2].second);
                    cnt++;
                    res[cnt].pb(one[0].first);
                    res[cnt].pb(one[0].second);
                    res[cnt].pb(zero[1].first);
                    res[cnt].pb(zero[1].second);
                    res[cnt].pb(zero[2].first);
                    res[cnt].pb(zero[2].second);
                    cnt++;
                    // cout<<cnt<<" "<<one.size()<<endl;
                }
                else if(one.size()==4) 
                {
                    res[cnt].pb(one[0].first);
                    res[cnt].pb(one[0].second);
                    res[cnt].pb(one[1].first);
                    res[cnt].pb(one[1].second);
                    res[cnt].pb(one[2].first);
                    res[cnt].pb(one[2].second);
                    cnt++;
                    res[cnt].pb(one[0].first);
                    res[cnt].pb(one[0].second);
                    res[cnt].pb(one[1].first);
                    res[cnt].pb(one[1].second);
                    res[cnt].pb(one[3].first);
                    res[cnt].pb(one[3].second);
                    cnt++;
                    res[cnt].pb(one[0].first);
                    res[cnt].pb(one[0].second);
                    res[cnt].pb(one[2].first);
                    res[cnt].pb(one[2].second);
                    res[cnt].pb(one[3].first);
                    res[cnt].pb(one[3].second);
                    cnt++;
                    res[cnt].pb(one[3].first);
                    res[cnt].pb(one[3].second);
                    res[cnt].pb(one[1].first);
                    res[cnt].pb(one[1].second);
                    res[cnt].pb(one[2].first);
                    res[cnt].pb(one[2].second);
                    cnt++;
                    // cout<<cnt<<" "<<one.size()<<endl;
                }
                
                arr[i][j]=arr[i+1][j]=arr[i][j+1]=arr[i+1][j+1]=0;
            }
        }

        if((n&1) && (m&1))
        {
            i=n-1;
            j=m-1;
            vector<pair<ll,ll>> one,zero;
                if(arr[i][j]==1)
                    one.pb({i,j});
                else
                {
                    zero.pb({i,j});
                }
                if(arr[i+1][j]==1)
                    one.pb({i+1,j});
                else
                {
                    zero.pb({i+1,j});
                }
                if(arr[i][j+1]==1)
                    one.pb({i,j+1});
                else
                {
                    zero.pb({i,j+1});
                }
                if(arr[i+1][j+1]==1)
                    one.pb({i+1,j+1});
                else
                {
                    zero.pb({i+1,j+1});
                }
                // deb(one.size());
                // deb(zero.size());
                if(one.size()==0)
                {
                    continue;
                }
                else if(one.size()==3)
                {
                    for(auto p:one)
                    {
                        res[cnt].pb(p.first);
                        res[cnt].pb(p.second);
                    }
                    cnt++;
                    // cout<<cnt<<" "<<one.size()<<endl;
                }
                else if(one.size()==2)
                {
                    for(auto p:zero)
                    {
                        res[cnt].pb(p.first);
                        res[cnt].pb(p.second);
                    }
                    res[cnt].pb(one[0].first);
                    res[cnt].pb(one[0].second);
                    cnt++;
                    for(auto p:zero)
                    {
                        res[cnt].pb(p.first);
                        res[cnt].pb(p.second);
                    }
                    res[cnt].pb(one[1].first);
                    res[cnt].pb(one[1].second);
                    cnt++;
                    // cout<<cnt<<" "<<one.size()<<" "<<zero.size()<<endl;
                }
                else if(one.size()==1)
                {
                    res[cnt].pb(one[0].first);
                    res[cnt].pb(one[0].second);
                    res[cnt].pb(zero[0].first);
                    res[cnt].pb(zero[0].second);
                    res[cnt].pb(zero[1].first);
                    res[cnt].pb(zero[1].second);
                    cnt++;
                    res[cnt].pb(one[0].first);
                    res[cnt].pb(one[0].second);
                    res[cnt].pb(zero[0].first);
                    res[cnt].pb(zero[0].second);
                    res[cnt].pb(zero[2].first);
                    res[cnt].pb(zero[2].second);
                    cnt++;
                    res[cnt].pb(one[0].first);
                    res[cnt].pb(one[0].second);
                    res[cnt].pb(zero[1].first);
                    res[cnt].pb(zero[1].second);
                    res[cnt].pb(zero[2].first);
                    res[cnt].pb(zero[2].second);
                    cnt++;
                    // cout<<cnt<<" "<<one.size()<<endl;
                }
                else if(one.size()==4) 
                {
                    res[cnt].pb(one[0].first);
                    res[cnt].pb(one[0].second);
                    res[cnt].pb(one[1].first);
                    res[cnt].pb(one[1].second);
                    res[cnt].pb(one[2].first);
                    res[cnt].pb(one[2].second);
                    cnt++;
                    res[cnt].pb(one[0].first);
                    res[cnt].pb(one[0].second);
                    res[cnt].pb(one[1].first);
                    res[cnt].pb(one[1].second);
                    res[cnt].pb(one[3].first);
                    res[cnt].pb(one[3].second);
                    cnt++;
                    res[cnt].pb(one[0].first);
                    res[cnt].pb(one[0].second);
                    res[cnt].pb(one[2].first);
                    res[cnt].pb(one[2].second);
                    res[cnt].pb(one[3].first);
                    res[cnt].pb(one[3].second);
                    cnt++;
                    res[cnt].pb(one[3].first);
                    res[cnt].pb(one[3].second);
                    res[cnt].pb(one[1].first);
                    res[cnt].pb(one[1].second);
                    res[cnt].pb(one[2].first);
                    res[cnt].pb(one[2].second);
                    cnt++;
                    // cout<<cnt<<" "<<one.size()<<endl;
                }
                
                arr[i][j]=arr[i+1][j]=arr[i][j+1]=arr[i+1][j+1]=0;
        }
        cout<<cnt<<endl;
        // ll cnt=0;
        fo(i,cnt)
        {
            fo(j,res[i].size())
            {
                cout<<res[i][j]<<" ";
            }
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