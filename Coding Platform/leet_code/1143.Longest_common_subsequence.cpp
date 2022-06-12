#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
#include <string>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
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
    string s1,s2;
    cin>>s1>>s2;
    ll sz1=s1.size(),sz2=s2.size();
    ll dp[sz1+1][sz2+1];
    for(ll i=0;i<=sz1;i++)
        dp[i][0]=0;
    for(ll i=0;i<=sz2;i++)
        dp[0][i]=0;
    for(ll i=1;i<=sz1;i++)
    {
        for(ll j=1;j<=sz2;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    for(ll i=0;i<=sz1;i++)
    {
        for(ll j=0;j<=sz2;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    string res;
    ll i=sz1,j=sz2;
    while(i>0 && j>0)
    {
            if(dp[i-1][j]==dp[i][j-1]==dp[i-1][j-1])
            {
                if(dp[i-1][j-1]!=dp[i][j])
                {
                    res=res+s1[i-1];
                    j--;
                    i--;
                }
                else
                {
                    j--;
                }
            }
            else
            {
                ll val=max(dp[i-1][j],dp[i][j-1]);
                if(val==dp[i-1][j])
                    i--;
                else
                    j--;
            }
        
    }
    cout<<res<<endl;
 return 0;
}
