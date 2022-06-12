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

bool is_correct(ll a[][9],ll i,ll j,ll n,ll k)
{
    ll x,y;
    for(ll p=0;p<9;p++)
    {
        if(a[p][j]==k)
            return false;
    }
    for(ll p=0;p<9;p++)
    {
        if(a[i][p]==k)
            return false;
    }
    x=(i/3)*3;  // this formula is important for checking i a 3*3 grid
    y=(j/3)*3;
    for(i=x;i<x+3;i++)
    {
        for(j=y;j<y+3;j++)
        {
            if(a[i][j]==k)
                return false;
        }
    }
    return true;
}

bool solve(ll a[9][9],ll i,ll j,ll n)
{
    if(i==n)
    {
        for(ll k=0;k<n;k++)
        {
            for(ll l=0;l<n;l++)
            {
                cout<<a[k][l]<<" ";
            }
            cout<<endl;
        }
        return true;
    }

    if(j==n)
        return solve(a,i+1,0,n);
    if(a[i][j]!=0)
        return solve(a,i,j+1,n);

    for(ll k=1;k<=9;k++)
    {
        if(is_correct(a,i,j,n,k))
        {
            a[i][j]=k;
            bool check;
            check=solve(a,i,j+1,n);
            if(!check)
                a[i][j]=0;
            else
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
    ll matrix[9][9];
    ll i,j;
    fo(i,9)
    {
        fo(j,9)
            cin>>matrix[i][j];
    }
    solve(matrix,0,0,9);

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