class Solution {
public:
    int findCenter(vector<vector<int>>& e) {
//         int ans=-1;
//         int q=INT_MIN;
//         int n=edges.size();
// unordered_map<int,int>v;
//         for(int i=0;i<edges.size();i++){
    //        v[edges[i][0]]++;
    //         v[edges[i][1]]++;
    //         if( v[edges[i][0]]>q){
    //             q= v[edges[i][0]];
    //             ans= edges[i][0];
    //         }
    //         else if( v[edges[i][1]]>q){
    //             q= v[edges[i][1]];
    //             ans= edges[i][1];
    //         }
    //     }
    //     // int q=0;
    //     // for(auto:v){
    //     //     if(v[i]>q){
    //     //         q=v[i];
    //     //         ans=i;
    //     //     }
    //     // }
    // return ans;
    // }
             return e[0][0] == e[1][0] || e[0][0] == e[1][1] ? e[0][0] : e[0][1];
    }  
};