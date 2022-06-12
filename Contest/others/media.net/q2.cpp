#include <bits/stdc++.h>
using namespace std;
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; i <= n; i++)
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<ll, ll>
#define pii pair<ll, ll>
#define vi vector<ll>
#define endl "\n"
#define deb(x) cout << #x << "=" << x << endl
#define yy cout << "YES" << endl
#define nn cout << "NO" << endl
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef unsigned long long ull;
typedef long double lld;
const ll mod = 1e9 + 7;

ll msum(ll a, ll b, ll map) { return (a % map + b % map) % map; }
ll msub(ll a, ll b, ll map) { return (a % map - b % map) % map; }
ll mpro(ll a, ll b, ll map) { return ((a % map) * (b % map)) % map; }
ll expo(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}
void swap(ll &a, ll &b)
{
    ll t = a;
    a = b;
    b = t;
}
void sieve(ll n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (ll i = 2; i * i <= n; i++)
    {
        if (prime[i] == true)
        {
            for (ll j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }
}

//use this when n>10^7 and mask array can't be made in sieve
//This gives us a vector which has all the prime factors of upto root of 10^9
vector<ll> sieve_vector(int n)
{
    ll arr[n + 1];
    vector<ll> vect;
    for (int i = 2; i <= n; i++)
        if (arr[i] == 0)
        {
            vect.push_back(i);
            for (int j = i * i; j <= n; j += i)
                arr[j] = 1;
        }
    return vect;
}
//vector<ll> v1 = sieve(31623); //coz root of 10^9 is near to this value

string solve(int A, vector<string> &B)
{
    map<string, int> map;
    int maximum = 0;
    string ans;
    for (int i = 0; i < A; i += 2)
    {
        int x = stoi(B[i + 1]);
        map[B[i]] += x;
    }

    for (auto g : map)
    {
        if (g.second > maximum)
        {
            maximum = g.second;
        }
    }
    
    vector<pair<string, int>> a;
    for (auto g : map)
    {
        if (g.second == maximum)
        {
            a.push_back(make_pair(g.first, 0));
        }
    }
    for (auto &g : a)
    {
        string str = g.first;
        for (int i = 0; i < A; i += 2)
        {
            if (B[i] == str)
            {
                g.second = i;
            }
        }
    }
    maximum = A;
    for (auto g : a)
    {
        if (g.second <= maximum)
        {
            maximum = g.second;
            ans = g.first;
        }
    }
    return ans;
}

int main()
{
    fastio
#ifdef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
#endif
    int n;
    cin >> n;
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;
        v.push_back(a);
        v.push_back(b);
    }
    {
        cout << solve(n, v);
    }
}