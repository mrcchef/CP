#pragma GCC optimize("Ofast")   //Comment optimisations for interactive problems (use endl)
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  randomINIT     mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define  all(x)         (x).begin(),(x).end()
#define  mset(x,val)    memset(x,val,sizeof(x))
#define  endl           "\n"
#define  pb             push_back
#define  sym(s)         s="#"+s+"#";
#define  mp             make_pair
#define  s              second
#define  f              first
#define  dline          cerr<<"///REACHED///\n";
#define  debv(a)        for(auto it: a)cout<<it<<" ";cout<<endl;
#define  deb1(a)        cout<<a<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());

typedef  long long             ll;
typedef  unsigned long long    ull;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   MOD   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   N  =  105;

vll adj[N];ll vis[N]={};
int dx8[]={0,1,1,1,0,-1,-1,-1}, dy8[]={1,1,0,-1,-1,-1,0,1};
int dx4[]={0,1,0,-1}, dy4[]={1,0,-1,0};

//<<-----Declare Variable Here------->>//
int t=1;
ll n,a[N][N],dp1[N][N],dp2[N][N];
//<<-----Implement Functions Here---->>//


//<<-----Start of Main--------------->>//
void MAIN(){
		cin>>n;ll ans = -1e18;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				cin>>a[i][j];
			}
		}
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				dp1[i][j] = dp1[i-1][j-1] + a[i][j];
				dp2[i][j] = dp2[i-1][j+1] + a[i][j];
			}
		}

        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=n;j++)
            {
                cout<<dp1[i][j]<<" ";
            }
            cout<<endl;
        }

        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=n;j++)
            {
                cout<<dp2[i][j]<<" ";
            }
            cout<<endl;
        }

		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				ll lx = i,ly = j;ll rx = i,ry = j;
				ll ux = i,uy = j;ll dx = i,dy = j;
				ll temp = a[i][j];ans = max(ans,temp);
				for(ll k=1;k<=n;k+=2){
					ly--;ry++;ux--;dx++;
					if(ly < 1||ry > n||ux < 1||dx > n)break;
					// right diagonals
					temp += dp1[rx][ry] - dp1[ux-1][uy-1];
					temp += dp1[dx][dy] - dp1[lx-1][ly-1];
					// left diagonals
					temp += dp2[lx][ly] - dp2[ux-1][uy+1];
					temp += dp2[dx][dy] - dp2[rx-1][ry+1];
					temp -= a[lx][ly] + a[rx][ry] + a[ux][uy] + a[dx][dy];
					ans = max(ans,temp);
				}
			}
		}
		cout<<ans<<endl;

		//Clearing
		for(ll i=0;i<=n+3;i++){
			for(ll j=0;j<=n+3;j++){dp1[i][j] = 0;dp2[i][j] = 0;}
		}
	
}

int main(){
    fastio;randomINIT;

    cin>>t;
    while(t--){
        MAIN();
    }

    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}