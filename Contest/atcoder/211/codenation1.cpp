#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5;
vector<int> prime;
bool check[N];

vector<int> res(N,0);

vector<int> isPresent(N,0);

void init()
{
    int i;
    for(i=0;i<N;i++)
    {
        res[i]=0;
        isPresent[i]=0;
    }
}

void cal()
{
    for(int i=1;i<=N;i++)
        check[i]=true;
    check[0]=check[1]=false;
    for(int i=1;i<=N;i++)
    {
        
        res[i]+=isPresent[i]-1;
        if(isPresent[i]==0)
            continue;
        
       
            prime.push_back(i);
            for(int j=2*i;j<=N;j+=i)
            {
                
                check[j]=0;
                if(isPresent[i]==0)
                    continue;
            
                if(isPresent[j]==0)
                {
                    continue;
                }

                int inc=isPresent[i]+isPresent[j];
                res[j]+=isPresent[i];
                res[i]+=isPresent[j];
            }
        
    } 
}

vector<int> solve(vector<int> &v)
{
    int n,i;
    n=v.size();
    // init(); 
    for(i=0;i<n;i++)
    {
        isPresent[v[i]]++;
    }


    for(i=0;i<N;i++)
    {
        res[i]=0;
        isPresent[i]=0;
    }

    cal();

    vector<int> ans(n);

    for(i=0;i<n;i++)
    {
        ans[i]=res[v[i]];
    }

    return ans;
}

int main()
{
    int t=1;
    cin>>t;
    while(t--)
    {

        int n,i;
        cin>>n;
        vector<int> v(n);
        for(i=0;i<n;i++)
            cin>>v[i];

        init();        
        vector<int> ans=solve(v);

        for(auto val:ans)
            cout<<val<<" ";
        cout<<endl;  
    }
 return 0;
}

