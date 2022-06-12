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
// Iterative method is more efficient
// Logic:-
// similar to substring but here we the result of subsequence form first to last is equal to 
// case 1:- if s[first]==s[last] then length for this subseq. will be 2+length of subseq. from first+1 and last-1
// case 2:- if s[first]!=s[last] then length for this subseq. will be max(2 subseq)
ll dp[1005][1005];

int palin(string s,ll first,ll last)
{
    if(first>last)
        return 0;
    if(first==last)
        return dp[first][last]=1;
    if(dp[first][last]!=0)
        return dp[first][last];
    
    if(s[first]==s[last])
    {
        return dp[first][last]=2+palin(s,first+1,last-1);
    }

    ll op1=palin(s,first+1,last);
    ll op2=palin(s,first,last-1);
    
    return dp[first][last]=max(op1,op2);

}

int main()
{
    string s;
    cin>>s;
    palin(s,0,s.size()-1);
    cout<<dp[0][s.size()-1];
    // for(ll i=0;i<s.size();i++)
    // {
    //     for(ll j=0;j<s.size();j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
 return 0;
}

// ll dp[1005][1005];

// int main()
// {
//     string s;
//     cin>>s;
//     ll sz=s.size();

//     ll start=sz-2;
//     ll ma=INT_MIN;
//     for(ll i=0;i<sz;i++)
//         dp[i][i]=1;

//     for(start;start>=0;start--)
//     {
//         for(ll end=start+1;end<sz;end++)
//         {
            
//             if(s[start]==s[end])
//             {
//                 dp[start][end]=dp[start+1][end-1]+2;
//             }
//             else
//             {
//                 ll op1,op2;
//                 op1=dp[start+1][end];
//                 op2=dp[start][end-1];
//                 dp[start][end]=max(op1,op2);
//             }
//         }
//     }
//     // for(ll i=0;i<sz;i++)
//     // {
//     //     for(ll j=0;j<sz;j++)
//     //         cout<<dp[i][j]<<" ";
//     //     cout<<endl;
//     // }
//     cout<<dp[0][s.size()-1];
    

// }

