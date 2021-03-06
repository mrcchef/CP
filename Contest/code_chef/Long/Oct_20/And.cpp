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

ll first_set(ll n)
{
    ll i=0;
    while(n)
    {
        if(n&1)
            break;
        i++;
        n=n>>1;
    }
    return i;
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
        ll n;
        cin>>n;
        if(n<=5)
        {
            if(n==1)
            {
                cout<<1<<endl;
            }
            else if(n==2|| n==4)
            {
                cout<<-1<<endl;
            }
            else if(n==3)
            {
                cout<<"1 3 2"<<endl;
            }
            else
            {
                cout<<"2 3 1 5 4"<<endl;
            }

            continue;
        }

        ll check[n+1]={0},i=6,cnt=5,lmt=7,sz=3,flag=0;
        vi v;
        v.pb(2);
        v.pb(3);
        v.pb(1);
        v.pb(5);
        v.pb(4);
        check[1]=check[2]=check[3]=check[4]=check[5]=1;
        while(cnt<n)
        {
            if(i>lmt)
            {
                ll x=v[cnt-1]+2;
                // x+=i-1;
                if(x>n)
                {
                    flag=1;
                    break;
                }
                if(check[x]==0)
                {
                    v.pb(x);
                    check[x]=1;
                }    
                lmt+=1<<sz;
                sz++;
                cnt++;
            }
            if(check[i]==0)
            {
                v.pb(i);
                check[i]=1;
                cnt++;
            } 
            // cout<<i<<" "<<cnt<<" "<<lmt<<" "<<sz<<endl;   
            i++;
        }
        if(flag==1)
            cout<<-1;
        else
        {
            for(auto x:v)
                cout<<x<<" ";
        }
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