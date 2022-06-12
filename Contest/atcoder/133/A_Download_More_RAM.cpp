#include <bits/stdc++.h>
using namespace std;
// #define fastio 

#define fo(i,n) for(i=0;i<n;i++)
#define ll long long
#define pb push_back
#define mii map<ll,ll>
#define vi vector<ll>
#define endl "\n"


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0) ; cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;

        // array 
        vector<pair<int,int>> v(n);
        ll i;

        for(i=0;i<n;i++)
        {
            cin>>v[i].first;
        }

        for(i=0;i<n;i++)
            cin>>v[i].second;


        sort(v.begin(),v.end());


        for(i=0;i<n;i++)
        {
            if(k<v[i].first)
            {
                break;
            }
            else
            {
                k+=v[i].second;
            }
        }

        cout<<k<<endl;   
    }
 return 0;
}
