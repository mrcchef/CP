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

ll freq[1000001];
ll distinct;

struct query{
    int L,R,q_no,block_no;

    bool operator < (query& q2)
    {
        if(block_no<q2.block_no)
            return true;
        else if(block_no>q2.block_no)
            return false;
        else
            return R<q2.R;
    }
};

void add(ll ele)
{
    if(freq[ele]==0)
        distinct++;
    freq[ele]++;
}

void remove(ll ele)
{
    freq[ele]--;
    if(freq[ele]==0)
        distinct--;
}

void adjust(ll& curr_L,ll &curr_R,query q,vi v)
{
    while(curr_L<q.L)
    {
        remove(v[curr_L]);
        curr_L++;
    }
    while(curr_L>q.L)
    {
        curr_L--;
        add(v[curr_L]);
    }
    while(curr_R<q.R)
    {
        curr_R++;
        add(v[curr_R]);
    }
    while(curr_R>q.R)
    {
        remove(v[curr_R]);
        curr_R--;
    }
}

void solve(vector<query>& vq, vi &v)
{
    vi ans(vq.size());
    ll curr_L=vq[0].L;
    ll curr_R=vq[0].R;

    memset(freq,0,sizeof(freq));
    distinct=0;

    for(ll i=curr_L;i<=curr_R;i++)
        add(v[i]);

    ans[0]=distinct;

    for(ll i=1;i<vq.size();i++)
    {
        adjust(curr_L,curr_R,vq[i],v);
        ans[i]=distinct;
    }

    for(auto val:ans)
        cout<<val<<endl;

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
        ll n,i;
        cin>>n;
        vi v(n);
        fo(i,n)
            cin>>v[i];

        ll rn=sqrt(n);
        ll q;
        cin>>q;
        vector<query> vq(q);
        fo(i,q)
        {
            ll x,y;
            cin>>x>>y;
            x--;
            y--;
            vq[i].L=x;
            vq[i].R=y;
            vq[i].q_no=i;
            vq[i].block_no=(x+1)/rn;
        }

        sort(vq.begin(),vq.end());

        solve(vq,v);
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