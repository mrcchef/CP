#include<bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
    #define debug(x);
#endif

#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<=n;i++)
#define ll long long
#define ull unsigned long long
#define lld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define endl "\n"
const ll MOD = 1e9+7;
const ll MOD1= 998244353;
#define popcount(x) __builtin_popcount(x)
#define all(x) x.begin(),x.end()
#define mem(a,v) memset(a,v,sizeof(a))
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))

char buf[200043];

// // debugging code
// // ---------------------------------------------------------------------------------------------------------------------------------
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

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
// // ---------------------------------------------------------------------------------------------------------------------------------


int main()
{
	int t;
	scanf("%d", &t);
	for(int tc = 1; tc <= t; tc++) {
		int n;
		scanf("%d", &n);
		scanf("%s", buf);
		string s = buf;
		queue<int> q;
		int cur = 0;
		for(int i = 0; i < n; i++)
		{
		 	if(i > 0 && s[i] != s[i - 1])
		 		cur++;
		 	if(i > 0 && s[i] == s[i - 1])
             {
                 debug(i)
                 debug(s[i])
                 debug(cur)
		 		q.push(cur);
             }
		}
		int deleted = 0;       
		int score = 0;
		for(int i = 0; i < n; i++)
		{
			if(q.empty())
				break;
            debug(q.front())
			q.pop();
            debug(deleted)
            debug(score)
            debug(i)
			deleted++;
			score++;
            debug(deleted)
            debug(score)
			while(!q.empty() && q.front() == i)
			{
				q.pop();
				deleted++; 	
			}
			deleted++;
            debug(deleted);
			//cerr << deleted << endl;
		}
		score += (n - deleted + 1) / 2;
		printf("%d\n", score);
	}
}