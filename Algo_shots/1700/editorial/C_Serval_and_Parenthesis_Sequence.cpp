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

// A correct parenthesis sequence is a parenthesis sequence that can be transformed into a 
// correct arithmetic expression by inserting characters "1" and "+" between the original 
// characters of the sequence. For example, parenthesis sequences "()()", "(())" are 
// correct (the resulting expressions are: "(1+1)+(1+1)", "((1+1)+1)"), while ")(" and ")"
//  are not. Note that the empty string is a correct parenthesis sequence by definition.

// A string in which the number of opening brackets are always greater than the closeing one 
// and the total number of opening and closing brackets should be equal.

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
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll n,i;
        cin>>n;
        string s;
        cin>>s;
        if(n&1)
        {
            cout<<":("<<endl;
            continue;
        }
        ll cnto=0,cntc=0;
        fo(i,n)
        {
            if(s[i]=='(')
            {
                cnto++;
            }
            else if(s[i]==')')
            {
                cntc++;
            }
        }

        ll rmo=n/2-cnto;
        ll rmc=n/2-cntc;

        if(rmo<0 || rmc<0)
        {
            cout<<":("<<endl;
            continue;
        }

        fo(i,n)
        {
            if(s[i]=='?')
            {
                if(rmo>0)
                {
                    s[i]='(';
                    rmo--;
                }
                else
                {
                    s[i]=')';
                    rmc--;
                }
            }
        }

        ll sm=0,flag=0;

        fo(i,n)
        {
            if(s[i]=='(')
            {
                sm++;
            }
            else
            {
                sm--;
            }

            if(sm<=0 && i!=n-1)
            {
                flag=1;
                break;
            }
            
        }

        if(flag==1 || sm!=0)
        {
            cout<<":("<<endl;
        }
        else
        {
            cout<<s<<endl;
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