//LinkedIn:https://www.linkedin.com/in/abhijeettamrakar/
//GitHub:https://github.com/mrcchef/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0) ; cout.tie(0);

class DSU{
    public:
    int n;
    vector<int> parent;
    vector<int> rank;
    
    DSU(int n)
    {
        this->n=n;
        parent=vector<int>(n+1,-1);
        rank=vector<int>(n+1,1);
    }

    int getParent(int node)
    {
        if(parent[node]==-1)
            return node;
        return parent[node]=getParent(parent[node]);
    }

    bool isCyclePresent(int node1,int node2)
    {
        int par1=getParent(node1);
        int par2=getParent(node2);

        return par1==par2;
    }

    bool mergeSet(int node1,int node2)
    {
        int par1=getParent(node1);
        int par2=getParent(node2);

        if(par1==par2)
            return false;
        
        if(rank[par1]<rank[par2])
        {
            parent[par1]=par2;
            rank[par2]+=rank[par1];
        }
        else
        {
            parent[par2]=par1;
            rank[par1]+=rank[par2];
        }

        return true;
    }
};

struct queryData{
    int node;
    int limit;
    int index;

    queryData(){}

    queryData(int node,int limit,int index){
        this->node=node;
        this->limit=limit;
        this->index=index;
    }
};

bool compare(queryData &q1,queryData &q2)
{
    return q1.limit<q2.limit;
}


void solve()
{
    int n,m,q,i,j;
    cin>>n>>m>>q;

    vector<vector<int>> edges(m);
    vector<queryData> queries(q);
    vector<int> ans(q);
    
    assert(n>=2 && n<=1e5);
    assert(m>=1 && m<=1e5);
    assert(q>=1 && q<=1e5);

    for(i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        assert(u>=1 && u<=n);
        assert(v>=1 && v<=n);
        assert(w>=1 && w<=1e9);
        vector<int> edge={w,u,v}; // wie, node1, node2
        edges[i]=edge;
    }

    for(i=0;i<q;i++)
    {
        int node,limit;
        cin>>node>>limit;
        assert(node>=1 && node<=n);
        assert(limit>=1 && limit<=1e9);
        queries[i]=queryData(node,limit,i);
    }

    sort(edges.begin(),edges.end());
    sort(queries.begin(),queries.end(),compare);    

    DSU ds(n);

    j=0;
    i=0;

    while(i<q)
    {
        while(j<m && edges[j][0]<=queries[i].limit)
        {
            int u=edges[j][1];
            int v=edges[j][2];
            ds.mergeSet(u,v);
            j++;            
        }

        int root=ds.getParent(queries[i].node);
        int len=ds.rank[root];

        ans[queries[i].index]=len;
        i++;
    }    

    for(i=0;i<q;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    fastio
    #ifdef ONLINE_JUDGE
         freopen("Error.txt", "w", stderr);
    #endif
    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();   
    }
 return 0;
}