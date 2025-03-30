class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        bool odd = k % 2;
        vector<double> res;
        multiset<int> left;
        multiset<int> right;
        int i = 0, j = 0;
        while (j < nums.size())
        {

            if (left.size() <= right.size()) {
                left.insert(nums[j]);
            } else {
                right.insert(nums[j]);
            }

            if (left.size() > 0 && right.size() > 0) {
                if (*left.rbegin() > *right.begin()) {
                    int leftmax = *left.rbegin();
                    int rightmax = *right.begin();
                    right.insert(leftmax);
                    left.insert(rightmax);
                    left.erase(left.find(leftmax));
                    right.erase(right.find(rightmax));
                }
            }

            if (j - i + 1 < k) {
                j++;
            } else {
                if (odd) {
                    res.push_back(*left.rbegin());
                } else {
                    cout<<*left.rbegin()<<" "<< *right.begin();
                    double x = (*left.rbegin()*1.0 + *right.begin()*1.0)/ 2.0;
                    res.push_back(x);
                }

                if (left.find(nums[i]) != left.end()) {
                    left.erase(left.find(nums[i]));
                } else {
                    right.erase(right.find(nums[i]));
                }

                i++;
                j++;
            }
        }
        return res;
    }
};