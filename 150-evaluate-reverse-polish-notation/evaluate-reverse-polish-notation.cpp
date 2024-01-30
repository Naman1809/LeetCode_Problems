
   class Solution {
public:
    int evalRPN(vector<string>& tokens) {
   stack<long long>st;
   for(int i=0;i<tokens.size();i++){
       if(tokens[i]=="+"){
           long long x1=st.top();
           st.pop();
           long long x2 = st.top();
           st.pop();
           st.push(x1+x2);
       }
        else if(tokens[i]=="-"){
           long long x1=st.top();
           st.pop();
           long long x2 = st.top();
           st.pop();
           st.push(x2-x1);
       }
       else if(tokens[i]=="*"){
           long long x1=st.top();
           st.pop();
           long long x2 = st.top();
           st.pop();
           st.push(x1*x2);
       }
       else if(tokens[i]=="/"){
           long long x1=st.top();
           st.pop();
           long long x2 = st.top();
           st.pop();
           st.push(x2/x1);
       }
       else{
st.push(stoi(tokens[i]));
       }
   }
return st.top();
    }
};