#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
ll MOD = 1e9 + 7;

class point {
public:
  ll x, y, t;
  point() {}
  point(ll x, ll y, ll t) : x(x), y(y), t(t) {}
};

ll sq(ll a) {
  return a * a;
}

ll value(const point& position, const point& spiral, bool right, bool clockwise) {
  ll x = (not right) ? spiral.x - position.x : position.x - spiral.x;
  ll y = ((not right and not clockwise) or (right and clockwise)) ? spiral.y - position.y : position.y - spiral.y;
  ll result;
  cout<<"x:"<<x<<" y:"<<y<<endl;
  if(abs(x) > abs(y) && x > 0)
    result = 4*sq(x) - 3*x + y;
  else if(abs(x) > abs(y) && x <= 0)
    result = 4*sq(x) - x - y;
  else if(abs(x) <= abs(y) && y > 0)
    result = 4*sq(y) - y - x;
  else
    result = 4*sq(y) - 3*y + x;
  return result;
}

void solve() {
  ll n, q;
  cin >> n >> q;
  vector<tuple<point, bool, bool>> v(n);

  assert(n>=1 && n<=1e3);
  assert(q>=1 && q<=1e2);

  for(int i = 0; i < n; i++) {
    ll x, y, t;
    string r, c;
    cin >> x >> y >> t >> r >> c;
    v[i] = {{x, y, t}, r == "right", c == "clockwise"};
    assert(x>=-1e8 && x<=1e8);
    assert(y>=-1e8 && y<=1e8);
    assert(t>=-1e8 && t<=1e8);
  }
  for(int i = 0; i < q; i++) {
    ll ans = 0;
    point p;
    cin >> p.x >> p.y >> p.t;
    for(int j = 0; j < n; j++) {
      ll val = value(p, get<0>(v[j]), get<1>(v[j]), get<2>(v[j]));
      cout<<val<<" ";
      if(p.t >= val + get<0>(v[j]).t) {
        ans += val;
      }
    }
    cout << ans << "\n";
  }
}

int main() {
  int cases;
  cin >> cases;
  assert(cases>=1 && cases<=1e2);
  while (cases--)
    solve();
}
