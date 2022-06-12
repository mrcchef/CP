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
#define mem(a,v) memset(a,v,sizeof(a))
#define pb push_back
#define popcount(x) __builtin_popcount(x)

using namespace std;

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


void __sol(){
    int n,m; cin >> n >> m;
    vector<int> v(n*m); cin >> v;
    vector<pair<int,int>> q;
    forr(i,n*m){
        q.eb(v[i] , i);
    }

    sort(all(q),[&](pair<int,int> &a,pair<int,int> &b){
        if(a.FF == b.FF) return a.SS < b.SS;
        return a.FF < b.FF;
    });
    map<pair<int,int>,int> mp;
    forr(i,n*m) mp[q[i]] = i;
    map<int,vector<int>> ids;
    forr(i,n*m){
        ids[i/m].eb( q[i].FF );
    }
    for(auto &i: ids){
        unique(i.SS);
    }
    vector<Fenwick<int>> f(n , Fenwick<int>(m));
    ll ans = 0;
    forr(i,n*m){
        int num = mp[{v[i],i}];
        int pos = lower_bound(all( ids[num/m] ) , v[i]) - ids[num/m].begin();
        if(1<=pos) ans += f[ num/m ].query(1 , pos );
        f[ num/m  ].update(pos + 1 , 1 );
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