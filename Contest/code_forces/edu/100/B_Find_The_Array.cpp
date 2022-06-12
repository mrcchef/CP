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
        ll n,i;
        cin>>n;
        vi v(n);
        ll sm1=0,sm2=0;
        fo(i,n)
        {
            cin>>v[i];
            if(i%2==0)
            {
                sm1+=v[i];

            }
            else
            {
                
            sm2+=v[i];
            }
            
        }

        vi ans(n);
        if(sm1<sm2)
        {
            for(i=0;i<n;i++)
                if(i%2==0)
                {
                    ans[i]=1;
                }
                else
                {
                    ans[i]=v[i];
                }
                
        }
        else
        {
            for(i=0;i<n;i++)
                if(i%2==1)
                {
                    ans[i]=1;
                }
                else
                {
                    ans[i]=v[i];
                }
        }
        

        // sort(v.begin(),v.end());

        // ll mid=n/2;
        // mii m;
        // for(i=mid;i<n;i++)
        // {
        //     m[v[i]++;
        // }

        // vi ans(n);

        //     ll temp=0;

        // fo(i,n)
        // {
        //     if(m[v[i]])
        //     {
        //         ans[i]=v[i];
        //         flag=1;
        //         // temp=0;
        //     }
        //     else
        //     {
        //         if(flag==1)
        //         {
        //             ans[i]=1;
        //             flag=0;
        //         }
        //         else
        //         {
        //             ans[i]
        //         }
                
        //         // if(ans[i-1]%v[i]==0 || v[i]%ans[i-1]==0)
        //         // {
        //         //     ans[i]=v[i];
        //         // }
        //         // else
        //         // {
        //         //     ans[i]=1;
        //         //     temp+=abs(ans[i]-v[i]);
        //         // }
        //         // ll v1=
        //     }
            
        // }
        // // cout<<sm<<" "
        // if(sm/2>=temp)
            // cout<<"YES";
        for(auto x:ans)
            cout<<x<<" ";
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