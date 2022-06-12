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
        string y,a,chter="!#%*@";
        map<char,ll> m;
        for(ll i=0;i<5;i++)
            m[chter[i]]=i;
        cin>>y>>a;
        ll sz=y.size();
        string s;
        if(sz&1)
        {
            s+='3';
            for(ll i=1;i<=(sz+1)/2;i++)
                s+='0';
            for(ll i=1;i<=sz/2;i++)
                s+='3';
        }
        else
        {
            ll check=0;
            if(m[y[0]]<3)
            {
                s+='3';
                for(ll i=1;i<=sz/2;i++)
                    s+='0';
                for(ll i=1;i<sz/2;i++)
                    s+='3';
            }
            else
            {
                ll check=0;
                ll cnts=0,cntz=0;
                for(ll i=0;i<sz;i++)
                {
                    if(m[y[i]]>3 && check==0)
                    {
                        string temp;
                        temp+='3';
                        for(ll j=1;j<=(sz/2)+1;j++)
                        {
                            temp+='0';
                        }
                        for(ll j=1;j<(sz/2)+1;j++)
                            temp+='3';
                        s=temp;
                        break;
                    }
                    else if(m[y[i]]==3)
                    {
                        if(cnts==sz/2-1)
                        {
                            if(cntz==0)
                            {
                                string temp;
                                temp+='3';
                                for(ll j=1;j<=(sz/2)+1;j++)
                                    temp+='0';
                                for(ll j=1;j<=(sz/2);j++)
                                    temp+='3';
                                s=temp;
                                break;
                            }
                            else
                            {
                                s+='3';
                                for(ll j=i-1;j>=0;j--)
                                {
                                    if(s[j]=='0')
                                    {
                                        s[j]='3';
                                        s[j+1]='0';
                                        break;
                                    }   
                                }
                            }
                        }
                        else
                        {
                            cnts++;
                            s+='3';
                        }
                        
                    }
                    else if(m[y[i]]==0)
                    { 
                        cntz++;
                        s+='0';
                        check=1;
                    }
                    else
                    {
                        check=1;
                        if(cnts==sz/2)
                        {
                            string temp;
                            temp+='3';
                            for(ll j=1;j<=(sz/2)+1;j++)
                                temp+='0';
                            for(ll j=1;j<=(sz/2);j++)
                                temp+='3';
                            s=temp;
                            break;
                        }
                        s+='3';
                        cnts++;
                    }
                    
                }
            }
        }
        deb(s);
        reverse(s.begin(),s.end());
        reverse(a.begin(),a.end());
        string res;
        ll i=0,carry=0;
        if(s.size()>=a.size())
        {
            for(i;i<a.size();i++)
            {
                ll val=(s[i]-'0')+(m[a[i]])+carry;
                carry=val/5;
                val=val%5;
                res+=chter[val];
            }
            for(;i<s.size();i++)
            {
                ll val=(s[i]-'0')+carry;
                carry=val/5;
                val=val%5;
                res+=chter[val];
            }
            // deb(res);
            if(carry!=0)
            {
                res+=chter[carry];
            }   
        }
        else
        {
            for(i;i<s.size();i++)
            {
                ll val=(s[i]-'0')+(m[a[i]])+carry;
                carry=val/5;
                val=val%5;
                res+=chter[val];
            }
            for(;i<a.size();i++)
            {
                ll val=(m[a[i]])+carry;
                carry=val/5;
                val=val%5;
                res+=chter[val];
            }
            if(carry!=0)
            {
                res+=chter[carry];
            }   
        }
        reverse(res.begin(),res.end());
        cout<<res<<endl;
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