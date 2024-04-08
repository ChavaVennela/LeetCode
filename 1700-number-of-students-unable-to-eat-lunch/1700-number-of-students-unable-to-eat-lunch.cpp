class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int studentcount=students.size(), j=0, ans=0, i=0;
        while(i<sandwiches.size() && j<studentcount){
            if(students[j]==sandwiches[i]){
                i++;
                ans++;
                studentcount=students.size();
            }
            else{
                students.push_back(students[j]);
            }
            j++;
        }
        return sandwiches.size()-ans;
    }
};