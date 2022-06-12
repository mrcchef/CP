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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        ll cnt_z=0,cnt_o=0,check=1;
        for(ll i=0;i<k;i++)
        {
            ll flag=0;

            char val;
            if(s[i]=='0')
            {
                cnt_z++;
                val='0';
            }
            else if(s[i]=='1')
            {
                cnt_o++;
                val='1';
            }
            else
            {
                val='?';
            }

            if(val=='?')
            {
                for(ll j=i+k;j<n;j+=k)
                {
                    if(s[j]!='?')
                    {
                        val=s[j];
                        break;
                    }
                }
                if(val=='1')
                    cnt_o++;
                else if(val=='0')
                {
                    cnt_z++;
                }
            }

            s[i]=val;

            for(ll j=i+k;j<n;j+=k)
            {
                if(s[j]=='?')
                    s[j]=val;
                else if(s[j]==val)
                    continue;
                else
                {
                    flag=1;
                    break;
                }    
            }
            if(flag==1)
            {
                check=0;
                break;
            }   
        }

        for(ll i=0;i<k;i++)
        {  
            if(s[i]=='?')
            {
                char val;
                if(cnt_z<k/2)
                {
                    val='0';
                    cnt_z++;
                }
                else if(cnt_o<k/2)
                {
                    val='1';
                    cnt_o++;
                }    
                for(ll j=i+k;j<n;j+=k)
                {
                    s[j]=val;    
                }
            }
        }

        // deb(cnt_o);
        // deb(cnt_z);

        if(cnt_o!=cnt_z || cnt_o+cnt_z!=k)
            check=0;

        if(check==0)
        {
            cout<<"NO";
        }
        else
        {
            cout<<"YES";
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