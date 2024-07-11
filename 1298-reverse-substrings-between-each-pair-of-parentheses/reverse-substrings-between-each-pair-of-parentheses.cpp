class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> s1;
        for(int i=0;i<s.length();i++){
            if(s[i]!=')'){
                s1.push(s[i]);
            }
            else{
                stack<char> s2,s3;
                while(!s1.empty()&&s1.top()!='('){
                    s2.push(s1.top());
                    s1.pop();
                }
                while(!s2.empty()){
                    s3.push(s2.top());
                    s2.pop();
                }
                s1.pop();
                while(!s3.empty()){
                    s1.push(s3.top());
                    s3.pop();
                }
               
            }
        }
        string s4;
        while(!s1.empty()){
            s4.push_back(s1.top());
            s1.pop();
        }
        reverse(s4.begin(),s4.end());
        return s4;
    }
};