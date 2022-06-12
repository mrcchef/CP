#include <bits/stdc++.h>
using namespace std;

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
        ll l,r,k;
        cin>>l>>r>>k;

        int ans1=(l)/2;
        int ans2=(r+1)/2;

        int res=ans2-ans1;

        if(l-r+1==1)
        {
            if(l!=1)
            {
                cout<<"YES";
            }
            else
                cout<<"NO";
            cout<<endl;
            // return 0;
        }
        else
        {
            if(k>=res)
        {
            cout<<"YES";
        }
        else
            cout<<"NO";
        cout<<endl;
        }


        
    }
 return 0;
}