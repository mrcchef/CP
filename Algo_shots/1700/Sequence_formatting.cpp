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

// prev=1 i.e space
// prev=2 i.e number
// prev=3 i.e. ...

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        string s,res;
        getline(cin,s);
        ll sz=s.size();
        ll i=0,k=0;
        while(i<sz)
        {
            string tmp;
            while( i<sz && s[i]!=',' )
            {
                tmp+=s[i];
                i++;
            }
            // deb(tmp);
            ll j=0,tsz=tmp.size(),prev=1,prev_prev=-1;
            // if it is not the begnning then we can add space
            if(k!=0)
            {
                res+=' ';
                k++;
            }
            while(j<tsz)
            {
                if(tmp[j]=='.') // if we encounter '.' this means we need to add a space before it
                {
                    if((prev==1 && (prev_prev==3)) ||(prev!=1)) // for adding a space we make sure that already we have inserted
                    {                       // space or not or if it is already inserted then it must be '...' b/c we have not 
                        res+=' ';           // inserted space in the below else if when the prev is '...'. so, actually we need to add
                        k++;                // a space here 
                    }
                    res+="...";
                    k+=3;
                    j+=3;
                    prev_prev=prev;
                    prev=3;
                }
                else if(tmp[j]==' ') // if we encounter a space then we simply travese the subarray of spaces then is the 
                {   // prev element is number then we should add a space and also number should not be the end of the string
                    while(j<tsz && tmp[j]==' ')
                        j++;
                    if(prev==2 && j!=tsz)
                    {
                        res+=' ';
                        k++;
                    }
                    prev_prev=prev;
                    prev=1;
                }
                else if(tmp[j]>=48 && tmp[j]<=58)  // if it is a number then simply add to our resulting string and then continue
                {
                    res+=tmp[j];
                    j++;
                    k++;
                    prev_prev=prev;
                    prev=2;
                }
            }
            if(i!=sz) // this is to add the , after end of the segment but that segment should not be the last segment of the string
            {
                res+=',';
                k++;
                i++;
            }
        }
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