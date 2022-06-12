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

struct data{
    ll stt,edt,stp,edp;
};

bool compare(data &node1,data &node2)
{
    return node1.stt<node2.stt;
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
        ll n,i;
        cin>>n;
        vector<pii> vp;
        vector<data> arr;
        vector<pii> arr2;
        mii m;
        ll time=0,pos=0,cnt=0;
        m[0]=0;
        fo(i,n)
        {
            ll tx,px;
            cin>>tx>>px;
            vp.pb({tx,px});
            if(tx>=time)
            {
                data node;
                m[tx]=pos;
                node.stt=tx;
                node.stp=pos;                
                ll inc=abs(px-pos);
                time=tx+inc;
                arr.pb(node);
                m[time]=px;
                pos=px;
                // cout<<time<<" "<<m[time]<<endl;
                cnt++;
            }
            else
            {
                ll val=tx-arr[cnt-1].stt;
                m[tx]=arr[cnt-1].stp;
                if(arr[cnt-1].stp>pos)
                    m[tx]-=val;
                else
                {
                    m[tx]+=val;
                }
                
                // cout<<tx<<" "<<m[tx]<<endl;
                arr2.pb({tx,px});
            }
            // deb(time);
            // deb(pos);
        }
        vp.pb({time,pos});
        sort(arr.begin(),arr.end(),compare);

        // for(auto val:m)
        //     cout<<val.first<<" "<<val.second<<endl;
        // for(auto val:vp)
        //     cout<<val.first<<" "<<val.second<<endl;

        ll count=0;
        fo(i,n)
        {
                if(m[vp[i].first]<=vp[i].second && m[vp[i+1].first]>=vp[i].second)
                    count++;
                else if(m[vp[i].first]>=vp[i].second && m[vp[i+1].first]<=vp[i].second)
                    count++;
                // cout<<vp[i].first<<" "<<vp[i].second<<" "<<vp[i+1].first<<" "<<m[vp[i].first]<<" "<<m[vp[i+1].first]<<endl;
            // }
        }
        cout<<count<<endl;


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