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
        ll a[4],i;
        fo(i,4)
            cin>>a[i];
        ll even=0,odd=0,flag=0,f=0,one=0;
        for(i=0;i<3;i++)
        {
            if(a[i]==0)
                flag++;
            else if(a[i]%2==0)
            {
                even++;
            }
            else 
            {
                odd++;
            }
            if(a[i]==1)
            {
                one++;
            }
        }
        if(a[3]!=0 && a[3]%2==0)
            even++;
        if(a[3]&1)
            odd++;  
        if(flag>0)
        {
            if(a[3]==1)
                one++;
            if(one>1)
            {
                cout<<"NO"<<endl;
                continue;
            }
            if(flag==1 || flag==2)
            {
                if(odd>=2)
                {
                    cout<<"NO"<<endl;
                    continue;
                }
            }
            cout<<"YES"<<endl;
            continue;
        }
        if(odd==2)
        {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;



        
        // if(flag>0)
        // {
        //     ll len=4-flag;
        //     for(ll j=0;j<4;j++)
        //     {
        //         if(a[i]==1)
        //             one++;
        //     }
        //     if(!(len==one) && one>1)
        //     {
        //         cout<<"NO"<<endl;
        //         continue;
        //     }
        //     if(odd>=2 && even==0)
        //     {
        //         cout<<"NO"<<endl;
        //         continue;
        //     }
        // }
        // if(odd==2)
        // {
        //     cout<<"NO"<<endl;
        //     continue;
        // }
        // cout<<"YES"<<endl;
        
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