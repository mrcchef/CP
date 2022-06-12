//LinkedIn:https://www.linkedin.com/in/abhijeettamrakar/
//GitHub:https://github.com/mrcchef/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0) ; cout.tie(0);

#define ll long long
ll getAns(ll n)
{
    return (n*(n-1))/2;
}

void solve()
{
    ll x,y;
    cin>>x>>y;
    ll q;
    cin>>q;

    assert(x>=1 && x<=1e9);
    assert(y>=1 && y<=1e9);
    assert(q>=1 && q<=1e5);
    
    while(q--)
    {
        char t;
        ll a,b;
        cin>>t>>a>>b;

        assert(t=='-' || t=='+');
        assert(a>=0 && a<=1e4);
        assert(b>=0 && b<=1e4);

        if(t=='+')
        {
            x+=a;
            y+=b;
        }
        else
        {
            x-=a;
            y-=b;
        }

        assert(x>=1 && x<=1e9);
        assert(y>=1 && y<=1e9);
    
        ll gcd=__gcd(x,y);
        ll ans=getAns(gcd);

        cout<<ans<<endl;
    }
}

int main()
{
    fastio
    solve();   
    return 0;
}