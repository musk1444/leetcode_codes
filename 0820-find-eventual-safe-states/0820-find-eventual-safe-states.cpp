class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int v = graph.size();
        vector<vector<int>> adjrev(v);

        for(int i = 0; i<v; i++)
        {
            for(auto adjnode:graph[i])
            {
                adjrev[adjnode].push_back(i);
            }
        }
        // we have reversed the graph
        
        vector<int> indegree(v,0);
        for(int i = 0; i<v; i++)
        {
            for(auto adjnode: adjrev[i])
            {
                indegree[adjnode]++;
            }
        }
        // we have stored the indegrees of all the node
        queue<int> q;
        vector<int> safenodes;
        for(int i = 0; i<v; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // now we will process every node in the queue
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            safenodes.push_back(node);

            for(auto adjnode: adjrev[node])
            {
                indegree[adjnode]--;
                if(indegree[adjnode] == 0)
                {
                    q.push(adjnode);
                }
            }
        }

        sort(begin(safenodes), end(safenodes));

        return safenodes;
    }
};