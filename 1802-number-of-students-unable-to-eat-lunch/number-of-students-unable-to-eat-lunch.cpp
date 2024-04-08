class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int sz = students.size();
        
        queue<int> q;
        int c = 0, st = 0;
        for (auto x : students) q.push(x);
        while (q.size()) {
            ++c;
            if (c > q.size()) break;
            if (q.front() == sandwiches[st]) {
                q.pop();
                ++st;
                c = 0;
            }
            else {
                q.pop();
                q.push(1-sandwiches[st]);
            }
        }
        return q.size();
    }
};