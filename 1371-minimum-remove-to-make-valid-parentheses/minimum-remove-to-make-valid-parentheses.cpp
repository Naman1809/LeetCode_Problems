class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.length();
        int count=0; 
        for(int i=0;i<n;++i){
            if(s[i]=='('){ 
                ++count;
            }
            else if(s[i]==')'){ 
                if(count==0){  
                    s[i]='#';
                }
                else{
                   
                    --count;
                }
            }
        }
        
       
        count=0;
        for(int i=n-1;i>=0;--i){
            if(s[i]==')'){ // for close bracket
                ++count;
            }
            else if(s[i]=='('){ // for open bracket
                if(count==0){ 
                    s[i]='#';
                }
                else{
                    --count;
                }
            }
        }
        
s.erase(remove(s.begin(),s.end(),'#'),s.end());
        return s;
    }
};