class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int>st;
        for(auto it:points){
            st.insert(it[0]);
        }
        int maxDiff=0;
        int prev=INT_MIN;
        for(auto it :st){
            if(prev!=INT_MIN){
                maxDiff=max(maxDiff,it-prev);
            }
            prev=it;
        }
        return maxDiff;
    }
};