class Solution {
public:

void dfs(int node, stack<int>& st, vector<int>& visited,vector<vector<int>>& adj)
{
    visited[node] = 1;
    st.push(node);

    for(auto adjnode: adj[node])
    {
        if(!visited[adjnode])
        {
            dfs(adjnode, st, visited, adj);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n =  isConnected.size();
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

        // wehave created the adjacency list
        vector<int> visited(n,0);
        stack<int> st;
        int count = 0;

        for(int i = 0;i < n; i++)
        {
            if(!visited[i])
            {
                count++;
                dfs(i,st,visited,adj);
            }
        }

        return count;        
    }
};