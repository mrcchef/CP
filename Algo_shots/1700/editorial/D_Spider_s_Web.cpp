// #include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
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
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll n,i;
        cin>>n;
        vi v[n+2];
        fo(i,n)
        {
            ll k,j;
            cin>>k;

            fo(j,k)
            {
                ll x;
                cin>>x;
                v[i].pb(x);
            }
            sort(v[i].begin(),v[i].end());
            if(i<2)
                v[i+n]=v[i];
        }
        ll cnt=0;
        Fo(i,1,n)
        {
            ll st,ed;
            st=v[i][0];
            for(ll j=1;j<v[i].size();j++)
            {
                ed=v[i][j];
                ll left=0,right=0;
                ll ls,ld;
                ls=lower_bound(v[i-1].begin(),v[i-1].end(),st)-v[i-1].begin();
                ld=lower_bound(v[i-1].begin(),v[i-1].end(),ed)-v[i-1].begin();
                left=ld-ls;
                // deb(left);
                // cout<<ld<<" "<<ls<<endl;
                ll rs,rd;
                rs=lower_bound(v[i+1].begin(),v[i+1].end(),st)-v[i+1].begin();
                rd=lower_bound(v[i+1].begin(),v[i+1].end(),ed)-v[i+1].begin();
                right=rd-rs;
                if(left!=right)
                {
                    cnt++;
                }
                st=ed;
            }
        }

        cout<<cnt<<endl;

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