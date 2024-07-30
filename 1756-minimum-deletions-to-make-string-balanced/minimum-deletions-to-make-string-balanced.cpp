class Solution {
public:
    int minimumDeletions(string s) {/*
stack<char> st;
        int d=0;
    for(int i=s.size()-1;i>=0;i--){
        char c=s[i];
        if(!st.empty()&&st.top()<c){
            d++;
            st.pop();
        }
        else{
            st.push(s[i]);
        }
    }
        return d;
    */
        int c=0,d=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'&&d>0){
                c++;
                d--;
            }
            else if(s[i]=='b'){
                d++;
            }
        }
        return c;
    
    }
};