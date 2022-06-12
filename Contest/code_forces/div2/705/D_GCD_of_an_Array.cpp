#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0) ; cout.tie(0);
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
#define deb1(x)                cout<<#x<<": "<<x<<endl
#define deb2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define deb3(x, y, z)          cout<<#x<<":"<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<" : "<<f<<endl
const ll mod = 1e9+7;
#define popcount(x) __builtin_popcount(x)
#define all(x) x.begin(),x.end()
#define mem(a,v) memset(a,v,sizeof(a))
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

const ll N=2e5+5;

ll lpf[N];
vi prime;

// lpf[i] stores minimum prime factor of i
// we can calulate it using seive in O(n) time for n numbers
// In order to calculate all prime factor we need to follow below pseudo code

// void primeFact(ll num)
// { 
//     while(num!=1)
//     {
//         ll fac=lpf[num]; // got one prime factor 
//         cout<<fac<<" ";
//         num=num/fac;   // eleminated one instace of the factor
//     }
// }

void cal()
{
    ll check[N];
    ll i;
    fo(i,N)
        lpf[i]=1;
    
    lpf[0]=0;

    for(i=2;i<N;i++)
    {
        if(lpf[i]==1)
        {
            lpf[i]=i; 
            prime.pb(i);  
        }

        for(ll j=0;j<prime.size() && prime[j]<=lpf[i] && i*prime[j]<N;j++)
        {
            lpf[i*prime[j]]=prime[j];
            check[j]=0;
        }
    }
}

// p is the prime factor
mii hm[N]; // hm[i][p] stores the power of prime factor p in the ith number

multiset<ll> mst[N];  // mst[i] stores all the power prime factor p in the n numbers

void solve()
{
    ll n,q;
    cin>>n>>q;
    ll i;
    ll ans=1;
    fo(i,n)
    {
        ll x;
        cin>>x;
        // cout<<lpf[x]<<endl;
        while(x!=1)
        {
            ll fac=lpf[x];
            // if that for ith number, factor is new
            //then simpley insert into the multiset
            if(hm[i][fac]==0)
            {
                mst[fac].insert(0);
            }

            // lower power of fac till now
            ll best=*mst[fac].begin();
            // In order to update we delete previous occurance
            // then insert the incremented value
            mst[fac].erase(mst[fac].find(hm[i][fac])); 
            hm[i][fac]++;
            mst[fac].insert(hm[i][fac]);

            // new Best power of fac
            ll newBest=*mst[fac].begin();

            // if total number of factor is less than n then their must of one number which is one
            // then it's contricution of ans doesn't matter 
            // and also if best value is less that newBest then only we multiply the result
            // b/c if the newBest is not greater then it must be eqal to best and 
            // on that case their is no change in the minimum value that is no need to add repetetive contribution    
            if(mst[fac].size()==n && best<newBest)
            {   
                ans=(ans*fac)%mod;
            }

            x/=fac;

        }
    }

    fo(i,q)
    {
        ll x,num;
        cin>>x>>num;

        x--;

        while(num!=1)
        {
            ll fac=lpf[num];
            if(hm[x][fac]==0)
            {
                mst[fac].insert(0);
            }

            ll best=*mst[fac].begin();
            mst[fac].erase(mst[fac].find(hm[x][fac]));
            hm[x][fac]++;
            mst[fac].insert(hm[x][fac]);

            ll mn=*mst[fac].begin();

            if(mst[fac].size()==n && best<mn)
            {
                ans=ans*fac%mod;
            }

            num=num/fac;
        }

        cout<<ans<<endl;
    }

}

int main()
{
    fastio
    int t=1;
    cal();
    // cin>>t;
    while(t--)
    {
        solve();   
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