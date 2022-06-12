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

void bits(ll n,vi *cnt)
{
    ll i=0;
    ll val=n;
    while(n)
    {
        if(n&1)
        {
            cnt[i].pb(val);
        }
        i++;
        n=n>>1;
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
        ll n,x,i,trk=0;
        cin>>n>>x;
        vi v(n);
        ll cnt[30]={0};
        fo(i,n)
        {
            cin>>v[i];
        }

        i=0;
        ll p=0;
        
        while(i<n-1)
        {
            ll val=v[i];
            ll k=0;
            while(val && p<x)
            {
                if(val&1)
                {
                    if(cnt[k]==0)
                    {
                        cnt[k]+=1;
                        p++;
                    }
                    else
                        cnt[k]=0;
                    v[i]=v[i]^(1<<k);
                }
                k++;
                val=val>>1;
            }
            if(p==x)
                break;
            i++;
        }

        ll rem=0, j;
        for(j=29;j>=0;j--)
            if(cnt[j]==1)
                rem++;

        ll flag=0;

        if(rem!=0)
        {
            if(i==n-2)
            for(j=0;j<=29;j++)
            {
                if(cnt[j]==1)
                {
                    v[n-1]=v[n-1]^(1<<j);
                    rem--;
                }
            }
            else
            {
                for(ll j=0;j<=29;j++)
                {
                    if(cnt[j]==1)
                    {
                        for(i;i<n;i++)
                        {
                            if(v[i]&(1<<j))
                            {
                                v[i]^=(1<<j);
                            }
                        }
                    }
                }   
            }
            
        }

        if(p<x)
        {
            rem=x-p;
            if(rem&1)
            {
                    if(v[n-1]!=0)
                    {
                        ll val=v[n-1];
                        ll check=0;
                        i=0;
                        while(!check)
                        {
                            if(val&1)
                            {
                                check=1;
                                v[n-1]^=(1<<i);
                                v[n-2]^=(1<<i);
                            }
                            i++;
                            val=val>>1;
                        }
                    }
                    else
                    {
                        v[n-1]=v[n-2]=1;
                    }
            }

        }

        for(i=0;i<n;i++)
            cout<<v[i]<<" ";
        cout<<endl;
        
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