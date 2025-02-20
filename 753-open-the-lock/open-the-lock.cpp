class Solution {
public:
    vector<char> nums = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        if(dead.find("0000")!=dead.end()){
            return -1;
        }
        visited.insert("0000");
        queue<string> q;
        q.push("0000");
        int level = 0;
        while (!q.empty()) {
            int n = q.size();
            while (n--)
            {
                string curr = q.front();
                q.pop();
                if (curr == target)return level;
                for (int i = 0; i < 4; i++) {
                    int idx = curr[i] - '0';
                    // 2 strings ban skti hai yahan pe
                    // ek forward move krne pe ek backward move krne pe
                    string forward = curr;
                    forward[i] = nums[(idx+1)%10];
                    string backward = curr;
                    backward[i] = nums[((idx-1)+10) % 10];
                    if (dead.find(forward) == dead.end() &&
                        visited.find(forward) == visited.end()) {
                        q.push(forward);
                        visited.insert(forward);
                    }
                    if (dead.find(backward) == dead.end() &&
                        visited.find(backward) == visited.end()) {
                        q.push(backward);
                        visited.insert(backward);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};