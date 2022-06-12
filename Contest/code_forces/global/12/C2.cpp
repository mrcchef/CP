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
        ll n,i,j;
        cin>>n;
        vector<string> v(n);
        fo(i,n)
            cin>>v[i];

        ll cnt[3][2];
        memset(cnt,0,sizeof(cnt));
        ll k=0;

        fo(i,n)
        {
            fo(j,n)
            {
                ll diagonal=(i+j)%3;
                if(v[i][j]=='X')
                {
                    cnt[diagonal][0]++;
                    k++;
                }
                else if(v[i][j]=='O')
                {
                    k++;
                    cnt[diagonal][1]++;
                }
            }
        }

        // ll mn=min_element(cnt,cnt+3)-cnt;
        ll flag=0;

        fo(i,3)
        {
            fo(j,3)
            {
                if(i==j)
                    continue;
                // ll diagonal=(i+j)%3;
                if(cnt[i][0]+cnt[j][1]<=k/3)
                {
                    ll x,y;
                    fo(x,n)
                    {
                        fo(y,n)
                        {
                            ll diagonal=(x+y)%3;
                            if(diagonal==i && v[x][y]=='X')
                            {
                                v[x][y]='O';
                            }
                            else if(diagonal==j && v[x][y]=='O')
                            {
                                v[x][y]='X';
                            }
                        }
                    }
                    flag=1;
                    break;
                }

            }
            if(flag==1)
                break;
        }

        // fo(i,n)
        // {
        //     fo(j,n)
        //     {
        //         if(v[i][j]=='X' && (i+j)%3==mn)
        //         {
        //             v[i][j]='O';
        //         }
        //     }
        // }

        fo(i,n)
            cout<<v[i]<<endl;

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