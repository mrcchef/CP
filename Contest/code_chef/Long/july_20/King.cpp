#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
#include <string>
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
#define deb(x) cout << #x << "=" << x << endl
const double mod = 1e9+7;

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll fxp(ll a,ll b,ll m) {
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp(a*a,b/2,m);
    return fxp(a,b-1,m)*a;
}
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,no_x;
        cin>>n;
        ll a[8][8];
        memset(a,0,sizeof(a));
        if(n==8)
            no_x=8;
        else
        {
            no_x=min(n+2,9LL);
        }
        ll k=0,temp=n,flag=0;
        for(ll i=0;i<8;i++)
        {
            for(ll j=0;j<8;j++)
            {
                if(temp)
                {
                    a[i][j]=0;
                    if(i==0 && j==0)
                        a[i][j]=1;
                    temp--;
                }
                else if(n<8 && no_x)
                {
                    if(flag==0)
                    {
                        a[i][j]=-1;
                        flag=1;
                        no_x--;
                        break;
                    }
                    else
                    {
                        a[i][j]=-1;  
                        no_x--; 
                    }
                }
                else if(n>=8 && no_x)
                {
                    a[i][j]=-1;
                    no_x--;
                }  
            }
        }
        for(ll i=0;i<8;i++)
        {
            for(ll j=0;j<8;j++)
            {
                if(a[i][j]==1)
                {
                    cout<<"O";
                }
                else if(a[i][j]==0)
                {
                    cout<<".";
                }
                else
                {
                    cout<<"X";
                }
            }
            cout<<endl;
        }
    }
 return 0;
}
