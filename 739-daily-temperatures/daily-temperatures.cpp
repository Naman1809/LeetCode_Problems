class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n= temperatures.size();
        stack<int> s;
        s.push(n-1);
        vector<int> v;
        v.push_back(0);
        for(int i=n-2;i>=0;i--){
            while(!s.empty()&&temperatures[s.top()]<=temperatures[i]){
                s.pop();
                
            }
            if(s.empty()){
                v.push_back(0);
                
            }
            else{
                v.push_back(s.top()-i);
            }
            s.push(i);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};