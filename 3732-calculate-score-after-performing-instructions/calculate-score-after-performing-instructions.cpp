class Solution {
public:
    long long calculateScore(vector<string>& instructions,
                             vector<int>& values) {
        long long score = 0;
        int n = values.size();

        unordered_map<long long,int> mp;
        long long j = 0;
        while (j < n  && j >= 0) {
            if (mp.find(j) != mp.end())break;
            mp[j]++;
            if (instructions[j] == "add") {
                score += (values[j])*1LL;
                j++;
            } else if (instructions[j] == "jump") {
                j += (values[j])*1LL;
            }
        }
        return score;
    }
};