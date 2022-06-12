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

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

void find_val(vi left,vi right,ll &mn,ll &mx,ll &idn,ll &idx)
{
    for(ll i=0;i<3;i++)
    {
        if(mn>left[i])
        {
            mn=left[i];
            idn=i;
        }
        if(mx<right[i])
        {
            mx=right[i];
            idx=i;
        }
    }
    // for(auto x:left)
    //     cout<<x<<" ";
    // cout<<endl;
    // for(auto x:right)
    //     cout<<x<<" ";
    // cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        vi left,right;
        ll sm_l=0,sm_r=0,j;
        fo(j,6)
        {
            ll val=s[j]-'0';
            if(j<=2)
            {
                left.pb(val);
                sm_l+=val;
            }
            else
            {
                right.pb(val);
                sm_r+=val;
            }
        }

        if(sm_l>sm_r)
        {
            vi temp=left;
            left=right;
            right=temp;
            swap(sm_l,sm_r);
        }
        ll diff=sm_r-sm_l;
        if(diff==0)
            cout<<0;
        else
        {
            ll mn=10,mx=-1,idn,idx;
            find_val(left,right,mn,mx,idn,idx);
            if(9-mn>mx)
            {
                diff-=(9-mn);
                left[idn]=9;
            }
            else
            {
                diff-=mx;
                right[idx]=0;
            }
            // deb(diff);
            if(diff<=0)
                cout<<1;
            else
            {
                mn=10;
                mx=-1;
                find_val(left,right,mn,mx,idn,idx);
                // deb(mn);
                // deb(mx);
                if(9-mn>mx)
                {
                    diff-=(9-mn);
                    left[idn]=9;
                }
                else
                {
                    diff-=mx;
                    right[idx]=0;
                }
                // deb(diff);
                if(diff<=0)
                    cout<<2;
                else
                {
                    cout<<3;
                }
                
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