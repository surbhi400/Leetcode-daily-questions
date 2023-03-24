class Solution {
public:
    void dfs(int node, vector<vector<pair<int,int>>>&adj, vector<int>&vis, int &ans){
      vis[node] = 1;
      for(auto it: adj[node]){
        if(!vis[it.first]){
          bool isedgeOutward = (it.second==1);
          if(isedgeOutward)ans++;
          dfs(it.first,adj,vis,ans);
        }
        else continue;
      }

    }
    int minReorder(int n, vector<vector<int>>& connections) {
       vector<vector<pair<int,int>>>adj(n);
       for(auto it: connections){
         adj[it[0]].push_back({it[1],1}); //for real direction
         adj[it[1]].push_back({it[0],-1}); //for opposite direction
       } 
       int ans = 0;
       vector<int>vis(n,0);
       dfs(0,adj,vis,ans);
       return ans;
        
    }
};
