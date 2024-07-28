class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> stu;
        int n=students.size();
        for(int i=0;i<n;i++){
            stu.push(students[i]);
        }
        int pos=0;
        int curr=0;
        while(!stu.empty() && curr<=stu.size()){
            if(stu.front()==sandwiches[pos]){
                stu.pop();
                pos++;
                curr=0;
            }
            else{
                stu.push(stu.front());
                stu.pop();
            }
            curr++;
        }
        return stu.size();
        
        
    }
};