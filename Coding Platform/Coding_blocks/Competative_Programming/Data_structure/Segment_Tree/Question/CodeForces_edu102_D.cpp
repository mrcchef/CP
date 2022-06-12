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

const int N = 1e5 + 5;
const int INF = 1e9;


/*
KEYNOTES:
------------------------------------------
merge(X,identity_element) = X
------------------------------------------
------------------------------------------
identity_transformation.combine(X) = X
------------------------------------------
------------------------------------------
ALWAYS: older_update.combine(newer_update)
------------------------------------------
*/



// example: addition: identity element is 0

// a + 0 = a or 0 + a = a

// min(x,INF) = x

struct node
{
	int mn = INT_MAX;
	int mx = INT_MIN;
    // intialization should be identity element
	// use more variables if you want more information
	// these default values should be identity_element
	node(){}
	node(int val){
		mn=mx=val;
	}
	void merge(const node &l,const node &r){ // store the thing you wanna query
		
        mx=max(l.mx,r.mx);
        mn=min(l.mn,r.mn);

		// mn = min(l.mn,r.mn);
		// freq = 0;
		// if(l.mn == mn) freq += l.freq;
		// if(r.mn == mn) freq += r.freq;
		
		// if we wanted the maximum, then we would do
		// like v = max(l.v,r.v)
	}
};

// example: add on a range: identity transformation = 0
// old += new

// if old is identity which is 0, then 0 + new which new

struct update
{
	int v = 0; // 4
	// use more variables if you want more information
	// these default values should be identity_transformation
	update(){}
	update(int val){
		v = val; // 5
	}
	// combine the current my_update with the other my_update (see keynotes)
	void combine(update &other,const int32_t &tl,const int32_t &tr){
		v += other.v; // 6
		// you can be sure that the "other" is newer than current
        // v is the newer value after update so, write experession accordingly
		
	}
	// store the correct information in the my_node x
	void apply(node &x,const int32_t &tl,const int32_t &tr){
		// no change in freq
		x.mn += v;
        // After all updation we are applying this update to our segment tree
	}
};

// template<typename node,typename update>
struct segtree
{
	int len;
	vector<node> t;
	vector<update> u;
	vector<bool> lazy;
	node identity_element;
	update identity_transformation;
	segtree(int l){
		len = l;
		t.resize(4 * len);
		u.resize(4 * len);
		lazy.resize(4 * len);
		identity_element = node();
		identity_transformation = update();
	}
	
	void pushdown(const int32_t &v, const int32_t &tl, const int32_t &tr){
		if(!lazy[v]) return;
		int32_t tm = (tl + tr) >> 1;
		apply(v<<1,tl,tm,u[v]);
		apply(v<<1|1,tm+1,tr,u[v]);
		u[v] = identity_transformation;
		lazy[v] = 0;
	}
	
	void apply(const int32_t &v, const int32_t &tl, const int32_t &tr, update upd){
		if(tl != tr){
			lazy[v] = 1;
			u[v].combine(upd,tl,tr);
		}
		upd.apply(t[v],tl,tr);
	}
	
	template<typename T>
	void build(const T &arr,const int32_t &v, const int32_t &tl, const int32_t &tr){
		if(tl == tr){
			t[v] = arr[tl];
			return;
		}
		int32_t tm = (tl + tr) >> 1;
		build(arr,v<<1,tl,tm);
		build(arr,v<<1|1,tm+1,tr);
		t[v].merge(t[v<<1],t[v<<1|1]);
	}
	
	node query(const int32_t &v,const int32_t &tl,const int32_t &tr,const int32_t &l,const int32_t &r){
		if(l > tr || r < tl){
			return identity_element;
		}
		if(tl >= l && tr <= r){
			return t[v];
		}
		pushdown(v,tl,tr);
		int32_t tm = (tl + tr) >> 1;
		node a = query(v<<1,tl,tm,l,r),b = query(v<<1|1,tm+1,tr,l,r),ans;
		ans.merge(a,b);
		return ans;
	}
	
	// rupd = range update
	void rupd(const int32_t &v,const int32_t &tl,const int32_t &tr,const int32_t &l,const int32_t &r,const update &upd){
		if(l > tr || r < tl){
			return;
		}
		if(tl >= l && tr <= r){
			apply(v,tl,tr,upd);
			return;
		}
		pushdown(v,tl,tr);
		int32_t tm = (tl + tr) >> 1;
		rupd(v<<1,tl,tm,l,r,upd);
		rupd(v<<1|1,tm+1,tr,l,r,upd);
		t[v].merge(t[v<<1],t[v<<1|1]);
	}
	
	public:
	template<typename T>
	void build(const T &arr){
		build(arr,1,0,len-1);
	}
	node query(const int32_t &l,const int32_t &r){
		return query(1,0,len-1,l,r);
	}
	void rupd(const int32_t &l,const int32_t &r,const update &upd){
		rupd(1,0,len-1,l,r,upd);
	}
};

int main()
{
    fastio
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k,i;
        cin>>n>>k;
        string s;
        cin>>s;
        vi pref(n+1,0);
        fo(i,n)
        {
            if(s[i]=='-')
            {
                pref[i+1]=pref[i]-1;
            }
            else
            {
                pref[i+1]=pref[i]+1;
            }
        }
        // for(i=0;i<=n;i++)
        //     cout<<pref[i]<<" ";
        // cout<<endl;
        segtree sg(n+1);
        sg.build(pref);
        fo(i,k)
        {
            ll l,r;
            cin>>l>>r;
            ll mx=0,mn=0;
            ll diff=pref[r]-pref[l-1];
            // deb(diff);
            if(l>1)
            {
                mx=max(mx,sg.query(1,l-1).mx*1LL);
                mn=min(mn,sg.query(1,l-1).mn*1LL);
            }
            if(r<n)
            {
                mx=max(mx,sg.query(r+1,n).mx*1LL-diff);
                mn=min(mn,sg.query(r+1,n).mn*1LL-diff);
            }
            ll ans=mx-mn+1;
            // ll ans=(sg.query(1,l-1).mx-sg.query(1,l-1).mn+1)+(sg.query(r+1,n).mx-sg.query(r+1,n).mn+1)-(pref[r]-pref[l-1]);
            cout<<ans<<endl;
            // cout<<sg.query(l,r).mn<<" "<<sg.query(l,r).mx<<endl;
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