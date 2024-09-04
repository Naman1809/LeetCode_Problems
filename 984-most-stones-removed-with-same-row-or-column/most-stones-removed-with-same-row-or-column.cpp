/*
class Solution {
public:
    int dfs(vector<vector<int>>&stones,int index,vector<bool>&visited,int&n){
        visited[index]=true;
        int result=0;
        for(int i=0;i<n;i++)
            if(!visited[i]&&(stones[i][0]==stones[index][0]||stones[i][1]==stones[index][1]))
                result +=(dfs(stones,i,visited,n) + 1);
        return result;
    }
    int removeStones(vector<vector<int>>&stones) {
        int n = stones.size();
        vector<bool>visited(n,0);
        int result=0;
        for(int i=0;i<n;i++){
            if(visited[i]){continue;}
            result+=dfs(stones,i,visited,n);
        }
        return result;
    }
};*/
class DisjointSet{
  public: 
  vector<int>rank,parent,size;
  DisjointSet(int n){
      rank.resize(n+1,0);
      parent.resize(n+1);
      size.resize(n+1,1);
      for(int i=0;i<=n;i++){
         parent[i]=i; 
      }
  }
  int findUpar(int node){
      if(node==parent[node])return node;
      return parent[node]=findUpar(parent[node]);
  }
  
  void unionByRank(int u, int v){
      int ulp_u=findUpar(u);
      int ulp_v=findUpar(v);
      if(ulp_u==ulp_v)return;
      if(rank[ulp_u]<rank[ulp_v]){
          parent[ulp_u]=ulp_v;
      }
      else if(rank[ulp_u]>rank[ulp_v]){
          parent[ulp_v]=ulp_u;
      }
      else{
           parent[ulp_u]=ulp_v;
           rank[ulp_v]++;
      }
  }
  
};
class Solution {
public:
int removeStones(vector<vector<int>>&stones) {
        int n = stones.size();
           int maxRow=0;
        int maxCol=0;
        for(auto it:stones){
            maxRow=max(maxRow,it[0]);
            maxCol=max(maxCol,it[1]);
        }
        DisjointSet ds(maxRow+maxCol+1);
        unordered_map<int,int>stoneNodes;
        for(auto it: stones){
            int nodeRow=it[0];
            int nodeCol=it[1]+maxRow+1;
            ds.unionByRank(nodeRow,nodeCol);
            stoneNodes[nodeRow]=1;
            stoneNodes[nodeCol]=1;
        }
        
        int cnt=0;
        for(auto it: stoneNodes){
            if(ds.findUpar(it.first)==it.first)cnt++;
        }
        return n-cnt;
}



};