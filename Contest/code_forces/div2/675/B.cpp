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
    int t;
    cin>>t;
    while(t--)
    {
        ll r,c,i,j;
        cin>>r>>c;
        ll a[r][c];
        fo(i,r)
        {
            fo(j,c)
                cin>>a[i][j];
        }

        ll ans=0;
        // if(r==1 && c==1)
        // {

        // }
        // else if(r==1)
        // {
        //     for(j=0;j<c/2;j++)
        //     {
        //         ll val=(a[0][j]+a[0][c-1-j])/2;
        //         ans+=abs(a[0][j]-val)+abs(a[0][c-i-j]-val);
        //     }
        // }
        for(i=0;i<r/2;i++)
        {
            for(j=0;j<c/2;j++)
            {
                vi v;
                v.pb(a[i][j]);
                v.pb(a[i][c-1-j]);
                v.pb(a[r-1-i][j]);
                v.pb(a[r-1-i][c-1-j]);
                sort(v.begin(),v.end());
                ll flag=1,val;
                for(ll k=0;k+1<v.size();k++)
                {
                    if(v[k]==v[k+1])
                    {
                        val=v[k];
                        flag=0;
                    }   
                }
                if(flag==1)
                {
                    val=v[1]+1;
                }
                for(ll k=0;k<v.size();k++)
                {
                    ans+=abs(v[k]-val);
                    
                }
                // deb(ans);
            }

        }
        // deb(ans);
        // if(r==1 && c!=1)
        // {
        //     i=0;
        //     for(j=0;j<c/2;j++)
        //     {
        //         ll val=(a[i][j]+a[i][c-1-j])/2;
        //         ans+=abs(a[i][j]-val)+abs(a[i][c-i-j]-val);
        //     }
        // }
        // else if(c==1 && r!=1)
        // {
        //      i=0;
        //     for(j=0;j<r/2;j++)
        //     {
        //         ll val=(a[j][i]+a[r-1-j][i])/2;
        //         ans+=abs(a[j][i]-val)+abs(a[r-1-j][i]-val);
        //     }
        // }
        // else
        // {
            
        // }
        
        if(r&1)
        {
            i=r/2;
            ll limit;
            if(c==1)
                limit=1;
            else
            {
                limit=c/2;
            }
            for(j=0;j<c/2;j++)
            {
                ll val=(a[i][j]+a[i][c-1-j])/2;
                ans+=abs(a[i][j]-val)+abs(a[i][c-1-j]-val);
            }
        }
        if(c&1)
        {
            i=c/2;
            ll limit;
            if(r==1)
                limit=1;
            else
            {
                limit=r/2;
            }
            
            for(j=0;j<limit;j++)
            {
                ll val=(a[j][i]+a[r-1-j][i])/2;
                ans+=abs(a[j][i]-val)+abs(a[r-1-j][i]-val);
            }
        }
        cout<<ans<<endl;

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