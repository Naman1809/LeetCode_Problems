class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int wt=flights[i][2];
            adj[u].push_back({v,wt});

        }
     queue<pair<int,pair<int,int>>>q;
     vector<int>dist(n,1e9);
     q.push({0,{src,0}});
     dist[src]=0;
     while(!q.empty()){
         int stop=q.front().first;
         int node=q.front().second.first;
         int price=q.front().second.second;
         q.pop();
         if(stop>k)continue;
         for(auto it: adj[node]){
             int adjN=it.first;
             int Nprice=it.second;
             if(dist[adjN]>price+Nprice&&stop<=k){
                 dist[adjN]=price+Nprice;
                 q.push({stop+1,{adjN,dist[adjN]}});
             }
         }
         
              }
              return dist[dst]==1e9?-1:dist[dst];

    }
};