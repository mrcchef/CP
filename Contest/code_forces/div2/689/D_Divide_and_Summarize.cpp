#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<map>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<=n;i++)
#define ll int
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

bool solve(vi v,ll n,ll sm,ll s)
{
    if(s==sm)
        return true;
    
    ll mid=(v[0]+v[n-1])/2;
    // cout<<mn<<" "<<mx<<" "<<sm<<endl;
    ll i;
    vi v1,v2;
    ll sm1=0,sm2=0,pos=-1;
    fo(i,n)
    {
        if(v[i]<=mid)
        {
            pos=i;
            sm1+=v[i];
        }
        else
        {
            break;
        }
    }
    sm2=sm-sm1;

    // ll mx1=INT_MIN,mn2=INT_MAX;
    // fo(i,v1.size())
    //     mx1=max(mx1,v1[i]);
    // fo(i,v2.size())
    //     mn2=min(mn2,v2[i]);
    // cout<<mn<<" "<<mx1<<" "<<mn2<<" "<<mx<<endl;
    if(pos==-1 || pos==n-1)
        return false;
    if(s>=v[0] && s<=sm1)
    {
        // v2.clear();
        return solve(v1,v1.size(),sm1,s);
    }
    else if(s>=v[pos+1] && s<=sm2)
    {
        // v1.clear();
        return solve(v2,v2.size(),sm2,s);
    }
    else
    {
        return false;
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,q,i;
        cin>>n>>q;
        vi v(n);
        ll mx=INT_MIN;
        ll mn=INT_MAX;
        ll sm=0;
        mii m;
        fo(i,n)
        {
            cin>>v[i];
            sm+=v[i];
            m[v[i]]++;
        }
        sort(v.begin(),v.end());
        fo(i,q)
        {
            bool check;
            ll s;
            cin>>s;
            if(m[s]>1 || s<v[0] || s>sm)
                check=false;
            else
            {
                check=solve(v,n,sm,s);
            }

            if(check)
            {
                cout<<"Yes";
            }
            else
            {
                cout<<"No";
            }
            cout<<endl;
        }
        
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