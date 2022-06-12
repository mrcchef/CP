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
        ll n,i;
        cin>>n;
        vi v(n);
        vi freq(n+1,0);
        fo(i,n)
            cin>>v[i];

        fo(i,n)
            freq[v[i]]++;

        int curMex=0;
        int st=0;

        vector<int> tempFreq(n+1,0);
        
        vi res;

        for(i=0;i<n;i++)
        {
            freq[v[i]]--;
            tempFreq[v[i]]++;
            while(tempFreq[curMex]>0)   
                curMex++;
            
            if(freq[curMex]>0)
            {

            }
            else
            {
                res.pb(curMex);
                curMex=0;
                for(int j=st;j<=i;j++)
                {
                    tempFreq[v[j]]--;
                }
                st=i+1;
            }   
        }

        cout<<res.size()<<endl;
        for(auto val:res)
            cout<<val<<" ";
        cout<<endl;  
    }
 return 0;

}
