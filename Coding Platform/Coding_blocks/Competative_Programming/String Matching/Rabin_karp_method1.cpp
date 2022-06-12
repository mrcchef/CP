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

ll p=31;
ll p_power=1;
// This method used the concept of sliding window of a fixed size
ll hash_v(string str)
{
    ll hashVal=0;
    p_power=1;
    for(ll i=0;i<str.size();i++)
    {
        hashVal+=p_power*(str[i]-'a'+1);
        // cout<<hashVal<<endl;
        p_power*=p;
        hashVal%=mod;
        p_power%=mod;
    } 
    return hashVal;
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
        string str,w;
        cin>>str>>w;
        ll hashW=hash_v(w);
        ll hashsub=hash_v(str.substr(0,w.size()));
        // deb(hashW);
        // deb(hashsub);
        ll mod_in=fxp(31,mod-2,mod);
        ll i,flag=0;
        p_power/=p;
        for(i=0;i+w.size()<=str.size()-1;i++)
        {
            if(hashW==hashsub)
            {
                // first occurance of the substring 
                flag=i+1;
                break;
            }

            hashsub-=(str[i]-'a'+1);
            hashsub*=mod_in;
            hashsub+=(str[i+w.size()]-'a'+1)*p_power;
            hashsub%=mod;
        }
        // deb(p_power);
        if(hashW==hashsub)
            flag=i+1;
        
        if(flag==0)
        {
            cout<<"Not matched";
        }
        else 
            cout<<"Fount at index "<<flag;
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