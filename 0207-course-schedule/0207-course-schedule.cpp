class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        int n = numCourses;
        vector<vector<int>> adj(n);
        for(auto it:prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }
        vector<int> indegree(n);
        queue<int> q;
        for(int i = 0; i<n; i++)
        {
            for(auto it: adj[i])
            {
                indegree[it]++;
                // we increase the indegree for the neighboring elements
            }
        }
        for(int i = 0; i<n; i++)
        {
            if(indegree[i] == 0)
            {
                // push all nodes with degree as 0 into the queue
                q.push(i);
            }
        }
        vector<int> toposort;
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            toposort.push_back(node);
            // we are adding the node into our toposort

            for(auto adjnode:adj[node])
            {
                indegree[adjnode]--;
                if(indegree[adjnode] == 0)
                {
                    q.push(adjnode);
                }
            }
        }
        if(toposort.size() == n)
        {
            // matlb hum sbhi elements ko topo sort kr paaye
            return true;
        }
        return false;
        
    }
};