#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
#include <string>
using namespace std;
#define ll long long int
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
    string s;
    cin>>s;
    ll cnt=0;
    ll sz=s.size();
    ll dp[sz][sz]={0};
    for(ll i=0;i<sz;i++){
        cnt++;
        dp[i][i]=1;
    }
    for(ll start=sz-2;start>=0;start--)
    {
        for(ll end=start+1;end<sz;end++)
        {
            if(s[start]==s[end] && (dp[start+1][end-1]==1 || end-start==1))
            {
                dp[start][end]=1;
                cnt++;
            }
        }
    }
    for(ll i=0;i<sz;i++)
    {
        for(ll j=0;j<sz;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    cout<<cnt;
     return 0;
}

// Recursive method needs improvement

// int count(string s,ll start,ll end,ll dp[][100])
// {
//     if(start>end)
//         return 0;
//     if(start==end)
//         return 1;
//     if(dp[start][end]!=0)
//         return dp[start][end];
    
//     if(s[start]==s[end])
//     {
//         ll op=end-start-1;;
//         if(op=count(s,start+1,end-1,dp))
//             return dp[start][end]=op+2;
//     }
//     ll op1=count(s,start+1,end,dp);
//     ll op2=count(s,start,end-1,dp);
//     return dp[start][end]=max(op1,op2);
// }

// int main()
// {
//     string s;
//     cin>>s;
//     ll cnt=0;
//     ll sz=s.size();
//     ll dp[100][100]={0};
//     cnt=count(s,0,sz-1,dp);
//     for(ll i=0;i<s.size();i++)
//     {
//         for(ll j=0;j<s.size();j++)
//             cout<<dp[i][j]<<" ";
//         cout<<endl;
//     }
//     cout<<cnt;


//     return 0;
// }