class Solution {
public:

void dfs(int node, stack<int>& st, vector<bool>& visited,vector<vector<int>>& adj)
{
    visited[node] = true;
    st.push(node);

    for(auto adjnode:adj[node])
    {
        if(!visited[adjnode])
        {
            dfs(adjnode,st,visited,adj);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        vector<vector<int>> adj(n+1);
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(isConnected[i][j] == 1 && i != j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        // we have constructed our adjacency list first
        int provinces = 0;
        stack<int> st;
        vector<bool> visited(n+1,false);
        for(int i = 0; i<n; i++)
        {
            if(!visited[i])
            {
                provinces++;
                dfs(i, st, visited,adj);

            }
        }

        return provinces;

        
    }
};