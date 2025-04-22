class Solution {
public:
typedef pair<int,int> P;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);
        
        for(auto flight: flights)
        {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        int stops = 0;
        queue<P> q;
        // we are storing {cost,node}
        vector<int> distance(n, INT_MAX);
        distance[src] = 0;
        q.push({src,0});

        while(!q.empty() && stops <= k)
        {
            int size = q.size();
            vector<int> temp = distance;

            for(int i = 0; i<size;i++)
            {
                auto it = q.front();
                q.pop();

                int node = it.first;
                int cost = it.second;

                for(auto val:adj[node])
                {
                    int adjnode = val.first;
                    int price = val.second;

                    if(price + cost  < temp[adjnode])
                    {
                        temp[adjnode] = price+cost;
                        q.push({adjnode, temp[adjnode]});
                    }
                }
            }
            distance = temp;
            stops++;
        }

        return distance[dst] == INT_MAX ? -1: distance[dst];
        
    }
};