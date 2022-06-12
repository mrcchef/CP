
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
/*
bool solve(char a[][10],ll op[][10],ll n,ll m,ll i,ll j)
{
    if(n-1==i && m-1==j)
    {
        op[i][j]=1;
        ll k=0,l=0;
        for(k;k<n;k++)
        {
            for(l=0;l<m;l++)
            {
                cout<<op[k][l]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        op[i][j]=0;
        return true;
    }

    if(i==n || j==m)
        return false;

    if(a[i][j]=='X')
        return false;
    
    op[i][j]=1;
    bool right,down;
    right=solve(a,op,n,m,i+1,j);
    down=solve(a,op,n,m,j,i+1);

    op[i][j]=0;
    if(right || down)
        return true;

    return false;
}
*/
bool hit=1;
void solve(char a[][10],ll op[][10],ll n,ll m,ll i,ll j){
    if(i==n && j==m){
        for(int p=0;p<=n;p++){
            for(int q=0;q<=m;q++) cout << op[p][q];
            cout << "\n";
        }
        cout << "\n";
        hit = 0;
        return ;
    }
    if(i<n && a[i+1][j]=='0'){
        op[i+1][j]=1;
        solve(a,op,n,m,i+1,j);
        op[i+1][j]=0;
    }
    if(j<n && a[i][j+1]=='0'){
        op[i][j+1]=1;
        solve(a,op,n,m,i,j+1) ;
        op[i][j+1]=0;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char a[10][10]={"0000",
                    "00X0",
                    "00X0",
                    "X000"};
    ll op[10][10]={{0}};
    ll n=4,m=4;
   // solve(a,op,n,m,0,0);
    op[0][0]=1;
    solve(a,op,n-1,m-1,0,0);
    if(hit) cout << "Solution doesnt exist";
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