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
#define deb(x) cout << #x << "=" << x << endl
const ll mod = 1e9+7;
#define popcount(x) __builtin_popcount(x)
#define all(x) x.begin(),x.end()
#define mem(a,v) memset(a,v,sizeof(a))

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

set<ll> st;

bool check(ll i,ll j,ll h,ll m)
{
    ll ti=i,tj=j;
    bool isli=false,islj=false;
    if(ti<10)
        isli=true;
    if(tj<10)
        islj=true;
    ll ri=0,rj=0;
    while(ti)
    {
        ll rem=ti%10;
        if(rem==2)
            rem=5;
        else if(rem==5)
            rem=2;
        ri=ri*10+rem;
        ti=ti/10;
        if(!st.count(rem))
            return false;
    }
    while(tj)
    {
        ll rem=tj%10;
        if(rem==2)
            rem=5;
        else if(rem==5)
            rem=2;
        rj=rj*10+rem;
        tj=tj/10;
        if(!st.count(rem))
            return false;
    }
    // deb(ri);
    // deb(rj);
    if(isli)
        ri*=10;
    if(islj)
        rj*=10;
    // deb(ri);
    // deb(rj);
    // deb(h);
    // deb(m);
    if(rj<h && ri<m)
        return true;

    return false;
}

void solve()
{
    int h,m;
    int hh,mm;
    cin>>h>>m;
    string s;
    cin>>s;
    string s1=s.substr(0,2);
    hh=stoi(s1);
    string s2=s.substr(3,2);
    mm=stoi(s2);
    // deb(hh);
    // deb(mm);
    ll flag=0;
    ll ansh=0,ansm=0;

    for(int i=hh;i<h;i++)
    {
        int j;
        if(i==hh)
            j=mm;
        else
            j=0;
        for(j;j<m;j++)
        {
            if(check(i,j,h,m))
            {
                flag=1;
                ansh=i;
                ansm=j;
                break;
            }
        }
        if(flag)
            break;
    }

    // if(flag==0)
    // {
    //     cout<<"00:00"<<endl;
    //     return;
    // }

    if(ansh<10 && ansm<10)
        cout<<"0"<<ansh<<":0"<<ansm<<endl;
    else if(ansh<10)
    {
        cout<<"0"<<ansh<<":"<<ansm<<endl;
    }
    else if(ansm<10)
    {
        cout<<ansh<<":0"<<ansm<<endl;
    }
    else
        cout<<ansh<<":"<<ansm<<endl;
}

int main()
{
    fastio
    int t;
    cin>>t;
    st.insert(0);
    st.insert(1);
    st.insert(2);
    st.insert(5);
    st.insert(8);
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

// ll flagx=0;
    // ll anshx,ansmx;
    // for(int i=hh;i>=0;i--)
    // {
    //     int j;
    //     if(i==hh)
    //         j=mm;
    //     else
    //         j=m-1;
    //     for(j;j>=0;j--)
    //     {
    //         // deb(i);
    //         // deb(j);
    //         // if(j==m)
    //         //     j=0;
    //         if(check(i,j,h,m))
    //         {
    //             flagx=1;
    //             anshx=i;
    //             ansmx=j;
    //             break;
    //         }
    //         // if(j==0)
    //         //     break;
    //     }
    //     // if(i)
    //     if(flagx)
    //         break;
    // }

    // ll diff1=(ansh-hh)*m+(ansm-mm);
    // ll diff2=(hh-anshx)*m+(mm-ansmx);
    // if(diff1>diff2)
    // {
    //     ansh=anshx;
    //     ansm=ansmx;
    // }