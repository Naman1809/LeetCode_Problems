class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        int n= colors.size();
        int ans=0;
        int j=0;
        for(int i=1;i<n;i++){
            if(colors[j]==colors[i]){
                if(time[i]<time[j]){
                    ans+=time[i];
                }
                else{
                    ans+=time[j];
                    j=i;
                }
            }else{
                j=i;
            }
        }
        return ans;
    }
};