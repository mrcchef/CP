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
    int n,d,k; cin >> d >> n >> k;
    map<int,vector<int>> m;
    forr(i,n){
        int h,l,r; cin >> h >> l >> r;
        m[l].eb(h);
        m[r+1].eb(-h);
    }
    Fenwick<int> f(300010);
    Fenwick<ll> fsum(300010);
    ll ans = 0 , tsum = 0;
    int curt = 0;
    for(auto &i: m){
        for(auto &j: i.SS){
            if(j < 0){
                curt--;
                f.update(-j , -1);
                fsum.update(-j,j);
                tsum += j;
            }
            else{
                curt++;
                tsum += j;
                f.update(j , 1);
                fsum.update(j,j);
            }
        }
        if(curt <= k){
            ans = max(ans , fsum.query(1 , 300010));
            continue;
        }
        int id = f.find(curt - k);
        ll cnt = fsum.query(1 , id - 1);
        int left = (curt - k) - f.query(1 , id - 1);
        cnt += 1LL * left * id;
        ans = max(ans , tsum - cnt);
    }
    cout << ans<<"\n";
    return;
}


int main(){ 
    fastio;
    int tc=1;  cin >> tc;
    for(int i=1;i<=tc;i++){
        cout <<"Case #"<<i<<": ";
        __sol();
    }
    return 0;
}