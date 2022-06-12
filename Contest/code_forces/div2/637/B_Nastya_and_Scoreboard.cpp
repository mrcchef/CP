#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<=n;i++)
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

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

string digits[11];
ll req[2005][11];
ll dp[2005][2005][11];

ll solve(ll i,ll k,ll n,ll d)
{
    // deb(d);
    if(i==n && k==0)
    {
        return dp[i][k][d]=1;
        // return 0;
    }
    if(i==n && k>=0)
        return dp[i][k][d]=0;

    if(dp[i][k][d]!=-1)
        return dp[i][k][d];

    ll j;
    ll val=0;
    fo(j,10)
    {
        if(req[i][j]==-1)
            continue;
        if(req[i][j]>k)
            continue;
        val|=solve(i+1,k-req[i][j],n,j);
    }
    // return val;
    return dp[i][k][d]=val;
}

string ans="";

void findAns(ll i,ll k,ll n)
{
    if(i==n)
        return ;
    ll check=0;
    for(ll j=9;j>=0;j--)
    {
        ll cnt=req[i][j];

        if(k-cnt>=0 && cnt!=-1 && dp[i+1][k-cnt][j]==1)
        {
            check=1;
            ans+=j+48;
            findAns(i+1,k-cnt,n);
            return ;
        }
    }
    if(check==0)
    {
        ans="-1";
        return ;
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll n,k,i;
        cin>>n>>k;
        vector<string> vs(n);
        fo(i,n)
            cin>>vs[i];
        digits[0]="1110111";
        digits[1]="0010010";
        digits[2]="1011101";
        digits[3]="1011011";
        digits[4]="0111010";
        digits[5]="1101011";
        digits[6]="1101111";
        digits[7]="1010010";
        digits[8]="1111111";
        digits[9]="1111011";
        
        memset(dp,-1,sizeof(dp));

        fo(i,n)
        {
            ll j;
            fo(j,10)
            {
                ll l;
                ll cnt=0;
                fo(l,7)
                {
                    if(vs[i][l]==digits[j][l])
                    {
                        continue;
                    }
                    if(vs[i][l]=='1')
                    {
                        cnt=-1;
                        break;
                    }
                    cnt++;
                }
                // cout<<i<<" "<<j<<" "<<cnt<<endl;
                req[i][j]=cnt;
            }
        }
        // vi ans;
        solve(0,k,n,0);
        findAns(0,k,n);
        // if(ans.size()==0)
        // {
        //     cout<<-1<<endl;
        //     return 0;
        // }
        // sort(ans.begin(),ans.end(),greater<ll>());
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
