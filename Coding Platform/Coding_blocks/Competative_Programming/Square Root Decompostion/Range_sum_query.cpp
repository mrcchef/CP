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

ll query(vi &v,vi &blocks,ll l,ll r,ll sr)
{
    ll val=0;
    ll i=l;
    // left most part
    while( i!=0 && i<r && i%sr!=0 )
    {
        val+=v[i];
        i++;
    }

    // Middle part
    while(i+sr<=r)
    {
        val+=blocks[i/sr];
        i+=sr;
    }

    //end part

     while(i<=r)
     {
         val+=v[i++];
     }   

     return val;
}

void update(vi &v,vi &blocks,ll index,ll val,ll sr)
{
    ll block_id=index/sr;
    blocks[block_id]=v[index]-val;
    v[index]=val;
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
        ll n,i,q;
        cin>>n>>q;
        vi v(n);
        fo(i,n)
            cin>>v[i];
        
        ll sr=sqrt(n);

        vi blocks(sr+1,0);
        ll block_id=-1;

        // n=10;

        // root n=3 , so we have dived them into n/(root n) parts 
        // below shown are the indices 
        // 0 1 2|3 4 5|6 7 8|9 _ _

        fo(i,n)
        {
            if(i%sr==0)
            {
                block_id++;
            }
            blocks[block_id]+=v[i];
        }

        for(auto val:blocks)
            cout<<val<<" ";
        cout<<endl;

        fo(i,q)
        {
            ll l,r,ch;
            cin>>ch>>l>>r;
            if(ch==1)
            {
            cout<<query(v,blocks,l-1,r-1,sr)<<endl;
            }
            else
                update(v,blocks,l,r,sr);
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