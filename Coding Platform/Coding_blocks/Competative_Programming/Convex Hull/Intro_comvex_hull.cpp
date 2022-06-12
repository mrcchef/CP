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

struct point{
    ll x,y;

    bool operator<(point &p)
    {
        if(x==p.x)
            return y<p.y;
        return x<p.x;
    }

    bool operator ==(point &p)
    {
        return p.x==x && p.y==y;
    }
}; 

bool acw(point a,point b,point c)
{
    return (b.y-a.y)*(c.x-b.x)<(c.y-b.y)*(b.x-a.x);
}

bool cw(point a,point b,point c)
{
    return (b.y-a.y)*(c.x-b.x)>(c.y-b.y)*(b.x-a.x);
}

bool collinear(point a,point b,point c)
{
    return (b.y-a.y)*(c.x-b.x)==(c.y-b.y)*(b.x-a.x);
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
        ll n,i;
        cin>>n;
        vector<point> p(n);
        fo(i,n)
        {
            cin>>p[i].x>>p[i].y;
        }    

        sort(p.begin(),p.end());

        point p1=p[0],p2=p[n-1];
        // p1 is the left most smallest pair 
        // p2 is the right most largest pair  
        vector<point> up,down;
        up.pb(p1);
        down.pb(p1);

        for(i=1;i<n;i++)
        {
            if(i==n-1 || !acw(p1,p[i],p2)) // checking, is the point p[i] lies up side 
            {
                while(up.size()>=2 && acw(up[up.size()-2],up[up.size()-1],p[i])) // if it the last three pair follows anticlock wise
                { // movement then we can remove the top element in the up vector 
                    up.pop_back();
                    // thisprocess would continue till we have alteast one triod including p[i] which follows anti colock wise movement
                }
                up.pb(p[i]);
                // then push the lastest elemet
            }
            // vice-versa 
            if(i==n-1 || !cw(p1,p[i],p2)) // checking, is the point p[i] lies down side 
            {
                while(down.size()>=2 && cw(down[down.size()-2],down[down.size()-1],p[i]))
                {
                    down.pop_back();
                }
                down.pb(p[i]);
            }
        }
    // now we are joing all thte poinnts from iup and down vector to create a convex hull
        p=up; 
        for(auto val:down)
            p.pb(val);

        sort(p.begin(),p.end());
        // this is to remove duplicate elements like p2 
        p.resize(unique(p.begin(),p.end())-p.begin());

        cout<<p.size()<<endl;
        for(auto val:p )
            cout<<val.x<<" "<<val.y<<endl;

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