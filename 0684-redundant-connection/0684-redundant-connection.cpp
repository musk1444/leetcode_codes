class disjointset{
    public:

    vector<int> rank;
    vector<int> parent;
    
    disjointset(int n)
    {
        rank.resize(n+1);
        parent.resize(n+1);
        for(int i = 0; i<n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int findultparent(int node)
    {
        if(parent[node] == node)
        {
            return node;
        }
        return parent[node] = findultparent(parent[node]);
    }

    void unionbyrank(int u , int v)
    {
        int ultu = findultparent(u);
        int ultv = findultparent(v);
        if(ultu == ultv) return;

        else if(rank[ultu] < rank[ultv])
        {
            parent[ultu] = ultv;
        }
        else if(rank[ultv] < rank[ultu])
        {
            parent[ultv] = ultu;
        }
        else
        {
            parent[ultv] = ultu;
            rank[ultu]++;
        }
    }
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        disjointset ds(n);
        for(auto edge: edges)
        {
            int u = edge[0];
            int v = edge[1];

            if(ds.findultparent(u) != ds.findultparent(v))
            {
                ds.unionbyrank(u,v);
            }
            else
            {
                return edge;
            }
        }

        return {};

        
    }
};