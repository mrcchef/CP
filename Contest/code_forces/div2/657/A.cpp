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

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
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
        ll n;
        cin>>n;
        string s,orig="abacaba";
        cin>>s;
        ll cnt=0;
        for(ll i=0;i<=n-7;i++)
        {
            ll k=0,flag=0;
            for(ll j=i;j<i+7;j++)
            {
                if(s[j]!=orig[k++])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
                cnt++;
        }
        if(cnt>1)
        {
            cout<<"NO"<<endl;
        }
        else if(cnt==1)
        {
            for(ll i=0;i<n;i++)
            {
                if(s[i]=='?')
                {
                    s[i]='z';
                }
            }
            cout<<"YES"<<endl;
            cout<<s<<endl;
        }
        else
        {
            ll found=0;
            for(ll i=0;i<=n-7;i++)
            {
                ll flag=0;
                if(s[i]==orig[0] || s[i]=='?')
                {
                    ll k=1;
                    for(ll j=i+1;j<i+7;j++)
                    {
                        if(s[j]!=orig[k] && s[j]!='?')
                        {
                            flag=1;
                            break;
                        }
                        k++;
                    }
                    if(flag==0)
                    {
                        ll k=0;
                        for(ll j=i;j<i+7;j++)
                        {
                            if(s[j]=='?')
                            {
                                s[j]=orig[k];
                            }
                            k++;
                        }
                        found=1;
                        break;
                    }
                }       
            }
            if(found==1)
            {
                for(ll i=0;i<n;i++)
                {
                    if(s[i]=='?')
                    {
                        s[i]='z';
                    }
                }
                cout<<"YES"<<endl;
                cout<<s<<endl;
            }
            else
            {
                cout<<"NO"<<endl;;
            }
        }
    }
 return 0;
}
ll fxp(ll a,ll b,ll m) {
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp(a*a,b/2,m);
    return fxp(a,b-1,m)*a;
}
