class DSU{
    public:
    ll n;
    vi parent;
    vi rank;
    
    DSU(ll n)
    {
        this->n=n;
        parent=vi(n+1,-1);
        rank=vi(n+1,1);
    }

    ll getParent(ll node)
    {
        if(parent[node]==-1)
            return node;
        return parent[node]=getParent(parent[node]);
    }

    bool isCyclePresent(ll node1,ll node2)
    {
        ll par1=getParent(node1);
        ll par2=getParent(node2);

        return par1==par2;
    }

    bool mergeSet(ll node1,ll node2)
    {
        ll par1=getParent(node1);
        ll par2=getParent(node2);

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