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

bool is_safe(ll a[][10],ll i,ll j,ll n)
{
    ll x=i,y=j;

    while(i>=0 && j>=0)
    {
        if(a[i][j]==1)
        {
            return false;
        }
        i--;
    }
    i=x;
    j=y;
    while(i>=0 && j>=0)
    {
        if(a[i][j]==1)
        {
            return false;
        }
        i--;
        j--;
    }
    i=x;
    j=y;
    while(i>=0 && j<n)
    {
        if(a[i][j]==1)
        {
            return false;
        }
        i--;
        j++;
    }

    return true;
}

bool solve(ll a[][10],ll i,ll n)
{
    if(i==n)
    {
        ll j,k;
        fo(j,n)
        {
            fo(k,n)
                cout<<a[j][k]<<" ";
            cout<<endl;
        }
        cout<<endl;
        return true;    // return false for printing all the possible valid arragnements this is b/c when we are searching for another 
    }                   // combination then we should back track and make the last postion again to be zero

    for(ll j=0;j<n;j++)
    {
        if(is_safe(a,i,j,n))
        {
            a[i][j]=1;
            bool check=solve(a,i+1,n);
            if(!check)
                a[i][j]=0;
            else                // Comment else condition for all the possible valid arrangements
                return true;    
        }
    }
    return false;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    ll board[10][10]={0};
    solve(board,0,n);

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