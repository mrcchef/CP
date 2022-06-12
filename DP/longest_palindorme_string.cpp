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
//  Logic is very simple
// we are moving from the extreme ends of array until we visited every character
// we are just checking that is the extreme ends of strings are eqaul if equal then we reduce our string by 2 
// if not there there will be two condition
// 1st new string is of len start+1,end 
// 2nd new string is of len start, end-1
// and we store max of them 
int palindrone(string s,ll start,ll end,ll dp[][100])
{
    if(start>end) //codition to check that is every character is visited
        return 0;
    if(start==end)// for single character
        return 1;

    if(dp[start][end]!=0) 
        return dp[start][end];
        
    if(s[start]==s[end])
    {
        ll remaning_string_len=end-start-1;
        if(remaning_string_len==palindrone(s,start+1,end-1,dp))
            return dp[start][end]=2+remaning_string_len;
    }
    return dp[start][end]=max(palindrone(s,start+1,end,dp),palindrone(s,start,end-1,dp));    
}

int main()
{
    string s;
    cin>>s;
    ll dp[100][100]={0};
    palindrone(s,0,s.size()-1,dp);
    for(ll i=0;i<s.size();i++)
    {
        for(ll j=0;j<s.size();j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
        
 return 0;
}

//https://www.youtube.com/watch?v=Msghl9189X4 
//Explanation video
//28:00 for iterative method

// int main()
// {
//     string s;
//     cin>>s;
//     ll sz=s.size();
//     ll dp[sz][sz]={0};
//     ll start=sz-2;
//     ll ma=INT_MIN;
//     for(ll i=0;i<sz;i++)
//         dp[i][i]=1;

//     for(start;start>=0;start--)
//     {
//         for(ll end=start+1;end<sz;end++)
//         {
            
//             if(s[start]==s[end] && (dp[start+1][end-1]==1 || end-start==1))
//             {
//                 ll len=end-start+1;
//                 ma=max(ma,len);
//                 dp[start][end]=1;
//             }
//         }
//     }
//     // for(ll i=0;i<sz;i++)
//     // {
//     //     for(ll j=0;j<sz;j++)
//     //         cout<<dp[i][j]<<" ";
//     //     cout<<endl;
//     // }
//     cout<<ma;
    

// }