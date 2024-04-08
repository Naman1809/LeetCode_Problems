class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
         std::queue q(std::deque<int>(students.begin(), students.end()));
        int index=0;
        int c= 0;
        while(!q.empty()){
            int curr= q.front();
            q.pop();
            if(curr != sandwiches[index]) 
            { 
                c++;
                q.push(curr);
            }
            else 
            {
               c= 0;
            index++;
            }
            if(c== q.size()) 
                break;
        }
        return q.size();
    }
};