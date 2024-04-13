class Solution {
public:
     int largest(vector<int> &arr){
       stack<int>s;
       long long tp;
       long long curr;
       long long res=0;
       int n=arr.size();
       for(int i=0;i<n;i++){
           while(s.empty()==false && arr[s.top()]>=arr[i]){
               tp=s.top();
               s.pop();
               curr=arr[tp]*(s.empty()? i : i-s.top()-1);
               res=max(res,curr);
           }
           s.push(i);
       }
       while(s.empty()==false){
               tp=s.top();
               s.pop();
               curr=arr[tp]*(s.empty()? n : n-s.top()-1);
               res=max(res,curr);
           }
           return res;
  }
    int maximalRectangle(vector<vector<char>>& M) {
        vector<int> v;
        
        int n=M.size();
          if(n==0){
            return 0;
        }
        int m=M[0].size();
        if(m==0){
            return 0;
        }
      
        for(int i=0;i<m;i++){
            v.push_back(M[0][i]-48);
        }
        int c=largest(v);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]=='1'){
                    v[j]=v[j]+1;
                }
                else{
                    v[j]=0;
                }
            }
            c=max(c,largest(v));
        }
        return c; 
    }
};