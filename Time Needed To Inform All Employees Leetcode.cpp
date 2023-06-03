class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++)
        {
            if(manager[i] != -1)
            {
                adj[manager[i]].push_back(i);
            }
        }
        queue<pair<int, int>> q;
        q.push({headID, informTime[headID]});
        vis[headID] = 1;
        int ans = INT_MIN;
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int node = it.first;
            int dis = it.second;
            ans = max(ans, dis);
            for(auto it : adj[node])
            {
                if(!vis[it])
                {
                    vis[it] = 1;
                    q.push({it, dis + informTime[it]});
                }
            }
        }
        return ans;
    }
};
