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
// #define endl "\n"
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
    int t=4;
    // cin>>t;
    ll ans[6];
    ll check[100000]={0};
    check[4]=1;
    check[8]=1;
    check[15]=1;
    check[16]=1;
    check[23]=1;
    check[42]=1;

    ll arr[6]={4,8,15,16,23,42};
    mii m;
    ll i=1;
    while(i<5)
    {
        cout<<"? "<<i<<" "<<i+1<<endl;
        ll val;
        cin>>val;

        for(ll j=0;j<6;j++)
        {
            ll q=val/arr[j];
            if(check[q]==1)
            {
                if(i>1)
                {
                    if(m[q]==1)
                    {
                        ans[i-1]=q;
                    }
                    else
                        ans[i-1]=arr[j];
                    if(i==2)
                    {
                        for(auto va:m)
                        {

                            if(ans[i-1]!=va.first && va.second==1)
                            {
                                // cout<<ans[i-1]<<" "<<va.first;
                                ans[0]=va.first;
                                break;
                            }
                        }
                    }
                    if(i==4)
                    {
                          if(ans[i-1]==q)
                                ans[i]=arr[j];
                        else
                        {
                            ans[i]=q;
                        }
                    }
                }
                // cout<<'\n'<<q<<" "<<arr[j]<<'\n';
                m[q]=1;
                m[arr[j]]=1;
                break;
            }
        }
        i++;
        if(i==5)
        {
            for(ll j=0;j<6;j++)
            {
                if(m[arr[j]]==0)
                {
                    ans[5]=arr[j];
                    break;
                }
            }
        }
    }
        cout<<"! ";
    for(ll j=0;j<6;j++)
        cout<<ans[j]<<" ";
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