#include <bits/stdc++.h>
using namespace std;


const int N=2e5+5;

vector<vector<int>> g(N);

vector<int> len(N,0);

void dfs2(int node,int parent)
{
    if(node==parent)
        return;

    len[node]=1;
    
    // cout<<"Node"<<node<<endl;
    // cout<<"Pa"<<parent<<endl;
    int flag=0;

    for(auto nbr:g[node])
    {
        if(nbr==parent)
            continue;
        flag=1;
        dfs2(nbr,node);

        len[node]+=len[nbr];
    }
    cout<<len[node]<<endl;
}

void dfs(int node,int parent,vector<int> &mex,vector<int> &c,vector<int> &isPresent)
{

    // ll currMex;
    isPresent[node]=1;
    cout<<"Node"<<node<<endl;
    if(node==parent)
        return;
    // if(g[node].size()==1)
    // {
    //     if(c[node]==0)
    //         return 1;
    //     else
    //         return 0;
    // }

    // set<ll> st;
    
    // st.insert(c[node]);
    // ll flag=0;

    for(auto nbr:g[node])
    {
        if(nbr==parent)
            continue;

        // st.insert(c[nbr]);
        dfs(nbr,node,mex,c,isPresent);
        // range mex= 0 to 
    }

    for(int val=0;val<=len[node];val++)
    {
        if(isPresent[val]==0)
        {
            mex[node]=val;
            break;
        }
    }

    isPresent[node]=0;
}

vector<int> solve(int a,vector<vector<int>> &b,vector<int> c)
{
    for(auto p:b)
    {
        g[p[0]].push_back(p[1]);
        g[p[1]].push_back(p[0]);
    }

    dfs2(0,-1);


    vector<int> mex(a);
    vector<int> isPresent(a,0);

    dfs(0,-1,mex,c,isPresent);

    return mex;
}

int main()
{
    // fastio
    // #ifdef ONLINE_JUDGE
    //      freopen("Error.txt", "w", stderr);
    // #endif
    int t=1;
    // cin>>t;
    while(t--)
    {
        int a;
        cin>>a;

        int i;

        vector<vector<int>> b(a,vector<int>(2));
        for(i=0;i<a-1;i++)
        {
            cin>>b[i][0]>>b[i][1];
            cout<<b[i][0]<<" "<<b[i][1]<<endl;
        }

        vector<int> c(a);

        for(i=0;i<a;i++)
            cin>>c[i];

        vector<int> mex=solve(a,b,c);

        for(auto val:mex)
            cout<<val<<" ";
        cout<<endl;   
    }
 return 0;
}
