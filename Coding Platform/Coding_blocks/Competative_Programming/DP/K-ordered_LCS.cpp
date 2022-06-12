// Any programmer worth his salt would be familiar with the famous Longest Common Subsequence problem. 
// Mancunian was asked to solve the same by an incompetent programmer. As expected, he solved it in a flash. 
// To complicate matters, a twist was introduced in the problem.

// In addition to the two sequences, an additional parameter k was introduced. 
// A k-ordered LCS is defined to be the LCS of two sequences if you are allowed to change atmost k elements in the first sequence 
// to any value you wish to. Can you help Mancunian solve this version of the classical problem?

// Input Format
// The first line contains three integers N, M and k, denoting the lengths of the first and second sequences and the 
// value of the provided parameter respectively. The second line contains N integers denoting the elements of the first sequence. 
// The third line contains M integers denoting the elements of the second sequence.

// Constraints
// 1 <= N, M <= 2000
// 1 <= k <= 5
// 1 <= element in any sequence <= 109


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

ll dp[1002][1002][6];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll n,m,k,i,j;
        cin>>n>>m>>k;
        vi v1(n+1),v2(m+1);
        fo(i,n)
        {
            cin>>v1[i+1];
        }
        fo(j,m)
        {
            cin>>v2[j+1];
        }
        
        Fo(i,1,n)
        {
            Fo(j,1,m)
            {
                for(ll p=1;p<=k;p++)
                {
                    if(v1[i]==v2[j])
                    {
                        dp[i][j][p]=1+dp[i-1][j-1][p];
                    }
                    else
                    {
                        dp[i][j][p]=max(1+dp[i-1][j-1][p-1],max(dp[i][j-1][p],dp[i-1][j][p]));
                    }
                }
            }
        }

        cout<<dp[n][m][k]<<endl;
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