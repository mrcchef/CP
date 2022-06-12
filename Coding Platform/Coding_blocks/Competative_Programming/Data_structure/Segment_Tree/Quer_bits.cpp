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
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

ll String_to_int(string s,ll l,ll r)
{
    ll k=s.size()-1,val=0;
    for(ll i=l;i<=r;i++)
    {
        val+=(s[i]-'0')*(fxp(2,k,mod));
        // deb(i);
        k--;
        // deb(s[i]-'0');
    }
    // deb(val);
    return val;    
}

void build_tree(vector<string> &tree,ll st,ll ed,ll index)
{
    if(st==ed)
    {
        tree[index]="0";
        return ;
    }
    ll mid=(st+ed)/2;
    build_tree(tree,st,mid,2*index);
    build_tree(tree,mid+1,ed,2*index+1);

    tree[index]=tree[2*index]+tree[2*index+1];
}

void change_to(string &s,char c,ll l,ll r)
{
    for(ll i=l;i<=r;i++)
    {
        s[i]=c;
    }
}

void update(vector<string> &tree,ll st,ll ed,ll l,ll r,ll index,char c)
{
    
    if(st>r || ed<l)
    {
        return ;
    }

    if(st==ed)
    {
        tree[index]=c;
        return ;
    }

    if(l<=st && r>=ed )
    {
        change_to(tree[index],c,st,ed);
        // deb(tree[index]);
    }    
    
    ll mid=(st+ed)/2;
    update(tree,st,mid,l,r,2*index,c);
    update(tree,mid+1,ed,l,r,2*index+1,c);

    tree[index]=tree[2*index]+tree[2*index+1];
}

string query(vector<string> tree,ll st,ll ed,ll l,ll r,ll index)
{
    // if(st==ed)
    //     return tree[index];

    if(r<st || l>ed)
        return "";
    
    if(l<=st && r>=ed)
    {
        return tree[index];
    }

    ll mid=(st+ed)/2;
    return query(tree,st,mid,l,r,2*index)+query(tree,mid+1,ed,l,r,2*index+1);

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,q;
    cin>>n>>q;
    vector<string> tree(4*n+2);
    build_tree(tree,0,n-1,1);
    // for(ll i=1;i<=5;i++)
    //     cout<<tree[i]<<" ";
    // cout<<endl;
    ll t,l,r;
    while(q--)
    {
        cin>>t>>l>>r;
        if(t==0)
            update(tree,0,n-1,l,r,1,'0');
        else if(t==1)
        {
            update(tree,0,n-1,l,r,1,'1');
            // for(ll i=1;i<=5;i++)
            //     cout<<tree[i]<<" ";
            // cout<<endl;
        }
        else
        {
            cout<<String_to_int(tree[1],l,r)<<endl;
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