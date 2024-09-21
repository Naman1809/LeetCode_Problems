class Solution {
public:
    void helper(string &s, int n, vector<int>&ans){
        for(int i=0;i<=9;i++){
            string s1 = s + to_string(i);
            if(stoi(s1)<=n){
                ans.push_back(stoi(s1));
                helper(s1,n,ans);
            }
            else break;

        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int i=1;i<=9;i++){
            if(i<=n){
                ans.push_back(i);
                string s = to_string(i);
                helper(s,n,ans);
            }
        }
        return ans;
    }

};