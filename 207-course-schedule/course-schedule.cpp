class Solution {
public:
    bool isCycle(int i, vector<int>adj[],vector<int>&vis,vector<int>&cyc){
            vis[i]=1;
            cyc[i]=1;
            for(auto it:adj[i]){
                if(!vis[it]){
                    if(isCycle(it,adj,vis,cyc))return true;
                }
                else if(cyc[it]==1)return true;
            }
            cyc[i]=0;
            return false;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int>adj[n];
        for(auto it :prerequisites){
            adj[it[1]].push_back(it[0]);

        }
        vector<int>vis(n,0),cyc(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
            if(isCycle(i,adj,vis,cyc))return false;
        }
        }
        return true;
    }
};