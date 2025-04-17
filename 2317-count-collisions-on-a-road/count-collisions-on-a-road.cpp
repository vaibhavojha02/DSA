class Solution {
public:
    int countCollisions(string s) {
        bool collision = false;
        int right = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'R') {
                if (collision == true) {
                    collision = false;
                }
                right++;

            } else if (s[i] == 'L') {
                if (right > 0) {
                    collision = true;
                    ans += (right+1);
                } else if (collision) {
                    ans++;
                }
                right = 0;
            } else {
                if (right > 0) {
                    ans += right;
                    right = 0;
                }
                collision = true;
            }
        }
        return ans;
    }
};