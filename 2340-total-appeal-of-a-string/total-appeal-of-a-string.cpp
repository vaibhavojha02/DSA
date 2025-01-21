class Solution {
public:
    long long appealSum(string s) {
        long long int n = s.size();
        long long int total = (n * (n + 1)) / 2;
        vector<long long>substring(26,0LL);
        for (int i = 0; i < 26; i++) {
            char ch = 'a' + i;
            long long int sum = 0LL;
            long long int cnt = 0LL;
            for (int j = 0; j < n; j++) {
                if (s[j] != ch) {
                    cnt++;
                } else {
                    sum += (cnt * (cnt + 1)) / 2;
                    cnt = 0LL;
                }
            }
            if (cnt != 0)
                sum += (cnt * (cnt + 1)) / 2;
            substring[i] = (total - sum);
        }
        long long result = 0LL;

        for (int i = 0; i < 26; i++)result += substring[i];
        return result;
    }
};