// // Problem Name : Money Change
// // Topic : DP
// // Difficulty : Hard
// // EXPLANATION
// // To count the total number of solutions, we can divide all set solutions into two sets. 1) 
// Solutions that do not contain mth coin (or Sm). 2) Solutions that contain at least one Sm. 
// Let count(S[], m, n) be the function to count the number of solutions, then it can be written as sum of count(S[], m-1, n)
//  and count(S[], m, n-Sm).

// // Therefore, the problem has optimal substructure property as the problem can be solved using solutions to subproblems.

// // Time Complexity : O(N*M).
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long 
// const int mod = 1000000000 + 7;
// int count( int S[], int m, int n ) 
// { 
//     // table[i] will be storing the number of solutions for 
//     // value i. We need n+1 rows as the table is constructed 
//     // in bottom up manner using the base case (n = 0) 
//     int table[n+1]; 

//     // Initialize all table values as 0 
//     memset(table, 0, sizeof(table)); 

//     // Base case (If given value is 0) 
//     table[0] = 1; 

//     // Pick all coins one by one and update the table[] values 
//     // after the index greater than or equal to the value of the 
//     // picked coin 
//     for(int i=0; i<m; i++) 
//         for(int j=S[i]; j<=n; j++) 
//             table[j] += table[j-S[i]],table[j]%=mod; 

//     return table[n]; 
// }  

// void solve(){
//     int m;
//     cin>>m;
//     int a[m];
//     for(int i=0;i<m;i++)cin>>a[i];
//     int n;
//     cin>>n;
//     cout<<count(a,m,n)<<endl;
// }

// signed main() {
//     int t;
//     cin>>t;
//     while(t--){
//         solve();
//     }
//     return 0;
// }
// Another Approach
// 1) Optimal Substructure
// To count the total number of solutions, we can divide all set solutions into two sets.
// 1) Solutions that do not contain mth coin (or Sm).
// 2) Solutions that contain at least one Sm.
// Let count(S[], m, n) be the function to count the number of solutions, then it can be written as sum of count(S[], m-1, n) and count(S[], m, n-Sm).

// Therefore, the problem has optimal substructure property as the problem can be solved using solutions to subproblems.

// Code

// static long countWays(int S[], int m, int n) 
//     { 
//         //Time complexity of this function: O(mn) 
//         //Space Complexity of this function: O(n) 

//         // table[i] will be storing the number of solutions 
//         // for value i. We need n+1 rows as the table is 
//         // constructed in bottom up manner using the base 
//         // case (n = 0) 
//         long[] table = new long[n+1]; 

//         // Initialize all table values as 0 
//         Arrays.fill(table, 0);   //O(n) 

//         // Base case (If given value is 0) 
//         table[0] = 1; 

//         // Pick all coins one by one and update the table[] 
//         // values after the index greater than or equal to 
//         // the value of the picked coin 
//         for (int i=0; i<m; i++) 
//             for (int j=S[i]; j<=n; j++) 
//                 table[j] += table[j-S[i]]; 

//         return table[n]; 
//     } 

// ---------------------- CPP Editorial -----------------------

// #include <iostream>
// #define ll long long int
// using namespace std;
// #define mod 1000000007
// ll CoinChangeBottomUp(int *coins, int value, int n) {
//     ll *dp = new ll[value+1];
//     dp[0] = 1;
//     for(int i=0;i<=value;i++) {
//         dp[i]=0;
//     }
//     dp[0]=1;
//     for(int i=0;i<n;i++) {
//         for(int j=0;j<=value;j++) {
//             if (coins[i] <= j)
//                 dp[j] = ((dp[j]%mod)+ (dp[j-coins[i]]%mod))%mod;
//         }
//     }
//     int temp=dp[value];
//     delete [] dp;
//     return temp;
// }

// // int minCoinChangeTopDown(int *coins, int value, int n, int *dp) {
// //     if(value<0) {
// //         return INT_MAX;
// //     }
// //     if(value==0) {
// //         dp[0] = 0;
// //         return 0;
// //     }
// //     if(dp[value]!=0) {
// //         return dp[value];
// //     }
// //     int currentVal = INT_MAX;
// //     for(int i=0;i<n;i++) {
// //         currentVal = min(currentVal, minCoinChangeTopDown(coins, value-coins[i], n, dp));
// //     }

// //     dp[value] = (currentVal==INT_MAX)?-1:1+currentVal;
// //     return dp[value];
// // }
// int main() {
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
//     int t;
//     cin>>t;
//     while(t--) {
//     int n,s;
//     cin>>n;
//     int *coins = new int[n];
//     for(int i=0;i<n;i++) {
//         cin>>coins[i];
//     }
//     cin>>s;
//     // int *dp = new int[5005];
//     cout<<CoinChangeBottomUp(coins, s, n)<<endl;
//     //delete [] dp;
// }
// return 0;
// }

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
#define endl "\n"
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
    int t;
    cin>>t;
    while(t--)
    {
        ll n,i;
        cin>>n;
        vi v(n);
        fo(i,n)
        {
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        ll N;
        cin>>N;
        ll dp[N+1]={0};
        dp[0]=1;
        for(i=0;i<n;i++)
        {
            for(ll j=1;j<=N;j++)
            {
                if(j-v[i]<0)
                    continue;
                dp[j]+=dp[j-v[i]];
                dp[j]%=mod;
            }
        }
        cout<<dp[N]<<endl;
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