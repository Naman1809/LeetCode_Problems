class DisjointSet{
    public:
    vector<int>rank,size,parent;
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


    vector<vector<string>> accountsMerge(vector<vector<string>>& details) {
        int n= details.size();
        DisjointSet ds(n);
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<details[i].size();j++){
                string mail=details[i][j];
                if(mp.find(mail)==mp.end()){
                    mp[mail]=i;
                }else{
                    ds.unionByRank(i,mp[mail]);
                }
            }
        }
        vector<string>mergeMail[n];
        for(auto it:mp){
            string mail=it.first;
            int node = ds.findUpar(it.second);
            mergeMail[node].push_back(mail);
        }
          vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mergeMail[i].size()==0)continue;
            sort(mergeMail[i].begin(),mergeMail[i].end());
            vector<string>temp;
            temp.push_back(details[i][0]);
            for(auto it: mergeMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};