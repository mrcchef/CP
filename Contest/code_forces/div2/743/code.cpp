/*  Jai Shree Ram 🚩🚩🚩 */
#include "bits/stdc++.h"
#define ll long long int
#define oo 1000000000000000000
#define forr(i,n) for(int i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
#define unique(v) sort(all(v)); v.resize(distance(v.begin(),unique(all(v))))
#define eb emplace_back
#define FF first
#define SS second
#define ff first
#define ss second
#define mem(a,v) memset(a,v,sizeof(a))
#define pb push_back
#define popcount(x) __builtin_popcount(x)
#define lld long double
using namespace std;

// debugging code
// ---------------------------------------------------------------------------------------------------------------------------------
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
// void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// ---------------------------------------------------------------------------------------------------------------------------------


template<typename T>
ostream &operator<<(ostream &output,const vector<T> &v){ 
    if(v.empty()) return output;
    for(int i=0;i<v.size()-1;i++) output << v[i] <<" ";
    output << v.back();
    return output;
}
template<typename T>
istream &operator>>(istream &input,vector<T> &v){ 
    for(auto &i: v) cin >> i;
    return input;            
}

template<typename T>
class Fenwick{
    private:
        vector<T> bit;
        int n;
        template<typename T1>
        T sum(T1 id){
            T ans = 0;
            while(id>0) ans+=bit[id] , id -= id & -id;
            return ans;
        }
    public:
        template<typename T1>
        Fenwick(T1 n){
            this->n = n;
            bit.assign(n+2,0);
        }
        template<typename T1,typename T2>
        void update(T1 id,T2 val){
            while(id<=n) bit[id]+= val , id += id & -id;
        }
        template<typename T1,typename T2>
        T query(T1 l,T2 r){
            return sum(r) - sum(l-1);
        }
        template<typename T1>
        int find(T1 k){
            int pos = 0;
            T pre = 0;
            for(int i=log2(n);i>=0;i--){
                if( pos + (1<<i) <= n && pre + bit[pos + (1<<i)] < k ){
                    pos += (1<<i);
                    pre += bit[pos];
                }
            }
            return pos + 1;
        }
};

#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;

void __sol(){
    int n,m; cin >> n >> m;
    vector<int> v(n*m); cin >> v;
    vector<pair<int,int>> q;
    forr(i,n*m){
        q.eb(v[i] , i);
    }

    debug(q);

    sort(all(q));

    debug(q);
    map<pair<int,int>,int> mp;

    forr(i,n*m) mp[q[i]] = i;

    debug(mp);

    map<int,vector<int>> ids;
    forr(i,n*m){
        ids[i/m].eb( q[i].FF );
    }

    debug(ids);

    for(auto &i: ids){
        unique(i.SS);
    }

    debug(ids);

    vector<Fenwick<int>> f(n , Fenwick<int>(m));
    ll ans = 0;

    debug(v);

    forr(i,n*m){
        int num = mp[{v[i],i}];
        debug(i);
        ll r=num/m;
        debug(num);
        int pos = lower_bound(all( ids[num/m] ) , v[i]) - ids[num/m].begin();
        
        debug(make_pair(r,pos));
        ll tans=f[ num/m ].query(1 , pos );
        if(1<=pos) ans += f[ num/m ].query(1 , pos );
        debug(tans);
        f[num/m].update(pos + 1 , 1 );
        // cout << pos%m<<" ->";
    }
    cout << ans<<"\n";

    return;
}


int main(){ 
    fastio;
    int tc=1; cin >> tc;
    while(tc--) __sol();
    return 0;
}