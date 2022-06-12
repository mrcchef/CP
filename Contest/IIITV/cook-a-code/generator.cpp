#include "bits/stdc++.h"
#include <time.h>
#define ll long long int
#define MOD 1000000007 
#define oo 1000000000000000000
#define forr(i,n) for(int i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0) ; cout.tie(0);
#define all(x) x.begin(),x.end()
#define eb emplace_back
#define FF first
#define SS second
#define mem(a,v) memset(a,v,sizeof(a))
#define pb push_back
#define popcount(x) __builtin_popcount(x)

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
// struct custom_hash {
//     static uint64_t splitmix64(uint64_t x) {
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }
//     size_t operator()(uint64_t x) const {
//         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }
// };
int power(long long x,long long n,const long long P){
    if(x==0) return 0; 
    if(n==0 || x==1) return 1LL;
    x%=P;
    int res = 1;
    while(n>0){
        if(n&1) res = (ll) res * x %P;
        x = (ll) x * x % P;
        n/=2;
    }
    return res;
}
long long int power(long long int x,long long int n){
    if(x==0) return 0;
    else if(n==0 || x==1) return 1;
    long long res = 1;
    while(n>0){
        if(n&1) res *= x;
        x *= x;
        n /=2;
    }
    return res;
}
int inv(long long x){ return power(x,MOD-2,MOD);}
long long int gcd(const long long int a,const long long int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}
long long int lcm(const long long int a,const long long int b){
    return (a*b)/gcd(a,b);
}

pair<int,int> dx[4] = {make_pair(-1,0),make_pair(1,0),make_pair(0,-1),make_pair(0,1)};

ll NumInRange(ll l,ll r){
    return rand()%(r-l+1) + l;
}

struct node{
    char ch;
    ll a,b;
    node()
    {}
    node(char ch,ll a,ll b)
    {
        this->ch=ch;
        this->a=a;
        this->b=b;
    }
};

void __sol(){
    int t=1;
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    // cout<<NumInRange(0,0)<<endl;
    while(t--)
    {
        ll x,y;
        x=NumInRange(1,1e9);
        y=NumInRange(1,1e9);
        x=1e9;
        y=1e9;
        ll q;
        q=NumInRange(1,1e5);
        
        cout<<x<<" "<<y<<endl;
        cout<<q<<endl;

        vector<node> query;

        while(query.size()<q)
        {
            ll a,b;
            char ch;
            ll isPlus=NumInRange(1,2);
            if(isPlus==1)
                ch='+';
            else
                ch='-';
            
            a=NumInRange(1,1e4);
            b=NumInRange(1,1e4);

            if(ch=='+')
                x+=a,y+=b;
            else
                x-=a,y-=b;
            
            if(x<=0 || y<=0)
            {
                if(ch=='-')
                    x+=a,y+=b;
                else
                    x-=a,y-=b;
                continue;
            }
            else if(x>1e9 || y>1e9)
            {
                if(ch=='-')
                    x+=a,y+=b;
                else
                    x-=a,y-=b;
                continue;
            }

            ll gcd=__gcd(x,y);
            // debug(gcd);
            if(gcd>1e9)
            {
                if(ch=='-')
                    x+=a,y+=b;
                else
                    x-=a,y-=b;
                continue;
            }

            node ele=node(ch,a,b);
            query.push_back(ele);
        }

        for(auto &ele:query)
        {
            cout<<ele.ch<<" "<<ele.a<<" "<<ele.b<<endl;
        }
    }
    return;
}


int main(){    

    srand(time(0));
    clock_t time_req = clock();
    fastio
    ll tc=1;  // cin >> tc;
    while(tc--) __sol();
    time_req = clock() - time_req; 
  //  cerr << "Finished in: "<< (float)time_req/CLOCKS_PER_SEC << " seconds" << endl; 
    return 0;
}