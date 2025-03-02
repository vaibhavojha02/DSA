class Solution {
public:
    vector<char> arr = {'A', 'C', 'G', 'T'};
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());
        unordered_set<string> visited;
        visited.insert(start);
        queue<string> q;
        q.push(start);
        int level = 0;
        while (!q.empty()) {

            int n = q.size();
            while (n--) {
                string temp = q.front();
                q.pop();
                if (temp == end)
                    return level;

                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 8; j++) {
                        string neigbour = temp;
                        if (neigbour[j] != arr[i]) {

                            neigbour[j] = arr[i];
                            if (visited.find(neigbour) == visited.end() &&
                                st.find(neigbour) != st.end()) {
                                q.push(neigbour);
                                visited.insert(neigbour);
                            }
                            
                        }
                    }
                }
            }
                level++;
        }
        return -1;
    }
};